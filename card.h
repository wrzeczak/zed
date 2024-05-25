#pragma once

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum {
    WILD = -2,
    PLUS4 = -1,
    MYSTERY = 0,
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    RED_OFFSET = 0,
    BLUE_OFFSET = 12,
    GREEN_OFFSET = 24,
    YELLOW_OFFSET = 36,
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    PLUS2,
    REVERSE,
    SKIP
};

typedef struct {
    int id; // summation of enum values, ie. either -2, -1, 0, or card value (ONE) + offset value (RED_OFFSET)
    int position; // position in the hand, 1 if in a hand, 0 if in the draw pile, -1 if in the play pile (initialized as NULL)
    Texture2D tex; // the texture of the card, always 410x585 (initialized as 0)
    Vector3 transform; // x, y, and theta for random offsetting in a pile
} Card;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Card LoadCard(int id, int position = (int) NULL) {
    Card output = (Card) {
        id,
        position,
        0
    };

    char * path = (char *) malloc(64 * sizeof(char));

    // match the id with the filepath (WOW! list created using a snippet, not *entirely* manually)
    switch(id) {
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case -2: strncpy(path, "./cards/wild.png", 64); break;
        case -1: strncpy(path, "./cards/plus4.png", 64); break;
        case 0: strncpy(path, "./cards/mystery.png", 64); break;
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case ONE + RED_OFFSET: strncpy(path, "./cards/red-01.png", 64); break;
        case TWO + RED_OFFSET: strncpy(path, "./cards/red-02.png", 64); break;
        case THREE + RED_OFFSET: strncpy(path, "./cards/red-03.png", 64); break;
        case FOUR + RED_OFFSET: strncpy(path, "./cards/red-04.png", 64); break;
        case FIVE + RED_OFFSET: strncpy(path, "./cards/red-05.png", 64); break;
        case SIX + RED_OFFSET: strncpy(path, "./cards/red-06.png", 64); break;
        case SEVEN + RED_OFFSET: strncpy(path, "./cards/red-07.png", 64); break;
        case EIGHT + RED_OFFSET: strncpy(path, "./cards/red-08.png", 64); break;
        case NINE + RED_OFFSET: strncpy(path, "./cards/red-09.png", 64); break;
        case PLUS2 + RED_OFFSET: strncpy(path, "./cards/red-p2.png", 64); break;
        case REVERSE + RED_OFFSET: strncpy(path, "./cards/red-rv.png", 64); break;
        case SKIP + RED_OFFSET: strncpy(path, "./cards/red-sk.png", 64); break;
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case ONE + BLUE_OFFSET: strncpy(path, "./cards/blue-01.png", 64); break;
        case TWO + BLUE_OFFSET: strncpy(path, "./cards/blue-02.png", 64); break;
        case THREE + BLUE_OFFSET: strncpy(path, "./cards/blue-03.png", 64); break;
        case FOUR + BLUE_OFFSET: strncpy(path, "./cards/blue-04.png", 64); break;
        case FIVE + BLUE_OFFSET: strncpy(path, "./cards/blue-05.png", 64); break;
        case SIX + BLUE_OFFSET: strncpy(path, "./cards/blue-06.png", 64); break;
        case SEVEN + BLUE_OFFSET: strncpy(path, "./cards/blue-07.png", 64); break;
        case EIGHT + BLUE_OFFSET: strncpy(path, "./cards/blue-08.png", 64); break;
        case NINE + BLUE_OFFSET: strncpy(path, "./cards/blue-09.png", 64); break;
        case PLUS2 + BLUE_OFFSET: strncpy(path, "./cards/blue-p2.png", 64); break;
        case REVERSE + BLUE_OFFSET: strncpy(path, "./cards/blue-rv.png", 64); break;
        case SKIP + BLUE_OFFSET: strncpy(path, "./cards/blue-sk.png", 64); break;
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case ONE + GREEN_OFFSET: strncpy(path, "./cards/green-01.png", 64); break;
        case TWO + GREEN_OFFSET: strncpy(path, "./cards/green-02.png", 64); break;
        case THREE + GREEN_OFFSET: strncpy(path, "./cards/green-03.png", 64); break;
        case FOUR + GREEN_OFFSET: strncpy(path, "./cards/green-04.png", 64); break;
        case FIVE + GREEN_OFFSET: strncpy(path, "./cards/green-05.png", 64); break;
        case SIX + GREEN_OFFSET: strncpy(path, "./cards/green-06.png", 64); break;
        case SEVEN + GREEN_OFFSET: strncpy(path, "./cards/green-07.png", 64); break;
        case EIGHT + GREEN_OFFSET: strncpy(path, "./cards/green-08.png", 64); break;
        case NINE + GREEN_OFFSET: strncpy(path, "./cards/green-09.png", 64); break;
        case PLUS2 + GREEN_OFFSET: strncpy(path, "./cards/green-p2.png", 64); break;
        case REVERSE + GREEN_OFFSET: strncpy(path, "./cards/green-rv.png", 64); break;
        case SKIP + GREEN_OFFSET: strncpy(path, "./cards/green-sk.png", 64); break;
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case ONE + YELLOW_OFFSET: strncpy(path, "./cards/yellow-01.png", 64); break;
        case TWO + YELLOW_OFFSET: strncpy(path, "./cards/yellow-02.png", 64); break;
        case THREE + YELLOW_OFFSET: strncpy(path, "./cards/yellow-03.png", 64); break;
        case FOUR + YELLOW_OFFSET: strncpy(path, "./cards/yellow-04.png", 64); break;
        case FIVE + YELLOW_OFFSET: strncpy(path, "./cards/yellow-05.png", 64); break;
        case SIX + YELLOW_OFFSET: strncpy(path, "./cards/yellow-06.png", 64); break;
        case SEVEN + YELLOW_OFFSET: strncpy(path, "./cards/yellow-07.png", 64); break;
        case EIGHT + YELLOW_OFFSET: strncpy(path, "./cards/yellow-08.png", 64); break;
        case NINE + YELLOW_OFFSET: strncpy(path, "./cards/yellow-09.png", 64); break;
        case PLUS2 + YELLOW_OFFSET: strncpy(path, "./cards/yellow-p2.png", 64); break;
        case REVERSE + YELLOW_OFFSET: strncpy(path, "./cards/yellow-rv.png", 64); break;
        case SKIP + YELLOW_OFFSET: strncpy(path, "./cards/yellow-sk.png", 64); break;
        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        default: strncpy(path, "./cards/error.png", 64); break;
    }

    output.tex = LoadTexture(path);
    // SetTextureFilter(output.tex, TEXTURE_FILTER_TRILINEAR);

    free(path);

    return output;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef std::vector<Card> Deck;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

