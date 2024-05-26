#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <vector>

#include <raylib.h>

#include "config.h"
#include "card.h"
#include "draw.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(void) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIDTH, HEIGHT, TITLE);

    SetTargetFPS(2 * GetMonitorRefreshRate(GetCurrentMonitor()));
    ToggleFullscreen();

    srand(time(NULL));

    Deck deck;
    Deck play;
    Deck hand;

    for(int i = 0; i < 7; i++) {
        hand.push_back(RandomCard());
    }

    play.push_back(RandomCard());

    Texture2D background_tex = LoadTexture(BACKGROUNDTEXPATH);

    InitAudioDevice();

    Sound select_sound_effect = LoadSound("./audio/select-sound-effect.mp3");
    SetSoundVolume(select_sound_effect, 0.5f);
    SetSoundPan(select_sound_effect, 1.0f);

    // wait for the sound to be ready
    while(!IsSoundReady(select_sound_effect)) {
        continue;
    }

    while(!WindowShouldClose()) {
        if(IsKeyPressed(KEY_SPACE)) hand.push_back(RandomCard());

        BeginDrawing();
            ClearBackground(LIME);

            DrawBackground(background_tex);
            DrawTitle();
            
            select_return_t select = DrawHandAndCheckCollisions(hand);
            DrawText(TextFormat("id: %02d idx: %02d", (int) select.id, (int) select.idx), 10, 10, 20, WHITE);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && select.id != -10 && select.idx != -10) {
                Card t = play[play.size() - 1]; // there has got to be a C++-ussy way to do this...
                Card c = hand[select.idx];
                if(!(SameColor(t, c) || SameValue(t, c))) goto __card_is_not_playable_and_that_is_really_really_rather_sad;
                #ifdef DEBUG
                printf("DEBUG: ID: %02d IDX: %02d LEN: %02d\n", (int) select.id, (int) select.idx, (int) hand.size());
                #endif

                
                c.transform.x += (rand() % 20) - 10;
                c.transform.y += (rand() % 50) - 25;
                c.transform.z += (rand() % 30) - 15;

                #ifdef DEBUG
                printf("DEBUG: C TRANSFORM %02d, %02d, %02d.\n", (int) c.transform.x, (int) c.transform.y, (int) c.transform.z);
                #endif

                play.push_back(c);
                PlaySound(select_sound_effect);

                hand.erase(hand.begin() + (int) select.idx);
            }
            __card_is_not_playable_and_that_is_really_really_rather_sad:
            DrawPlayPile(play);

            if((int) hand.size() == 1) DrawUno();

            const char * fps_text = TextFormat("%03d FPS", GetFPS());
            DrawText(fps_text, WIDTH - 10 - MeasureText(fps_text, 20), 10, 20, LIME);

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