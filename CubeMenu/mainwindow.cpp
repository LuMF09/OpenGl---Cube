#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <iostream>
#include <QMessageBox>
//#include "C:/glm/glm/gtx/transform2.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialogParam(this),dialogEyes(this)
{
    ui->setupUi(this);
    connect(dialogParam.getButton(),SIGNAL(accepted()), this, SLOT(onParamChosen()));
    connect(dialogEyes.getButton(), SIGNAL(accepted()), this, SLOT(onViewChosen()));
}

void MainWindow::setView(MainView *view)
{
    this->view = view;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//When we click on the "Line rotation" tab and "Choose parameters" option
void MainWindow::on_actionChoose_Parameters_triggered()
{    
    dialogParam.show();//show the dialog
    dialogParam.exec();
}

//When we click on OK in the line parameters dialog
void MainWindow::onParamChosen()
{
    setOfValues paramLine(dialogParam.getStruct());

    //If no parameters are entered
    if(abs(paramLine.xD)+abs(paramLine.yD)+abs(paramLine.zD)==0)
    {
         QMessageBox::information(this, "No values for the d coefficient of the line.","Please choose at least one parameter for d!");
    }
    else
    {
    //We calculate the line thanks to 2 points and send thel to the graphics card
    double normD=std::sqrt(paramLine.xD*paramLine.xD+paramLine.yD*paramLine.yD+paramLine.zD*paramLine.zD);

    glm::vec3 vectorD_Normalized(paramLine.xD/normD,paramLine.yD/normD,paramLine.zD/normD);

    glm::vec3 point1(paramLine.xB+10*vectorD_Normalized[0],paramLine.yB+10*vectorD_Normalized[1],paramLine.zB+10*vectorD_Normalized[2]);
    glm::vec3 point2(paramLine.xB-10*vectorD_Normalized[0],paramLine.yB-10*vectorD_Normalized[1],paramLine.zB-10*vectorD_Normalized[2]);

    view->rotateMatrix(paramLine);
    view->updateCube(point1, point2);

    }
}

//When we click on the "View Position" tab and "Choose parameters of the camera" option
void MainWindow::on_actionChoose_data_triggered()
{
    dialogEyes.show();//show the dialog
    dialogEyes.exec();
}
 //When we click on ok in the camera parameters dialog
void MainWindow::onViewChosen()
{
    setOfView paramCamera(dialogEyes.getStruct());
    //If no parameters are entered
    if(abs(paramCamera.eyex)+abs(paramCamera.eyey)+abs(paramCamera.eyez)+abs(paramCamera.directx)+abs(paramCamera.directy)+abs(paramCamera.directz)==0)
    {
         QMessageBox::information(this, "No values entered.","Please choose at least one parameter for the view!");
    }else
    {
        //change the view
       view->updateCamera(paramCamera);
    }
}

//When we click on the "Default Position" tab and "Restore default parameters of the camera " option
void MainWindow::on_actionRestore_default_parameters_of_the_camera_triggered()
{
    view->restoreCamera();

}

//When we click on the "Information" tab and "Show Information about the simulation" option
void MainWindow::on_actionShow_Informations_about_the_simulation_triggered()
{
    QMessageBox::information(this,"Information","- Line rotation's tab allows you to choose the parameters of the line.\n \n"
                                                 "- View position's tab allows you to choose the parameters of the camera.\n \n"
                                                 "- Default position's tab allows you to display again the initial position of the cube with the default camera position.\n \n"
                                                 "\n"
                                                 "Please note the following functionment:\n"
                                                 "- If you do not choose any parameters of the camera or restore the default parameters, when you will perform a rotation or display a new line, the camera will be set on the center of the cube with a different eye.\n \n"
                                                 "- If you choose the parameters, when you will perform a new rotation or display a new line, the camera will be set with your parameters.\n"
                                                 "\n"
                                                 "A little precision concerning the view: \n"
                                                 "- When you choose coordinates of the direction, be careful. You choose the vector of direction and not the point to look.\n"
                                                 " It is not intuitive to use this to see the functionment but it is the way asked in the assignment.");
}
