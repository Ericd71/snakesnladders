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
    state->board = *board;
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
    if (state->curr_pos >= ){ //Acabar if. Es refereix a posició més gran o igual que la posició de l'últim tile
        finished = TRUE;
        state->game_finished = finished;
    }
    else if (state->curr_pos < ){ //Acabar else if. Es refereix a posició més petita que la posició de l'últim tile
        finished = FALSE;
        state->game_finished = finished;
    }
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
    if (state->game_finished == TRUE){
        return TRUE;
    }
    else{
        return FALSE;
    }
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
void move(State* state, int dice_value) {
    state->curr_pos = state->curr_pos + dice_value;
    if (state->curr_pos ){ // Acabar if. Intenta dir if curr_pos es troba en un tile amb ladder...
        printf("You found a ladder!");
        state->curr_pos = ; // trobar manera de settejar a la posició on porta la ladder
    }
    if (state->curr_pos ){ // Acabar if. Intenta dir if curr_pos es troba en un tile amb snake...
        printf("You found a snake!");
        state->curr_pos = ; // trobar manera de settejar a la posició on porta la snake
    }
    int finished;
    set_finished(state, finished);
}
