#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define SC_WIDTH 1240
#define SC_HEIGHT 1024
#define WINDOW_NAME "Robotic Codes"
#define YAH_PATH "resources/yeah.wav"
#define MUS_PATH "resources/cantina.ogg"
#define WSH_PATH "resources/swoosh.wav"
#define CLK_PATH "resources/click.wav"
#define SKR_PATH "resources/scream.wav"

int initialize();
void drawMenu();
bool quit_status = false;
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
TTF_Font *font = NULL;
TTF_Font *wfont = NULL;
bool settings[5] = {0, 0, 1, 0, 0};
Mix_Chunk *yah = NULL;
Mix_Music *music = NULL;
Mix_Chunk *wsh = NULL;
Mix_Chunk *clk = NULL;
Mix_Chunk *skr = NULL;
void dGrayRect(int x1, int y1, int x2, int y2);
void dButton(int x1, int y1, int x2, int y2, char *label);
void dBRect(int x1, int y1, int x2, int y2);
void drawLabel(int x, int y, int w, int h, char *label);
void drawstat();
void plays(Mix_Chunk *snd);
void moused(int x, int y);

int main(int argc, char* argv[]){
  if (!initialize())
    fprintf(stderr, "Couldn't initialize SDL2\n");
  SDL_Event event;
  // Prepare things
  SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(ren);
  drawMenu();
  // Show things
  //Mix_PlayMusic( music, -1);

  while (!quit_status){ // While loop for running
    while (SDL_PollEvent(&event) != 0){ // handle input
      if (event.type == SDL_QUIT)
        quit_status = true;
      if (event.type == SDL_MOUSEBUTTONUP){
      }
      if (event.type == SDL_MOUSEBUTTONDOWN){
        moused(event.motion.x, event.motion.y);
      }
    }
    // old sleep usleep(500);
  }
  //Time to quit
  Mix_FreeChunk(yah);
  Mix_FreeChunk(wsh);
  Mix_FreeChunk(clk);
  Mix_FreeChunk(skr);
	Mix_FreeMusic(music);

	// quit SDL_mixer
	Mix_CloseAudio();
  TTF_CloseFont(font);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  ren = NULL;
  win = NULL;
  SDL_Quit();
  return 0;
}

