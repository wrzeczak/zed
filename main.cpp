#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>

#include <raylib.h>

#include "config.h"
#include "card.h"
#include "draw.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(void) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIDTH, HEIGHT, TITLE);

    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    ToggleFullscreen();

    srand(time(NULL));

    Deck deck;
    Deck play;
    Deck hand;

    for(int i = -2; i <= 3; i++) {
        deck.push_back(LoadCard(i));
    }

    Texture2D background_tex = LoadTexture(BACKGROUNDTEXPATH);

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_SPACE)) deck.push_back(LoadCard(rand() % SKIP + YELLOW_OFFSET));
        BeginDrawing();
            ClearBackground(LIME);

            DrawBackground(background_tex);
            DrawTitle();
            
            DrawHand(deck);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}