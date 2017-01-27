#ifndef DIALOG_H
#define DIALOG_H
/*!
* \file dialog.h
* \brief Graphical user interface when the user set parameters of the line and of the angle of rotation
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class Dialog;
}

/*! \struct SetOfValues dialog.h "Parameters of the GUI of the line" */
struct setOfValues{
    double xB,yB,zB,xD,yD,zD,alpha;
};


/*! \class Dialog
* \brief Set the structure and the links between objects when parameters of the line are entered.
*/
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /*!
    *  \brief Constructor of the Dialog
    *
    *  \param parent: the global widget
    */
    explicit Dialog(QWidget *parent = 0);
    /*!
    *  \brief Default destructor of the Dialog
    */
    ~Dialog();

    /*!
    *  \brief Const Accessor method wich provide the button in order to connect it
    *
    *  \return The button
    */
    QDialogButtonBox * const getButton();

    /*!
    *  \brief Const Accessor method wich provide the structure
    *
    *  \return The structure which belong to the window
    */
    setOfValues const & getStruct();

private slots:
    void on_buttonBox_accepted(); /*!< Slot when we push the accept button  */

    void on_buttonBox_rejected(); /*!< Slot when we push the rejected button  */

    void on_pushButton_clicked(); /*!< Slot when we push the reset button  */

private:
    Ui::Dialog *ui; /*!< GUI  */
    setOfValues set1; /*!< All parameters entered  */
};

#endif // DIALOG_H
