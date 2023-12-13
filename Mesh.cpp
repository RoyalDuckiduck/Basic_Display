#include "Mesh.hpp"

Mesh::Mesh(Vertex *verticies, int verticies_amount){
  this->verticies_amount = verticies_amount;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(BUFFERS_NUMBER, vab);
  glBindBuffer(GL_ARRAY_BUFFER, vab[POSITION_VERTEX_BUFFER]);
  glBufferData(GL_ARRAY_BUFFER, verticies_amount * sizeof(verticies[0]), verticies, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  glBindVertexArray(0);
  std::cout << "new mesh" << '\n';
}

Mesh::~Mesh(){
  glDeleteBuffers(BUFFERS_NUMBER, vab);
  glDeleteVertexArrays(1, &vao);
  std::cout << "destroyed mesh" << '\n';
}

int Mesh::Draw(){
  glBindVertexArray(vao);

  glDrawArrays(GL_TRIANGLES, 0, verticies_amount);

  glBindVertexArray(0);

  return 0;
}
