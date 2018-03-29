#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define SC_WIDTH 1240
#define SC_HEIGHT 1024
#define WINDOW_NAME "Robotic Codes"

int initialize();
void drawMenu();
bool quit_status = false;
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
void dGrayRect(int x1, int y1, int x2, int y2);

int main(int argc, char* argv[]){
  if (initialize())
    fprintf(stderr, "Couldn't initialize SDL2\n");
  SDL_Event event;
  while (!quit_status){ // While loop for running
    while (SDL_PollEvent(&event) != 0){ // handle input
      if (event.type == SDL_QUIT)
        quit_status = true;
    }
    // Prepare things
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(ren);
    drawMenu();
    // Show things
    SDL_RenderPresent(ren);
  }
  //Time to quit
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  ren = NULL;
  win = NULL;
  SDL_Quit();
  return 0;
}

int initialize(){
  int result = 0;
  result += SDL_Init(SDL_INIT_VIDEO);
  result += SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  win = SDL_CreateWindow(WINDOW_NAME,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SC_WIDTH,
      SC_HEIGHT,
      SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (win == NULL || ren == NULL)
    fprintf(stderr, "%s\n", "Couldn't make windows with renderer");
  SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
  return 0;
}

void drawMenu(){
  dGrayRect(0, 0, 8, SC_HEIGHT);
  dGrayRect(0, 0, SC_WIDTH, 10);
  dGrayRect(SC_WIDTH-10, 0, SC_WIDTH, SC_HEIGHT);
  dGrayRect(0, SC_HEIGHT-10, SC_WIDTH, SC_HEIGHT);
  rectangleRGBA(ren, 0, 0, SC_WIDTH/2, SC_HEIGHT/2, 0xAA, 0x00, 0x00, 0xFF);
}

void dGrayRect(int x1, int y1, int x2, int y2){
  SDL_Rect bar = { x1, y1, x2, y2};
  SDL_SetRenderDrawColor(ren, 0xAA, 0xAA, 0xAA, 0xFF);
  SDL_RenderFillRect(ren, &bar);
}
