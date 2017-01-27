#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*!
* \file mainwindow.h
* \brief Articulate the differents actions (bouton pushed or tab triggered)to send them to the mainview
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include <QMainWindow>
#include "mainview.h"
#include "dialog.h"
#include "dialogeyes.h"

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
* \brief It is the main window, where the user can choose parameters.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    *  \brief Constructor of MainWindow
    *
    *  \param parent: the global widget
    */
    explicit MainWindow(QWidget *parent = 0);

    /*!
    *  \brief Set the Mainview of the project
    *
    *  \param view: Mainview
    */
    void setView(MainView* view);

    /*!
    *  \brief Default destructor of MainWindow
    */
    ~MainWindow();

private slots:

    void on_actionChoose_Parameters_triggered();/*!< Slot when we trigger the tab to choose parameters of the line*/

    void onParamChosen();/*!< Slot when we choose to open the window to choose parameters of the line */

    void on_actionChoose_data_triggered();/*!< Slot when we trigger the tab to choose parameters of the camera */

    void onViewChosen();/*!< Slot when we choose to open the window to choose parameters of the camera */

    void on_actionRestore_default_parameters_of_the_camera_triggered();/*!< Slot when we trigger the tab to restore defaults parameters */

    void on_actionShow_Informations_about_the_simulation_triggered();/*!< Slot when we trigger the tab to have information */

private:
    Ui::MainWindow *ui;/*!< Main GUI */
    MainView* view;/*!< Mainview */
    Dialog dialogParam;/*!< window of line parameters */
    DialogEyes dialogEyes;/*!< window of the camera parameters */
};

#endif // MAINWINDOW_H