int initialize(){
  int result = 0;
  if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return -1;
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
		result = -1;
  if (TTF_Init() == -1){
    fprintf(stderr, "%s\n", "Couldn't initialize TTF font system.");
    exit(-1);
  }
  result += SDL_Init(SDL_INIT_VIDEO);
  result += SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  win = SDL_CreateWindow(WINDOW_NAME,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SC_WIDTH,
      SC_HEIGHT,
      SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (win == NULL || ren == NULL){
    fprintf(stderr, "%s\n", "Couldn't make windows with renderer");
    exit(-1);
  }
  SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
  wfont = TTF_OpenFont("resources/Golden Age Shad.ttf", 60);
  font = TTF_OpenFont("resources/WRESTLEMANIA.ttf", 50);
  yah = Mix_LoadWAV(YAH_PATH);
  wsh = Mix_LoadWAV(WSH_PATH);
  clk = Mix_LoadWAV(CLK_PATH);
  skr = Mix_LoadWAV(SKR_PATH);
	music = Mix_LoadMUS(MUS_PATH);
  Mix_VolumeMusic(64);
}

void drawMenu(){
  char* labels[] = {(char*)"X", (char*)"R1", (char*)"R2", (char*)"R3", (char*)"R4", (char*)"R5", (char*)"R6", (char*)"Q U I T", (char*)"P L A Y"};
  char* options[] = {(char*)"Scan Arcs", (char*)"Source", (char*)"Graphics", (char*)"Silent", (char*)"Compile"};
  dGrayRect(0, 0, 10, 1024);                // Left Border
  dGrayRect(0, 0, 1240, 10);                // Top Border
  dGrayRect(1230, 0, 1240, 1024);           // Right Border
  dGrayRect(0, 1014, 1240, 1024);           // Bottom Border
  SDL_Color color={255,255,255};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(wfont, "Robotic Codes", color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
  SDL_Rect Message_rect;                    //create a rect
  Message_rect.x = 50;                      //controls the rect's x coordinate
  Message_rect.y = 20;                      // controls the rect's y coordinte
  Message_rect.w = 780;                     // controls the width of the rect
  Message_rect.h = 60;                      // controls the height of the rect
  SDL_RenderCopy(ren, Message, NULL, &Message_rect);
  SDL_FreeSurface(surfaceMessage);
  dGrayRect(10, 90, 1230, 512);             // file selection background
  dButton(10, 158, 50, 50, labels[0]);      // R1 Close
  dButton(10, 276, 50, 50, labels[0]);      // R2 Close
  dButton(10, 394, 50, 50, labels[0]);      // R3 Close
  dButton(70, 158, 50, 50, labels[1]);      // R1 Open
  dButton(70, 276, 50, 50, labels[2]);      // R2 Open
  dButton(70, 394, 50, 50, labels[3]);      // R3 Open
  dBRect(123, 158, 407, 50);                // File Box R1
  dBRect(123, 276, 407, 50);                // File Box R2
  dBRect(123, 394, 407, 50);                // File Box R3
  dButton(630, 158, 50, 50, labels[0]);      // R4 Close
  dButton(630, 276, 50, 50, labels[0]);      // R5 Close
  dButton(630, 394, 50, 50, labels[0]);      // R6 Close
  dButton(690, 158, 50, 50, labels[4]);      // R4 Open
  dButton(690, 276, 50, 50, labels[5]);      // R5 Open
  dButton(690, 394, 50, 50, labels[6]);      // R6 Open
  dBRect(743, 158, 407, 50);                // File Box R4
  dBRect(743, 276, 407, 50);                // File Box R5
  dBRect(743, 394, 407, 50);                // File Box R6
  dGrayRect(70, 950, 600, 1000);            // Quit Box
  dGrayRect(640, 950, 1170, 1000);          // Play Box
  drawLabel(210, 925, 210, 80, labels[7]);  // Quit Label
  drawLabel(780, 925, 210, 80, labels[8]);  // Play Label
  for (int i=0; i<5; i++){
    dButton(50, (530+(i*80)), 400, 60, options[i]);
  }
  drawstat();
  SDL_RenderPresent(ren);
}

void dGrayRect(int x1, int y1, int x2, int y2){
  /* OLD: used native SDL rectangle
  SDL_Rect bar = { x1, y1, x2, y2};
  SDL_SetRenderDrawColor(ren, 0xAA, 0xAA, 0xAA, 0xFF);
  SDL_RenderFillRect(ren, &bar);
  */
  // Now uses SDL2_gfx
  boxRGBA(ren, x1, y1, x2, y2, 0x96, 0x96, 0x96, 0xFF);
}

void dBRect(int x1, int y1, int x2, int y2){
  x2 += x1;
  y2 += y1;
  boxRGBA(ren, x1, y1, x2, y2, 0x00, 0x00, 0x00, 0xFF);
}

void dButton(int x1, int y1, int x2, int y2, char *label){  // can only take in a single line of text
  boxRGBA(ren, x1+1, y1+1, x1+x2-1, y1+y2-1, 0xFF, 0xFF, 0xFF, 0xFF); // draw button
  boxRGBA(ren, x1+3, y1+3, x1+x2-3, y1+y2-3, 0xAA, 0xAA, 0xAA, 0xFF);
  SDL_Color color={0,0,0};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, label, color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
  SDL_Rect Message_rect; //create a rect
  Message_rect.x = x1+5;  //controls the rect's x coordinate
  Message_rect.y = y1+5; // controls the rect's y coordinte
  Message_rect.w = (x2-5); // controls the width of the rect
  Message_rect.h = (y2-5); // controls the height of the rect
  SDL_RenderCopy(ren, Message, NULL, &Message_rect);
  SDL_FreeSurface(surfaceMessage);
}

void drawLabel(int x, int y, int w, int h, char *label){
  SDL_Color col={0, 0, 0};
  SDL_Surface* messg = TTF_RenderText_Solid(font, label, col);
  SDL_Texture* messg_tx = SDL_CreateTextureFromSurface(ren, messg);
  SDL_Rect messg_rct;
  messg_rct.x = x;
  messg_rct.y = y;
  messg_rct.w = w;
  messg_rct.h = h;
  SDL_RenderCopy(ren, messg_tx, NULL, &messg_rct);
  SDL_FreeSurface(messg);
}

void drawstat(){
  for (int x=0; x<5; x++){
    if (settings[x]){
      filledCircleRGBA(ren, 525, (555+(x*80)), 25, 255, 255, 255, 255);
    }else{
      filledCircleRGBA(ren, 525, (555+(x*80)), 25, 0, 0, 0, 255);
      circleRGBA(ren, 525, (555+(x*80)), 25, 255, 255, 255, 255);
    }
  }
}

void plays(Mix_Chunk *snd){
  Mix_PlayChannel(-1, snd, 0);
}

void moused(int x, int y){
  if (x > 50 && x < 400){
    for (int i=0; i<5; i++){
      if (y > (530+(i*80)) && y < (590+(i*80))){
        settings[i] = !settings[i];
        plays(clk);
      }
    }
    drawMenu();
  }
  if (y > 925 && y < 985){
    if (x > 70 && x < 600){
      // clicked QUIT
      plays(skr);
      usleep(1000);
      quit_status = true;
    }else if (x > 780 && x < 990){
      //Clicked play
      
    }
  }
}
