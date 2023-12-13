#include "general-imports.MThImports"
#include "graphics-imports.MThImports"

#ifndef __WINDOW__
#define __WINDOW__

class Window{
public:
  Window(int width, int height, std::string& title);
  ~Window();
  int Update();
  void Clear(float r, float g, float b, float a = 255);

  std::string ChangeTitle();
private:
  SDL_Window *window;
  SDL_GLContext context;

  int SwapBuffers();
};

#endif
