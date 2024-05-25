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

Vector2 DrawHandAndCheckCollisions(Deck d) {
    int count = d.size();

    int deck_width = count * TEXWIDTH * CARDSCALE * 0.5f;

    float tragedy_scaler = (deck_width < (WIDTH * 0.9f)) ? 1.0f : 0.75f;

    int offset = (WIDTH - tragedy_scaler * deck_width) / 2;
    int rotation_offset = -(count / 2);

    int output_id = -10;
    int output_index = -10;

    if(count % 2 != 0) {
        for(int i = 0; i < count; i++) {
            DrawTextureEx(d[i].tex, (Vector2) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler)}, .5f * ( rotation_offset + i ), CARDSCALE * tragedy_scaler, WHITE);
            if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler), TEXWIDTH * CARDSCALE * tragedy_scaler, TEXHEIGHT * CARDSCALE * tragedy_scaler})) { 
                output_id = d[i].id;
                output_index = i;
            }
        }
    } else {
        for(int i = 0; i < count / 2; i++) {
            DrawTextureEx(d[i].tex, (Vector2) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler)}, .5f * ( rotation_offset + i ), CARDSCALE * tragedy_scaler, WHITE);
            if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler), TEXWIDTH * CARDSCALE * tragedy_scaler, TEXHEIGHT * CARDSCALE * tragedy_scaler})) { 
                output_id = d[i].id;
                output_index = i;
            }
        }        
        for(int i = count / 2; i < count; i++) {
            DrawTextureEx(d[i].tex, (Vector2) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler)}, .5f * ( rotation_offset + i + 1 ), CARDSCALE * tragedy_scaler, WHITE);
            if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) { offset + (i * TEXWIDTH * CARDSCALE * 0.5f * tragedy_scaler ), HEIGHT - 1.25f * (TEXHEIGHT * CARDSCALE * tragedy_scaler), TEXWIDTH * CARDSCALE * tragedy_scaler, TEXHEIGHT * CARDSCALE * tragedy_scaler})) { 
                output_id = d[i].id;
                output_index = i;
            }
        }
    }

    return (Vector2) { (float) output_id, (float) output_index};
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void DrawPlayPile(Deck play) {
    Vector2 source = { (WIDTH - (TEXWIDTH * CARDSCALE)) / 2, 400 };
    if(play.size() > 0) {
        Card c = play[play.size() - 1];
        source.x += c.transform.x;
        source.y += c.transform.y;

        DrawTextureEx(c.tex, source, c.transform.z, CARDSCALE, WHITE);
    }
}