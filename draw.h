#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>

#include <raylib.h>

#include "config.h"
#include "card.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DrawBackground(Texture2D background_tex) {
    DrawTexture(background_tex, 0, 0, WHITE);
    /*
    Vector2 source = { 480, 580 };
    for(int i = 0; i < 30; i++) {
        DrawTextureV(decktop_tex, source, WHITE);
        source.y -= 2;
    }
    // this code ran once to render the cards, then i took a screenshot and replaced the background
    */
}

void DrawTitle() {
    int w = MeasureText(TITLE, 65);
    DrawRectangle(((WIDTH - w) / 2) - 30, 5, w + 60, 70, Fade(GRAY, 0.3f));
    DrawText(TITLE, ((WIDTH - w) / 2) + 2, 12, 65, BLACK);
    DrawText(TITLE, (WIDTH - w) / 2, 10, 65, WHITE);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DrawHand(Deck d) {
    int count = (int) d.size();

    int deck_width = count * TEXWIDTH * CARDSCALE * 0.5f;
    int offset = (WIDTH - deck_width) / 2;

    int rotation_offset = -(count / 2);

    if(count % 2 != 0) {
        for(int i = 0; i < count; i++) {
            DrawTextureEx(d[i].tex, (Vector2) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f ), HEIGHT - (TEXHEIGHT * CARDSCALE) - 5 * (10 - (int) abs(rotation_offset))}, .5f * ( rotation_offset + i ), CARDSCALE, WHITE);
        }
    }
}