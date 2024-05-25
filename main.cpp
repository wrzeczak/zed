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

    std::vector<int> ids;
    for(int i = 0; i < 11; i++) {
        ids.push_back(rand() % (YELLOW_OFFSET + SKIP + 2) - 2);
    }
    Deck hand = LoadCards(ids);

    Texture2D background_tex = LoadTexture(BACKGROUNDTEXPATH);

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(LIME);

            DrawBackground(background_tex);
            DrawTitle();
            
            DrawHand(hand);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}