#include "scenebasic.h"
#include <cstdio>
#include <cstdlib>
#include<cmath>
#include <iostream>
#include <fstream>
using std::ifstream;
#include <sstream>
using std::ostringstream;
#include "glutils.h"
#include "C:/glm/glm/gtc/matrix_transform.hpp"
#include "C:/glm/glm/gtx/transform2.hpp"
#include "C:/glm/glm/gtc/matrix_inverse.hpp"

const float PI = 4.0*atan(1.0);

SceneBasic::SceneBasic() : angle(0.0), axis(0.0,1.0,0.0),center(3), noParam(true),firstLine(true)
{
    positionData[0]={0};
    colorData[0]={0};
    positionDataLine[0]={0};
    colorDataLine[0]={0};
    readData("shader/scenebasic2.dat");
}

void SceneBasic::readData(const char* fname)
{
    ifstream ifs(fname);

    if (!ifs) {
        std::cout << "data file not found\n";
        exit(1);
    } else {
        for (int i=0; i<108; i++) ifs >> positionData[i];//Store all positions in an array
        for (int i=0; i<108; i++) ifs >> colorData[i];//Store all colors in an array
    }

    //The following determine the center of the cube in order to center the camera on this point
    float xMin = positionData[0], xMax = positionData[0],
          yMin = positionData[1], yMax = positionData[1],
          zMin = positionData[2], zMax = positionData[2];

    for(int i = 3; i < 108; ++i) {
        if (i%3 == 0) {
            if(positionData[i] < xMin) {
                xMin = positionData[0];
            }
            if(positionData[i] > xMax) {
                xMax = positionData[i];
            }
        } else if (i%3 == 1) {
            if(positionData[i] < yMin) {
                yMin = positionData[i];
            }
            if(positionData[i] > yMax) {
                yMax = positionData[i];
            }
        } else if (i%3 == 2){
            if(positionData[i] < zMin) {
                zMin = positionData[i];
            }
            if(positionData[i] > zMax) {
                zMax = positionData[i];
            }
        }
    }

    this->center[0] = (xMin + xMax) / 2;
    this->center[1] = (yMin + yMax) / 2;
    this->center[2] = (zMin + zMax) / 2;
}


void SceneBasic::setAngleAxis(float ang, glm::vec3 ax)
{
    angle = ang;
    axis = ax;
}

