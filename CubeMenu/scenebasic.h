#ifndef SCENEBASIC_H
#define SCENEBASIC_H
/*!
* \file scenebasic.h
* \brief Inherited from scene,do all the transformations on every objects of the scene
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include "scene.h"
#include "C:/glew-1.13.0/include/GL/glew.h"
#include "glslprogram.h"
#include "C:/glm/glm/glm.hpp"
using glm::mat4;

/*! \class SceneBasic
* \brief It is the scene of the project. Where all transformations, actions are done.
*/
class SceneBasic : public Scene
{
private:
    int width, height;/*!< width and height of the scene */
    GLuint vboHandles[2];/*!< Vbos cube */
    GLuint vaoHandle;/*!< Vao cube */

    GLuint vboLine[2];/*!< Vbos line */
    GLuint vaoLine;/*!< Vao line */

    float angle;/*!< angle */
    vec3 axis;/*!< axes */
    mat4 rotationMatrix;/*!< rotation of the matrix */
    GLSLProgram prog;/*!< cube program */
    GLSLProgram progLine;/*!< line program */

    mat4 model;/*!< Model of the cube */
    mat4 modelInit;/*!< Initial model */
    mat4 modelLine;/*!< Model of the line */
    mat4 view;/*!< view */
    mat4 viewInit;/*!< Initial view */
    mat4 projection;/*!< projection */
    std::vector<double> center;/*!< Coordinates of the enter of the cube */
    bool noParam;/*!< Check if some parameters are entered by the user */
    bool firstLine;/*!< Check if a line had already been created */

    /*!
    *  \brief Read data from a ".dat"
    *
    *  \param fname: name of the file
    */
    void readData(const char* fname);

    /*!
    *  \brief Create vbos
    */
    void CreateVBO();

    /*!
    *  \brief Write the line in the graphic card
    *
    *  \param p1: point 1 of the line
    *  \param p2: point 2 of the line
    */
    void writeLine(glm::vec3 p1, glm::vec3 p2);


    float positionData[108];/*!< table with positions for the cube */
    float colorData[108];/*!< table with colors for the cube */   //6faces*6sommets*3 coordinates

    float positionDataLine[9];/*!< table with positions for the line */
    float colorDataLine[9];/*!< table with colors for the line */

public:
    /*!
    *  \brief Default constructor of SceneBasic
    */
    SceneBasic();

    //virtual functions inherited from scene

    /*!
    *  \brief Const Accessor inherited method wich provide the center of the cube
    *
    *  \return The center of the cube
    */
    std::vector<double> const &getCenter();

    /*!
    *  \brief Inherited function from scene. Create vbos for the line.
    */
    void CreateVBOLine();

    /*!
    *  \brief Inherited function from scene. Initialize the scene.
    */
    void initScene();

    /*!
    *  \brief Inherited function from scene. Update the scene.
    */
    void render();

    /*!
    *  \brief Resize the window
    */
    void resize(int, int);

    /*!
    *  \brief Update the angle
    *
    *  \param t: t*2*Pi*angle
    */
    void update( float t );

    /*!
    *  \brief Set the angle of the axis
    *
    *  \param ang: angle
    *  \param ax: axis
    */
    void setAngleAxis(float ang, vec3 ax);

    void printActiveUniforms(GLuint programHandle);
    void printActiveAttribs(GLuint programHandle);

    /*!
    *  \brief Do tranformations on the models
    *
    *  \param param: set of values of the user when he choses the parameters of the line
    */
    void rotateModel(setOfValues param);

    /*!
    *  \brief Update the camera
    *
    *  \param center: center of the cube
    */
    void updateEyeCameraOnCube(std::vector<double> center);

    /*!
    *  \brief Set the camera with the parameters chosen by the user
    *
    *  \param param: set of values of the user when he choses the parameters of the camera
    */
    void updateEyeCameraUser(setOfView param);

    /*!
    *  \brief Inherited function from scene. Restore the default parameters of the view and the cube.
    */
    void restoreCamDefault();
};

#endif // SCENEBASIC_H
