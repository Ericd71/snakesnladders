#include <stdlib.h>

#include "../headers/board.h"

/**
 * TODO (2nd submission): Initializes the board, initializing also each tile of it.
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 *
 * Pre:
 * Post:
 */
int init_board(Board* board, int rows, int columns) {
    struct Board;
    if ((rows < MAX_ROWS) || (columns < MAX_COLUMNS)){
        if ((rows < 1) || (columns < 2)){
            board->rows = rows;
            board->columns = columns;
        }
    }
    int pos = 0;
    while (pos < rows * columns) {
        init_tile(&board->tiles[rows][columns], pos)
    }
    return INVALID_BOARD_DIMENSIONS;
}

/**
 * TODO (2nd submission): Returns the number of rows of the board.
 * @param board The board to be queried.
 * @return The number of rows of the board.
 *
 * Pre:
 * Post:
 */
int get_rows(Board* board) {
    return (board->rows);
    return ERROR;
}

/**
 * TODO (2nd submission): Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_rows(Board* board, int rows) {
}

/**
 * TODO (2nd submission): Returns the number of columns of the board.
 * @param board The board to be queried.
 * @return The number of columns of the board.
 *
 * Pre:
 * Post:
 */
int get_columns(Board* board) {
    return (board->columns);
    return ERROR;
}

/**
 * TODO (2nd submission): Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_columns(Board* board, int columns) {
}

/**
 * TODO (2nd submission): Returns the size of the board, it is, the total number of tiles.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre:
 * Post:
 */
int get_size(Board* board) { // check if it's okay
    return get_rows(board) + get_columns((board));
    return ERROR;
}

/**
 * TODO (2nd submission): Returns the board tile at the specific position.
 *
 * @param board The board from which the tile should be retrieved.
 * @param position The position of the tile.
 * @return The (reference to the) tile of the board corresponding to the position if valid, NULL otherwise.
 *
 * Pre:
 * Post:
 */
Tile* get_tile_at(Board *board, int position) {
    return NULL;
}
