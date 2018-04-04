#include <iostream>

#include "ColorContainer.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

const int WIDTH = 940, HEIGHT = 720;

int main(int argc, char *argv[]) {
    SDL_Surface *windowSurface;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Color Sorter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
       SDL_DestroyWindow(window);
       printf ("SDL_CreateRenderer Error: %s", SDL_GetError());
       SDL_Quit();
       return 1;
    }

    // Check that the window was successfully created
    if (NULL == window) {
        // In the case that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    SDL_PixelFormat *fmt = windowSurface->format;

    ColorContainer myColors;
    vector<ColorType> myVec = myColors.getColorVec();

    bool sorted = false;

    struct Button {
        int left;
        int right;
        int top;
        int bottom;
        bool pressed;
    };

    Button rb = {100, 150, HEIGHT - 10, HEIGHT - 40, false};
    Button gb = {170, 220, HEIGHT - 10, HEIGHT - 40, false};
    Button bb = {240, 290, HEIGHT - 10, HEIGHT - 40, false};
    Button ab = {310, 360, HEIGHT - 10, HEIGHT - 40, false};

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
            if (SDL_MOUSEBUTTONDOWN == windowEvent.type) {
                if (windowEvent.motion.x > rb.left && windowEvent.motion.x < rb.right &&
                    windowEvent.motion.y > rb.bottom && windowEvent.motion.x < rb.top) {
                    rb.pressed = true;
                } else { rb.pressed = false; }
                if (windowEvent.motion.x > gb.left && windowEvent.motion.x < gb.right &&
                    windowEvent.motion.y > gb.bottom && windowEvent.motion.x < gb.top) {
                    gb.pressed = true;
                } else { gb.pressed = false; }
                if (windowEvent.motion.x > bb.left && windowEvent.motion.x < bb.right &&
                    windowEvent.motion.y > bb.bottom && windowEvent.motion.x < bb.top) {
                    bb.pressed = true;
                } else { bb.pressed = false; }
                if (windowEvent.motion.x > ab.left && windowEvent.motion.x < ab.right &&
                    windowEvent.motion.y > ab.bottom && windowEvent.motion.x < ab.top) {
                    ab.pressed = true;
                } else { ab.pressed = false; }
            }
            if (SDL_MOUSEBUTTONUP == windowEvent.type) {
                sorted = false;
                rb.pressed = false;
                gb.pressed = false;
                bb.pressed = false;
                ab.pressed = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (rb.pressed) {
            boxRGBA(renderer, rb.left, rb.bottom, rb.right, rb.top, 255, 0, 0, 255);
            if (!sorted) {
                sorted = true;
                myVec = myColors.sortRed(myVec);
            }
        } else rectangleRGBA(renderer, rb.left, rb.bottom, rb.right, rb.top, 255, 0, 0, 255);

        if (gb.pressed) {
            boxRGBA(renderer, gb.left, gb.bottom, gb.right, gb.top, 0, 255, 0, 255);
            if (!sorted) {
                sorted = true;
                myVec = myColors.sortGreen(myVec);
            }
        } else rectangleRGBA(renderer, gb.left, gb.bottom, gb.right, gb.top, 0, 255, 0, 255);

        if (bb.pressed) {
            boxRGBA(renderer, bb.left, bb.bottom, bb.right, bb.top, 0, 0, 255, 255);
            if (!sorted) {
                sorted = true;
                myVec = myColors.sortBlue(myVec);
            }
        } else rectangleRGBA(renderer, bb.left, bb.bottom, bb.right, bb.top, 0, 0, 255, 255);

        if (ab.pressed) {
            boxRGBA(renderer, ab.left, ab.bottom, ab.right, ab.top, 255, 255, 255, 255);
            if (!sorted) {
                sorted = true;
                myVec = myColors.sortAlpha(myVec);
            }
        } else rectangleRGBA(renderer, ab.left, ab.bottom, ab.right, ab.top, 255, 255, 255, 255);

        for (int i = 0; i < myVec.size(); i++) {
            boxRGBA(renderer, i * WIDTH/myVec.size(), 50, i * WIDTH/myVec.size() + WIDTH/myVec.size(), HEIGHT - 50, myVec[i].r, myVec[i].g, myVec[i].b, myVec[i].a);
        }

        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyRenderer(renderer);

    windowSurface = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
