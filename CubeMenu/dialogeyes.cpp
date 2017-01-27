#include "dialogeyes.h"
#include "ui_dialogeyes.h"

DialogEyes::DialogEyes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEyes),param({0.00,0.00,0.00,0.00,0.00,0.00})
{
    ui->setupUi(this);
    //set a fixed size to the window
    this->setFixedSize(this->width(),this->height());
    //remove the "?" tab of the window
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

DialogEyes::~DialogEyes()
{
    delete ui;
}

QDialogButtonBox * const DialogEyes::getButton()
{
    return ui->buttonBox;
}

const setOfView &DialogEyes::getStruct()
{
    return param;
}

//When the user click on the OK button, values entered are stored in the set
void DialogEyes::on_buttonBox_accepted()
{
    param.eyex=ui->doubleSpinBox_eyex->value();
    param.eyey=ui->doubleSpinBox_eyey->value();
    param.eyez=ui->doubleSpinBox_eyez->value();

    param.directx=ui->doubleSpinBox_dx->value();
    param.directy=ui->doubleSpinBox_dy->value();
    param.directz=ui->doubleSpinBox_dz->value();

}

//When the user click on the CANCEL button, values does not change
void DialogEyes::on_buttonBox_rejected()
{
    ui->doubleSpinBox_eyex->setValue(param.eyex);
    ui->doubleSpinBox_eyey->setValue(param.eyey);
    ui->doubleSpinBox_eyez->setValue(param.eyez);

    ui->doubleSpinBox_dx->setValue(param.directx);
    ui->doubleSpinBox_dy->setValue(param.directy);
    ui->doubleSpinBox_dz->setValue(param.directz);
}

//When the user click on the RESET button, values are re-initialised at 0
void DialogEyes::on_pushButton_reset_clicked()
{
    ui->doubleSpinBox_eyex->setValue(0);
    ui->doubleSpinBox_eyey->setValue(0);
    ui->doubleSpinBox_eyez->setValue(0);

    ui->doubleSpinBox_dx->setValue(0);
    ui->doubleSpinBox_dy->setValue(0);
    ui->doubleSpinBox_dz->setValue(0);
}
