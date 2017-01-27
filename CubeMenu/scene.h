#ifndef SCENE_H
#define SCENE_H
/*!
* \file scene.h
* \brief Scene of the project
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include "C:/glm/glm/glm.hpp"
#include "dialogeyes.h"
#include "dialog.h"
using glm::vec3;

class Scene
{
public:
    /**
      Load textures, initialize shaders, etc.
      */
    virtual void initScene() = 0;

    /**
      This is called prior to every frame.  Use this
      to update your animation.
      */
    virtual void update( float t ) = 0;

    /**
      Draw your scene.
      */
    virtual void render() = 0;

    /**
      Called when screen is resized
      */
    virtual void resize(int, int) = 0;

    virtual void setAngleAxis(float angle, vec3 axis) = 0;
    virtual void writeLine(glm::vec3 p1, glm::vec3 p2) = 0;
    virtual void CreateVBOLine()=0;

    virtual void rotateModel(setOfValues param)=0;

    virtual void updateEyeCameraOnCube(std::vector<double> center)=0;

    virtual void updateEyeCameraUser(setOfView param)=0;

    virtual void restoreCamDefault()=0;

    virtual std::vector<double> const  &getCenter()=0;
};

#endif // SCENE_H
