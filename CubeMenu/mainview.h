#ifndef MAINVIEW_H
#define MAINVIEW_H
/*!
* \file mainview.h
* \brief Main view, link choices made by the user with actions inside the code
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include "C:/glew-1.13.0/include/GL/glew.h"
#include "C:/glm/glm/glm.hpp"
#include <QGLWidget>
#include <QTimer>
using glm::vec3;
#include "scene.h"
#include "dialog.h"
#include "dialogeyes.h"

/*! \class MainView
* \brief It is the main view, it will recover data and transmit them.
*/
class MainView : public QGLWidget
{
    Q_OBJECT

private:
    QTimer *timer;
    Scene *scene;
    float angle;
    vec3 axis;

public:
    /*!
    *  \brief Constructor of MainView
    *
    *  \param format: Specifies the display format of an OpenGL rendering context.
    *  \param widget: the global widget
    */
    MainView( const QGLFormat & format, QWidget *parent = 0 );

    /*!
    *  \brief Update the models of the line and the cube
    *
    *  \param p1: point 1 of the line
    *  \param p1: point 1 of the line
    */
    void updateCube(glm::vec3 p1, glm::vec3 p2);

    /*!
    *  \brief Do the transformations (translations and rotation) on the models.
    *
    *  \param param: set of values from the user
    */
    void rotateMatrix(setOfValues param);

    /*!
    *  \brief Update the camera
    *
    *  \param param: set of values of the view from the user
    */
    void updateCamera(setOfView param);

    /*!
    *  \brief Restore the default parameters of the cube and the view
    */
    void restoreCamera();

protected:
    void initializeGL();/*!< Initialize  */
    void paintGL();/*!< Paint   */
    void resizeGL(int w, int h);/*!< Resize */

public slots:
    void timerUpdate();/*!< Slot wich update the timer */
    void toggleAnimation();/*!< Slot which deals with animations */
    void takeScreenShot();/*!< Slot which allow us to do a screenshot  */
};

#endif // MAINVIEW_H
