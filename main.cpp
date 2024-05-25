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

    for(int i = -2; i <= 5; i++) {
        deck.push_back(LoadCard(i));
    }

    Texture2D background_tex = LoadTexture(BACKGROUNDTEXPATH);

    InitAudioDevice();

    Sound select_sound_effect = LoadSound("./audio/select-sound-effect.mp3");
    SetSoundVolume(select_sound_effect, 0.5f);
    SetSoundPan(select_sound_effect, 1.0f);

    while(!IsSoundReady(select_sound_effect)) {

    }

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_SPACE)) deck.push_back(LoadCard(rand() % (SKIP + YELLOW_OFFSET)));
        BeginDrawing();
            ClearBackground(LIME);

            DrawBackground(background_tex);
            DrawTitle();
            
            Vector2 selected_card = DrawHandAndCheckCollisions(deck);
            DrawText(TextFormat("id: %02d idx: %02d", (int) selected_card.x, (int) selected_card.y), 10, 10, 20, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && selected_card.x != -10 && selected_card.y != -10) {
                Card c = LoadCard((int) selected_card.x);
                play.push_back(c);
                PlaySound(select_sound_effect);
            }
            DrawPlayPile(play);
        EndDrawing();
    }

    #ifdef DEBUG
    printf("DEBUG: Test!\n");
    #endif

    UnloadSound(select_sound_effect);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}