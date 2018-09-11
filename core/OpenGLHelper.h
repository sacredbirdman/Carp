#ifndef __APPLE__
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
  
#include <carp_memory.h>
#include <core.h>

GLuint GL_genVertexArray() {

  GLuint tmp = 0;

#ifndef __APPLE__
  glewExperimental = GL_TRUE; 
  glewInit();
#endif

  glGenVertexArrays(1, &tmp);
  return tmp;
}

GLuint GL_genBuffer() {
  GLuint tmp = 0;
  glGenBuffers(1, &tmp);
  return tmp;
}

void GL_bufferIntData(GLenum target, int length, int *data, GLenum usage) {
  glBufferData(target, length * sizeof(int), data, usage);
}

void GL_bufferFloatData(GLenum target, int length, float* data, GLenum usage) {
  glBufferData(target, length * sizeof(float), data, usage);
}

void GL_checkCompileErrors(GLuint shaderID) {
	int shaderCompilationStatus = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &shaderCompilationStatus);

        if(shaderCompilationStatus == GL_TRUE) {
           printf("Compilation successful!\n");
        } else {
           int logLength = 0;
	   glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
	   char* infoLog = (char*) malloc(logLength);
	   glGetShaderInfoLog(shaderID, logLength, NULL, infoLog);
	   printf("A Shader compilation error occurred. Info log:\n");
	   printf("%s\n", infoLog);
	   free(infoLog);
	}
}

void GL_checkLinkErrors(GLuint programID) {
	int programLinkStatus = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &programLinkStatus);
        
        if(programLinkStatus == GL_TRUE) {
          printf("Linking successful!\n");
        } else {

          int logLength = 0;
	  glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
	  char* infoLog = (char*) malloc(logLength);
	  glGetProgramInfoLog(programID, logLength, NULL, infoLog);
	  printf("Program linking failed. Info log:\n");
	  printf("%s\n", infoLog);
	  free(infoLog);
	}
}


