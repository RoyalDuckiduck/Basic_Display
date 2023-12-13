#include "general-imports.MThImports"
#include "Window.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

int main(int argc, char const *argv[]) {

  std::string title = "";
  Window window(700, 500, title);
  Vertex verticies[] = {
    Vertex(-.5f,-.5f), Vertex(.5f, -.5f), Vertex(-.5f, .5f),
    Vertex(.5f,.5f), Vertex(.5f, -.5f), Vertex(-.5f, .5f),
  };
  Mesh mesh(verticies, sizeof(verticies)/sizeof(verticies[0]));
  std::string shs = "./testShaders/testShader";
  Shader shader(shs, 2);

  while (!window.Update()){
    //any process while the window is opened.
    //exemple with a screen clear :
    window.Clear(255.0f, 100.0f, 0.0f, 255.0f);

    //shader.Bind();
    mesh.Draw();
  }

  return 0;
}
