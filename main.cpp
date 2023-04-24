#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Okienko SDL",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   640, 480,
                                   SDL_WINDOW_SHOWN);
    int gaming = true;
    for (int i = 0; i < 1000; i++) {
        SDL_Event e;
        while(SDL_PollEvent(&e) != 0) {

        }
        SDL_Delay(10);

    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
