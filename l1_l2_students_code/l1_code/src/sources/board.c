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
        init_tile(&board->tiles[rows][columns], pos);
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
}

/**
 * TODO (2nd submission): Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre: The board is not NULL and rows is bigger than 0
 * Post: The numbers of rows of board
 */
void set_rows(Board* board, int rows) {
    board->rows = rows;
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
}

/**
 * TODO (2nd submission): Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre:
 * Post:
 */
void set_columns(Board* board, int columns) {
    board->columns = columns;
}

/**
 * TODO (2nd submission): Returns the size of the board, it is, the total number of tiles.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre:
 * Post:
 */
int get_size(Board* board) {
    return (get_rows(board) * get_columns((board)));
}

/**
 * TODO (2nd submission): Returns the board tile at the specific position.
 *
 * @param board The board from which the tile should be retrieved.
 * @param position The position of the tile.
 * @return The (reference to the) tile of the board corresponding to the position if valid, NULL otherwise.
 * Pre: The board is not NULL. The position is between 1 and the board's size, the size included.
 * Post: It will return a pointer to the tile (Tile*) if the position is valid, it will return NULL otherwise.
 */
Tile* get_tile_at(Board *board, int position) {
    int row = position / get_columns(board);
    int col = position % get_columns(board);
    return &(board->tiles[row][col]);
}
