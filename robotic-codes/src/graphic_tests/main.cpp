#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1500

bool running = 1;
void firstTriangle(GLFWwindow* w);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void drawMenu(GLFWwindow* w);
static void err_callback(int errnum, const char* desc);

int main(int argc, char* argv[]){
  if (!glfwInit()){
    fprintf(stderr, "Failed to start GLFW");
    return -1;
  }
  glfwWindowHint(GLFW_SAMPLES, 16);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSetErrorCallback(err_callback);
  GLFWwindow* win;
  win = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "W I N D O W", NULL, NULL);
  if (win == NULL){
    fprintf(stderr, "Failed top open GLFW window");
    glfwTerminate();
    return -1;
  }
  //Print Stat
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);

  glfwMakeContextCurrent(win);
  glewExperimental = GL_TRUE;
  glewInit();
  glfwSetKeyCallback(win, key_callback);
  //glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);
  while (!glfwWindowShouldClose(win)){




    glfwPollEvents();
  }
  return 0;
}

static void err_callback(int errnum, const char* desc){
  fprintf(stderr, "OOPS: %s\n", desc);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  //std::cout << key << " -- " << mods <<std::endl;
  printf("Found: %d\n", key);
  if (action == GLFW_PRESS){
    if (key == GLFW_KEY_ESCAPE ){
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }
}

void drawMenu(GLFWwindow* w){

}
