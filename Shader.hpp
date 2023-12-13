#ifndef __SHADER__
#define __SHADER__

#include "general-imports.MThImports"
#include <GL/glew.h>
#include <fstream>

class Shader{
public:
  Shader(const std::string& fileName, unsigned int shadersNum, std::string vertName = ".vert", std::string fragName = ".frag", std::string geomName = ".geom");
  ~Shader();

  int Bind();
  GLuint CreateShader(const std::string& text, GLenum shaderType);

private:
  GLuint program;
  unsigned int shadersNum;
  GLuint *shaders;

  std::string LoadShader(const std::string& fileName);
  void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
};

#endif
