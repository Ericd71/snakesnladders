#include <stdio.h>

#include "../headers/state.h"

/**
 * TODO (2nd submission): Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre: Having a structure type "State" with the fields "curr_pos", "game_finished" and "board". Also, having a structure "Board" to be able to initialize the "board" field in the "State" structure.
 * Post: Having initialized the 3 fields of the "State" structure mentioned in the pre condition ( current position set to 0, finished flag set to false and board set to *board).
 */
void init_state(State* state, Board* board) {
    state->curr_pos = 0;
    state->game_finished = FALSE;
    state->board = board;
}

/**
 * TODO (2nd submission): Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre: Having a structure type "State" with the field "curr_pos".
 * Post: Having set the field "curr_pos" to the value of the variable "position".
 */
void set_current_position(State* state, int position) {
    state->curr_pos = position;
}

/**
 * TODO (2nd submission): Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre: Having a structure type "State" with the field "curr_pos".
 * Post: Having returned the value of the field "curr_pos".
 */
int get_current_position(State* state) {
    return state->curr_pos;
}

/**
 * TODO (2nd submission): Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre: Having a structure type "State" with the field "game_finished"
 * Post: Having set the field "game_finished" to the value of the variable finished (which can be either TRUE or FALSE).
 */
void set_finished(State* state, int finished) {
    state->game_finished = finished;
}

/**
 * TODO (2nd submission): Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre: Having a structure type "State" with the field "game_finished"
 * Post: Having returned TRUE in case that's the value of "state->game_finished" or FALSE otherwise.
 */
int is_finished(State* state) {
    return state->game_finished;
}

/**
 * TODO (2nd submission): Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * tile containing a ladder or a snake, prints a message (You found a ladder/snake!) and updates the state's current
 * position accordingly. Also, sets the state as finished if it moves to or past the last tile.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre: Having a structure type "State" with the field "curr_pos"
 * Post: Having updated the state of the current position in function of the dice value and set the state to finished if the current position is equal or greater than the position of the last tile.
 */
void set_new_current_position(State* state, int position) {
    state->curr_pos += position;
}
int move(State* state, int dice_value) {
    set_new_current_position(state,dice_value);
    int size;
    size = state->board->rows * state->board->columns;
    if (state->curr_pos < size-1){
        Tile *tile;
        tile = get_tile_at(state->board,state->curr_pos);
        while (tile->target != EMPTY_TARGET && tile->target < size-1){
            if (tile->position < tile->target){
                printf("You found a ladder!!\n\r");
                set_current_position(state,tile->target);
            } else {
                printf("You found a snake !!\n\r");
                set_current_position(state,tile->target);
            }
            tile = get_tile_at(state->board,state->curr_pos);
        }
    } else {
        int flag;
        flag = TRUE;
        set_finished(state,flag);
    }
}


/**
 * TODO: Adds a step to the state's sequence, as the last step of it.
 *
 * Pre: state is not NULL
 * Post: Adds a step to the state's sequence, as the last step of it.
 */
void add_step(State* state, int dice_value) {
    int index = state->board->rows * state->board->columns - 1;
    state->board->tiles[index/state->board->columns][index % state->board->columns].position = dice_value;
}


/**
 * Prints the sequence of the state.
 * @param sequence The sequence to be shown.
 *
 * Pre:
 * Post:
 */
void print_state_sequence(State* state) {
    printf("Sequence: ");
    for (int i = 0; i < state->board->rows * state->board->columns; i++){
        printf("%d ", state->board->tiles[i /state->board->columns][i % state->board->columns].position);
    }
    printf("\n");
}


/**
 * Clear the state history and init the state again
 * @param state The current state to reset
 *
 * Pre: The state pointer is not NULL.
 * Post: The state's current position is set to 0, the game_finished flag is set to 0,
 *       and the board is reset to its initial configuration.
 */
void reset(State *state){
    if (state == NULL){
        printf("Error: state pointer is NULL\n");
        return;
    }
    // Reset current position and game_finished flag
    state->curr_pos = 0;
    state->game_finished = 0;

    // Reset board to initial configuration
    int tile_number = 1;
    for (int i = 0; i < state->board->rows; i++) {
        for (int j = 0; j < state->board->columns; j++) {
            state->board->tiles[i][j].position = tile_number++;
            state->board->tiles[i][j].target = -1; // assuming there are no snakes or ladders initially
        }
    }
}
