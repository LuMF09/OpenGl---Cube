#ifndef DIALOGEYES_H
#define DIALOGEYES_H
/*!
* \file dialogeyes.h
* \brief Graphical user interface when the user set parameters of the camera
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class DialogEyes;
}

/*! \struct SetOfView dialogeyes.h "Parameters of the GUI of the camera" */
struct setOfView{
    double eyex,eyey,eyez,directx, directy, directz;
};

/*! \class DialogEyes
* \brief Set the structure and the links between objects when parameters of the view are entered.
*/
class DialogEyes : public QDialog
{
    Q_OBJECT

public:
    /*!
    *  \brief Constructor of the DialogEyes
    *
    *  \param parent: the global widget
    */
    explicit DialogEyes(QWidget *parent = 0);
    /*!
    *  \brief Default destructor of the DialogEyes
    */
    ~DialogEyes();

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
    setOfView const &getStruct();

private slots:
    void on_buttonBox_accepted();/*!< Slot when we push the accept button  */

    void on_buttonBox_rejected();/*!< Slot when we push the rejected button  */

    void on_pushButton_reset_clicked();/*!< Slot when we push the reset button  */

private:
    Ui::DialogEyes *ui;/*!< GUI  */
    setOfView param;/*!< All parameters entered  */
};

#endif // DIALOGEYES_H