void SceneBasic::CreateVBO()
{
    // Create and populate the buffer objects
    glGenBuffers(2, vboHandles);

    GLuint positionBufferHandle = vboHandles[0];
    GLuint colorBufferHandle = vboHandles[1];

    // bind positionBufferHandle to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), positionData, GL_STATIC_DRAW);

     // bind colorBufferHandle to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), colorData, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    glGenVertexArrays( 1, &vaoHandle );
    // bind the vertex array object
    glBindVertexArray(vaoHandle);

    /* enables the generic vertex attribute array
       the values in the generic vertex attribute array will be accessed
       and used for rendering when calls are made to vertex array commands
       such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);

    /* define an array of generic vertex attribute data
       specifies the location and data format of the array of generic
       vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

//Write the line thanks to the 2 points given
void SceneBasic::writeLine(glm::vec3 p1, glm::vec3 p2)
{
    //Define a line with a flat triangle
    positionDataLine[0]= p1[0];
    positionDataLine[1]= p1[1];
    positionDataLine[2]= p1[2];

    positionDataLine[3]= p2[0];
    positionDataLine[4]= p2[1];
    positionDataLine[5]= p2[2];

    for(int i=0;i<2;i++)
    {
        //set the green color
       colorDataLine[i*3]= 0.0f; //white
       colorDataLine[i*3+1]= 1.0f;
       colorDataLine[i*3+2]= 0.0f;
    }

}

void SceneBasic::CreateVBOLine()
{
    /*
     * VBOs CREATED
     *
     */
if(firstLine)//in order to not creat a new buffer each time the user create a line.
            //Only the first time.
{
    // Create and populate the buffer objects
     glGenBuffers(2, vboLine);
     firstLine=false;
}
    GLuint positionBufferLine = vboLine[0];
    GLuint colorBufferLine = vboLine[1];

    // bind positionBufferLine to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferLine);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positionDataLine, GL_STATIC_DRAW);

    // bind colorBufferLine to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferLine);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colorDataLine, GL_STATIC_DRAW);


   /*
    * VAO CREATED
    *
    */

   // bind the vertex array object
    glBindVertexArray(vaoLine);

   /* enables the generic vertex attribute array
      the values in the generic vertex attribute array will be accessed
      and used for rendering when calls are made to vertex array commands
      such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferLine);

   /* define an array of generic vertex attribute data
      specifies the location and data format of the array of generic
      vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferLine);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void SceneBasic::initScene()
{
    //////////////////////////////////////////////////////
    /////////// Vertex shader //////////////////////////
    //////////////////////////////////////////////////////

    /* The OpenGL Extension Wrangler Library (GLEW) is a cross-platform
     open-source C/C++ extension loading library. GLEW provides efficient
     run-time mechanisms for determining which OpenGL extensions are supported
     on the target platform.

     if you link with some function - it must exist on target platform,
     or your program wouldn't launch. GLEW handles that - you're not linking
     with GL functions directly, but instead getting function pointers after
     initialization phase. It allows you to check at runtime which extensions
     are present and which functions may be used.

     GLEW obtains information on the supported extensions from the graphics driver.
     Experimental or pre-release drivers, however, might not report every available
     extension through the standard mechanism, in which case GLEW will report
     it unsupported. To circumvent this situation, the glewExperimental global switch
     can be turned on by setting it to GL_TRUE before calling glewInit(), which ensures
     that all extensions with valid entry points will be exposed. */

    glewExperimental = GL_TRUE;
    glewInit();
    // Create and set-up the vertex array object
    glGenVertexArrays( 1, &vaoLine );

	// Create the vertex shader object
    GLuint vertShader = prog.createShader(GL_VERTEX_SHADER);

    // Check status
    if( 0 == vertShader)
    {
		fprintf(stderr, "Error creating vertex shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(vertShader,"shader/basic.vert");

	// compile the shader
    prog.compileShader(vertShader);

    // Check compilation status
    prog.checkCompileStatus(vertShader);

    progLine.load_shader(vertShader,"shader/basic.vert");

    // compile the shader
    progLine.compileShader(vertShader);

    // Check compilation status
    progLine.checkCompileStatus(vertShader);
  
    //////////////////////////////////////////////////////
    /////////// Fragment shader //////////////////////////
    //////////////////////////////////////////////////////


   // Create the fragment shader object
    GLuint fragShader = prog.createShader(GL_FRAGMENT_SHADER);

    // Check status
    if( 0 == fragShader)
    {
		fprintf(stderr, "Error creating fragment shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(fragShader,"shader/basic.frag");

	// compile the shader
    prog.compileShader(fragShader);

    // Check compilation status
    prog.checkCompileStatus(fragShader);

    // load the shader from the file
    progLine.load_shader(fragShader,"shader/basic.frag");

    // compile the shader
    progLine.compileShader(fragShader);

    // Check compilation status
    progLine.checkCompileStatus(fragShader);

    // Create the program object
    if (!prog.createObject()) printf("error\n");

    // attach shaders to program object
    prog.attachShader(vertShader);
    prog.attachShader(fragShader);

    // Bind index 0 to the shader input variable "VertexPosition"
    prog.bindAttribLocation(0, "VertexPosition");
    // Bind index 1 to the shader input variable "VertexColor"
    prog.bindAttribLocation(1, "VertexColor");

    // link the program
    prog.link();

    // create and populate the vertex buffer opbject
    CreateVBO();

    prog.printActiveUniforms();

    // Create the program object
    if (!progLine.createObject()) printf("error\n");

    // attach shaders to program object
    progLine.attachShader(vertShader);
    progLine.attachShader(fragShader);

    // Bind index 0 to the shader input variable "VertexPosition"
    progLine.bindAttribLocation(0, "VertexPosition");
    // Bind index 1 to the shader input variable "VertexColor"
    progLine.bindAttribLocation(1, "VertexColor");

    // link the program
    progLine.link();

    progLine.printActiveUniforms();

    //initialisation of the model of the cube
    model = mat4(1.0f);
    modelInit= mat4(1.0f);

    //initialisation of the model of the line
    modelLine = mat4(1.0f);

    //set the view at the initial position
    view=glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3(0.0f,0.0f,(2.0f-1.0f)), vec3(0.0f,1.0f,0.0f));

    //Copy the inital view on viewInit to go back to the initial view
    viewInit=view;

    //Copy the initial model on modelInit to go back to the initial position of the cube
    modelInit=model;

    //set the projection
    projection = mat4(1.0f);

    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glEnable(GL_DEPTH_TEST);
}


void SceneBasic::update( float t )
{
    angle += t*2*PI/360.0;
    if( t >= 360.0) angle -= 360.0;
}

std::vector<double> const &SceneBasic::getCenter()
{
    return center;
}


void SceneBasic::render()
{

    /* sets the bitplane area of the window to values previously
       selected by glClear. GL_COLOR_BUFFER_BIT indicates the buffers
       currently enabled for color writing. */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* render primitives from array data
       GL_TRIANGLES Specifies what kind of primitives to render.
       Possibilities are symbolic constants GL_POINTS, GL_LINE_STRIP,
       GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN and GL_TRIANGLES.
       0 specifies the starting index in the enabled arrays.
       36 specifies the number of indices to be rendered. */

    //Apply the transformation to the cube
    prog.link();
    glBindVertexArray(vaoHandle);
    mat4 mv = view*model;
    prog.setUniform("MVP", projection * mv);
    glDrawArrays(GL_TRIANGLES, 0, 36 );//6*6 because it is triangles

    //Apply the transformation to the line
    progLine.link();
    glBindVertexArray(vaoLine);
    mat4 mvLine = view*modelLine;
    progLine.setUniform("MVP", projection * mvLine);
    glDrawArrays(GL_LINES, 0, 2 );//2 for the line
}

void SceneBasic::resize(int w, int h)
{
    glViewport(0,0,w,h);
    width = w;
    height = h;

    //set the perspective
    projection = glm::perspective(20.0f, (float)w/h, 0.3f, 30.0f);
}


void SceneBasic::printActiveUniforms(GLuint programHandle) {

    GLint nUniforms, size, location, maxLen;
    GLchar * name;
    GLsizei written;
    GLenum type;

    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

    name = (GLchar *) malloc( maxLen );

    printf(" Location | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nUniforms; ++i ) {
        glGetActiveUniform( programHandle, i, maxLen, &written, &size, &type, name );
        location = glGetUniformLocation(programHandle, name);
        printf(" %-8d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::printActiveAttribs(GLuint programHandle) {

    GLint written, size, location, maxLength, nAttribs;
    GLenum type;
    GLchar * name;

    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &nAttribs);

    name = (GLchar *) malloc( maxLength );

    printf(" Index | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nAttribs; i++ ) {
        glGetActiveAttrib( programHandle, i, maxLength, &written, &size, &type, name );
        location = glGetAttribLocation(programHandle, name);
        printf(" %-5d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::rotateModel(setOfValues param)
{
    //Set the angle in radian in order to use glm::rotate
    float phiRadian=glm::radians(param.alpha);

    //vector translation
    glm::vec3 trans((center[0]-param.xB),(center[1]-param.yB),(center[2]-param.zB));

    //Rotation of the cube: translation*rotation*(-translation)
    this->model=glm::translate(this->model,trans);
    this->model= glm::rotate(this->model,phiRadian,glm::vec3(param.xD,param.yD,param.zD));
    this->model=glm::translate(this->model,-trans);
}

//If no parameters of the view are choosen, set the camera on the center of the cube, else with parameters of the user
void SceneBasic::updateEyeCameraOnCube(std::vector<double> center)
{
    if(noParam)//If no parameters are entered by the user
    {
        //Set the view on the center of the cube
        view = glm::lookAt(vec3(0.0f,0.0f,2.0f), vec3((float)center[0],(float)center[1],(float)(center[2])), vec3(0.0f,1.0f,0.0f));
    }
}

void SceneBasic::updateEyeCameraUser(setOfView param)
{
    if((param.eyex == 0 && param.eyey != 0 && param.eyez == 0)
    || (param.directx+param.eyex == 0 && param.directy+param.eyey != 0 && param.directz+param.eyez == 0)) {
    view=glm::lookAt(vec3((float)param.eyex,(float)param.eyey,(float)param.eyez),vec3((float)(param.eyex+param.directx),(float)(param.eyey+param.directy),(float)(param.eyez+param.directz)),vec3(0.0f,0.0f,1.0f));
    } else {
    //Set the view with the user parameters
    view=glm::lookAt(vec3((float)param.eyex,(float)param.eyey,(float)param.eyez),vec3((float)(param.eyex+param.directx),(float)(param.eyey+param.directy),(float)(param.eyez+param.directz)),vec3(0.0f,1.0f,0.0f));
    }
    //indicate that parameters are entered
    noParam=false;
}

void SceneBasic::restoreCamDefault()
{
    //Parameters from the begining are set (model and view)
    model=modelInit;

    //Set the default view
    view=glm::lookAt(vec3(0.0f,0.0f,2.0f),vec3(0.0f,0.0f,(2.0f-1.0f)),vec3(0.0f,1.0f,0.0f));

    //indicate that initial parameters are sets. Old settings are erased.
    noParam=true;
}
