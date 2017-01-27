#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H
/*!
* \file glslprogram.h
* \brief All functions and ways to load, create, compile shaders,  apply transformations etc .. It is the link whit the graphical card
* \author Lucien MAMAN
* \date 26/01/2017
*/
#include "C:/glew-1.13.0/include/GL/glew.h"
#include <string>
using std::string;

#include "C:/glm/glm/glm.hpp"
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::mat3;

namespace GLSLShader {
    enum GLSLShaderType {
        VERTEX, FRAGMENT, GEOMETRY,
        TESS_CONTROL, TESS_EVALUATION
    };
};

class GLSLProgram
{
private:
    // the program object handle
    GLuint  handle;

    // linked status
    bool linked;

    // string for log information
    string logString;

    // returns the location of a uniform variable specified by name
    int  getUniformLocation(const char * name );

    // checks if the file specified by filename exists
    bool fileExists( const string & fileName );

public:
    /*!
    *  \brief Default constructor of GLSLProgram
    */
    GLSLProgram();

    /*!
    *  \brief  Read the shader source from a file and compile
    *
    *  \param fileName : name of the file
    *  \param type : type of shader
    */
    bool compileShaderFromFile( const char * fileName, GLSLShader::GLSLShaderType type );

    /*!
    *  \brief  Compiles shader source code stored in a string
    *
    *  \param source : source of the shader
    *  \param type : type of shader
    */
    bool compileShaderFromString( const string & source, GLSLShader::GLSLShaderType type );

    /*!
    *  \brief  Load the shader source code from the file into a string
    *
    *  \param fname : name of the file
    */
    std::string loadFileToString(const char* fname);

    /*!
    *  \brief  Load the shader code from a file
    *
    *  \param shaderobject : shader object
    *  \param shadersourcefilename : name of the file of the shader
    */
    void load_shader(GLuint shaderobject, const char*  shadersourcefilename);

    /*!
    *  \brief  glShaderSource sets the source code in shader to the source code in the array of strings specified by string.
    *
    *  \param shader : shader
    *  \param shader_string : name of the file of the shader (string)
    */
    void glcppShaderSource(GLuint shader, std::string const &shader_string);

    /*!
    *  \brief  glCreateShader creates an empty shader object and returns a non-zero value by which it can be referenced.
    *
    *  \param shaderType: type of the shader
    */
    GLuint createShader(GLenum shaderType);

    /*!
    *  \brief  glCompileShader compiles the source code strings that have been stored in the shader object specified by shader.
    *
    *  \param shader: shader
    */
    void compileShader(GLuint shader);


    /*!
    *  \brief Provides error log information for compilation of shader
    *
    *  \param shader: shader
    */
    void checkCompileStatus(GLuint shader);

    /*!
    *  \brief Attaches the shader object specified by shader to the program object specified by handle.
    *
    *  \param shader: shader
    */
    void attachShader(GLuint shader);

    bool link();/*!< Links the program object specified by handle.  */

    void use();/*!< Installs the program object specified by handle as part of current rendering state.  */

    bool createObject();/*!< Creates an empty program object and returns a non-zero value by which it can be referenced.  */

    string log();/*!< Returns the logString  */

    GLuint getHandle();/*!< Return the program object handle  */

    bool isLinked();/*!< Returns the link status  */

    /*!
    *  \brief associates a user-defined attribute variable in the program object specified by handle with a generic vertex attribute index.
    *
    *  \param location: location of the GLuint
    *  \param name: name
    */
    void bindAttribLocation( GLuint location, const char * name);


    /*!
    *  \brief bind a user-defined varying out variable specified by name to a fragment shader color number specified by location
    *
    *  \param location: location of the GLuint
    *  \param name: name
    */
    void bindFragDataLocation( GLuint location, const char * name );


    // the following group of setUniform methods modify the value of a uniform variable or a uniform variable array.

    /*!
    *  \brief x,y,z are the new values to be used for the specified uniform variable
    *
    *  \param name: name
    *  \param x: coordinate x
    *  \param y: coordinate y
    *  \param z: coordinate z
    */
    void setUniform( const char *name, float x, float y, float z);

    /*!
    *  \brief v.x,v.y,v.z are the new values to be used for the specified uniform variable
    *
    *  \param name: name
    *  \param v: vector of values
    */
    void setUniform( const char *name, const vec3 & v);

    /*!
    *  \brief v.x,v.y,v.z, v.w are the new values to be used for the specified uniform variable
    *
    *  \param name: name
    *  \param v: vector of values
    */
    void setUniform( const char *name, const vec4 & v);

    /*!
    *  \brief val is the new value for the uniform variable
    *
    *  \param name: name
    *  \param val: value of the uniform variable
    */
    void setUniform( const char *name, float val );

    /*!
    *  \brief val is the new value for the uniform variable
    *
    *  \param name: name
    *  \param val: value of the uniform variable
    */
    void setUniform( const char *name, int val );

    /*!
    *  \brief val is the new value for the uniform variable
    *
    *  \param name: name
    *  \param val: value of the uniform variable
    */
    void setUniform( const char *name, bool val );

    /*!
    *  \brief The commands glUniformMatrix{2|3|4}fv are used to modify a matrix or an array of matrices. The numbers in the command name are interpreted as the dimensionality of the matrix.
    *
    *  \param name: name
    *  \param m: matrix 4*4
    */
    void setUniform( const char *name, const mat4 & m);
    /*!
    *  \brief The commands glUniformMatrix{2|3|4}fv are used to modify a matrix or an array of matrices. The numbers in the command name are interpreted as the dimensionality of the matrix.
    *
    *  \param name: name
    *  \param m: matrix 3*3
    */
    void setUniform( const char *name, const mat3 & m);

    /*!
    *  \brief Prints all the active uniform variables
    */
    void printActiveUniforms();

    /*!
    *  \brief Prints all the active attribute variables
    */
    void printActiveAttribs();
};

#endif // GLSLPROGRAM_H
