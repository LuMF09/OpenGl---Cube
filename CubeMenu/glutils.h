#ifndef GLUTILS_H
#define GLUTILS_H
/*!
* \file glutils.h
* \brief Management of possible errors
* \author Lucien MAMAN
* \date 26/01/2017
*/
class GLUtils
{
public:
    /*!
    *  \brief Constructor of GLUtils
    *
    *  \param none
    */
    GLUtils();

    static int checkForOpenGLError(const char *, int);
    static int checkForOpenGLError();
    static void dumpGLInfo(bool dumpExtensions = false);
};

#endif // GLUTILS_H
