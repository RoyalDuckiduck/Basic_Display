#include "Window.hpp"

Window::Window(int width, int height, std::string& title){
  if (SDL_Init(SDL_INIT_EVERYTHING)){
    std::cerr << "erreor initializing SDL in Window class Constructor" << "\n";
    return;
  }

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  context = SDL_GL_CreateContext(window);

  GLenum state = glewInit();

  if (state != GLEW_OK){
    std::cerr << "erreor initializing glew in Window class Constructor   " << '\n';
    return;
  }

  std::cout << "created a new window " << title << '\n';
}

Window::~Window(){
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "deleted a window" << '\n';
}

int Window::SwapBuffers(){
  SDL_GL_SwapWindow(this->window);
  return 0;
}

int Window::Update(){
  SDL_Event event;

  while (SDL_PollEvent(&event)){
    if (event.type == SDL_QUIT){
      return 1;
    }
  }

  this->SwapBuffers();
  return 0;
}

void Window::Clear(float r, float g, float b, float a){
  glClearColor(r/255, g/255, b/255, a/255);
  glClear(GL_COLOR_BUFFER_BIT);
}
