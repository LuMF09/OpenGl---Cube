#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QAbstractButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog), set1({0.00,0.00,0.00,0.00,0.00,0.00,0.00})
{
    ui->setupUi(this);
    //set a fixed size to the window
    this->setFixedSize(this->width(),this->height());
    //remove the "?" tab of the window
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Dialog::~Dialog()
{
    delete ui;
}

QDialogButtonBox * const Dialog::getButton()
{
    return ui->buttonBox;
}

setOfValues const & Dialog::getStruct()
{
    return set1;
}

//When the user click on the OK button, values entered are stored in the set
void Dialog::on_buttonBox_accepted()
{
    set1.xB = ui->doubleSpinBox_x_b->value();
    set1.yB = ui->doubleSpinBox_y_b->value();
    set1.zB = ui->doubleSpinBox_z_b->value();

    set1.xD = ui->doubleSpinBox_x_d->value();
    set1.yD = ui->doubleSpinBox_y_d->value();
    set1.zD = ui->doubleSpinBox_z_d->value();

    set1.alpha = ui->doubleSpinBox_value_alpha->value();
}

//When the user click on the CANCEL button, values does not change
void Dialog::on_buttonBox_rejected()
{
    ui->doubleSpinBox_x_b->setValue(set1.xB);
    ui->doubleSpinBox_y_b->setValue(set1.yB);
    ui->doubleSpinBox_z_b->setValue(set1.zB);

    ui->doubleSpinBox_x_d->setValue(set1.xD);
    ui->doubleSpinBox_y_d->setValue(set1.yD);
    ui->doubleSpinBox_z_d->setValue(set1.zD);

    ui->doubleSpinBox_value_alpha->setValue(set1.alpha);
}

//When the user click on the RESET button, values are re-initialised at 0
void Dialog::on_pushButton_clicked()
{
    ui->doubleSpinBox_x_b->setValue(0.00);
    ui->doubleSpinBox_y_b->setValue(0.00);
    ui->doubleSpinBox_z_b->setValue(0.00);

    ui->doubleSpinBox_x_d->setValue(0.00);
    ui->doubleSpinBox_y_d->setValue(0.00);
    ui->doubleSpinBox_z_d->setValue(0.00);

    ui->doubleSpinBox_value_alpha->setValue(0.00);
}
