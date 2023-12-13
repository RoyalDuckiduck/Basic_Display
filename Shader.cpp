#include "Shader.hpp"

Shader::Shader(const std::string& fileName, unsigned int shadersNum, std::string vertName, std::string fragName, std::string geomName){

  this->shadersNum = shadersNum;

  shaders = new GLuint[shadersNum];

  program = glCreateProgram();

  shaders[0] = CreateShader(LoadShader(fileName + vertName), GL_VERTEX_SHADER);
  shaders[1] = CreateShader(LoadShader(fileName + fragName), GL_FRAGMENT_SHADER);
  if (shadersNum == 3)
    shaders[2] = CreateShader(LoadShader(fileName + geomName), GL_GEOMETRY_SHADER);

  for (int i; i<shadersNum; i++)
    glAttachShader(program, shaders[i]);

  glBindAttribLocation(program, 0, "position");

  glLinkProgram(program);
  CheckShaderError(program, GL_LINK_STATUS, true, "failed to link shader program. : ");

  glValidateProgram(program);
  CheckShaderError(program, GL_VALIDATE_STATUS, true, "failed to validate shader program. : ");
}

Shader::~Shader(){
  for (int i; i<shadersNum; i++){
    glDetachShader(program, shaders[i]);
    glDeleteShader(shaders[i]);
  }

  glDeleteProgram(program);
}


GLuint Shader::CreateShader(const std::string& text, GLenum shaderType){
  GLuint shader = glCreateShader(shaderType);

  if (!shader)
    std::cerr << "shader creation failed" << '\n';

  const GLchar* shaderSource[1] = {text.c_str()};
  GLint shaderSourceLen[1];
  shaderSourceLen[0] = text.length();

  glShaderSource(shader, 1, shaderSource, shaderSourceLen);
  glCompileShader(shader);

  CheckShaderError(shader, GL_COMPILE_STATUS, false, "failed to compile shader");

  return shader;
}

int Shader::Bind(){
  glUseProgram(program);

  return 0;
}


std::string Shader::LoadShader(const std::string& fileName){
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
