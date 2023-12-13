#include "general-imports.MThImports"
#include "graphics-imports.MThImports"

#ifndef __MESH__
#define __MESH__

class Vertex{
public:
  Vertex(float xPos, float yPos, float zPos = 0, float xSize = 1, float ySize = 1){
    pos = glm::vec3(xPos, yPos, zPos);
  }
  ~Vertex(){}
private:
  glm::vec3 pos;
};

class Mesh{
public:
  Mesh(Vertex *verticies, int verticies_amount);
  ~Mesh();

  int Draw();
private:

  enum{
    POSITION_VERTEX_BUFFER,

    BUFFERS_NUMBER
  };

  unsigned int verticies_amount;

  GLuint vao;
  GLuint vab[BUFFERS_NUMBER];
};

#endif
