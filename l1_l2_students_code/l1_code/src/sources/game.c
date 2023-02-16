#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../headers/game.h"
#include "../headers/utils.h"
#include "../headers/state.h"
#include "../headers/board_utils.h"

#define MAX_ITERATIONS 1000

char show_game_options() {

    char option = read_char_option("Press T for throwing the dice, Q for quit\n");
    return option;
}

int throw_dice() {
    int value = (rand() % 6) + 1;

    printf("Dice roll... %d!\n", value);
    
    return value;
}

void start_game(Board *board) {

    State state;
    init_state(&state, board);

    int quit = FALSE;
    printf("Starting game...\n\n");
    while (quit == FALSE) {

        int current_position = get_current_position(&state);

        draw_zigzag_board(stdout, board, current_position);
        char option = show_game_options();

        if (option == THROW_DICE) {
            int dice_value = throw_dice();

            move(&state, dice_value);
            if (is_finished(&state) == TRUE) {
                quit = TRUE;
            }

        } else if (option == QUIT) {
            quit = TRUE;

        } else {
            printf("Invalid option! Try again...\n");
        }
    }

    if (is_finished(&state) == TRUE) {
        int current_position = get_current_position(&state);
        draw_zigzag_board(stdout, board, current_position);
        printf("You won!\n");
    }
}

void solve(Board *board) {
}
