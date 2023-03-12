#include <stdlib.h>

#include "../headers/board.h"

/**
 * TODO: Initializes the board, initializing also each tile of it.
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 *
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
 * Pre: Having a structure "Board" with fields "rows"(int),"columns"(int) and "tiles"(matrix type Tile) of size
 *      MAX_ROWS * MAX_COLUMNS. Also, having a structure "Tile" in order to create the field "tiles" in "Board".
 *      Finally, having a function init_tile.
 * Post: Returning the integer INVALID_BOARD_DIMENSIONS (-1) and having the board and the tiles initialized.
 */
int init_board(Board* board, int rows, int columns) {
    if (rows < 1 || rows > MAX_ROWS || columns < 2 || columns>MAX_COLUMNS){
        return ERROR;
    } else{
        set_rows(board,rows);
        set_columns(board,columns);
        int i, j, pos;
        Tile *tile;
        for (i=0; i<MAX_ROWS; i++){
            for(j=0; j<MAX_COLUMNS;j++){
                tile = &board->tiles[i][j];
                clear_target_position(tile);
                if (i < rows && j < columns){
                    pos = j + i*columns;
                    // move from to left to right if row is even
                    if (i % 2 == 0){
                        init_tile(tile,pos);
                    } else {
                        tile = &board->tiles[i][columns -1 - j];
                        init_tile(tile,pos);
                    }
                }
            }
        }
        return SUCCESS;
    }
}

/**
 * TODO (2nd submission): Returns the number of rows of the board.
 * @param board The board to be queried.
 * @return The number of rows of the board.
 *
 * Pre: Having board structure type "Board" with, at least, the field "rows" (int).
 * Post: Returning the field "rows" (int) of the given structure.
 */
int get_rows(Board* board) {
    return (board->rows);
}

/**
 * TODO (2nd submission): Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre: Having board (Type structure "Board") with, at least, the field "rows" (int).
 * Post: Having set the field "rows" of board to the variable "rows" (int).
 */
void set_rows(Board* board, int rows) {
    board->rows = rows;
}

/**
 * TODO (2nd submission): Returns the number of columns of the board.
 * @param board The board to be queried.
 * @return The number of columns of the board.
 *
 * Pre: Having board structure type "Board" with, at least, the field "columns" (int).
 * Post: Returning the field "columns" (int) of the given structure.
 */
int get_columns(Board* board) {
    return (board->columns);
}

/**
 * TODO (2nd submission): Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre: Having board (Type structure "Board") with, at least, the field "columns" (int).
 * Post: Having set the field "columns" of board to the variable "columns" (int).
 */
void set_columns(Board* board, int columns) {
    board->columns = columns;
}

/**
 * TODO (2nd submission): Returns the size of the board, it is, the total number of tiles.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre: Having board (structure type "Board") with a field "rows" (int) and a field "columns" (int), and
 *      having the functions get_rows(board) and get_columns(board).
 * Post: Returning the size of the board (number of tiles). That is the result of the multiplication
 *       of get_rows(board) times get_columns(board).
 */
int get_size(Board* board) {
    return board->rows * board->columns;
}

/**
 * TODO (2nd submission): Returns the board tile at the specific position.
 *
 * @param board The board from which the tile should be retrieved.
 * @param position The position of the tile.
 * @return The (reference to the) tile of the board corresponding to the position if valid, NULL otherwise.
 * Pre: Having board (Type structure "Board") with, at least, the field "tiles" (matrix type "Tile").
 *      Having an integer "position" with value between 1 and the board's size, the size included.
 *      Also, having the function get_columns(board) previously defined.
 * Post: Returning a pointer to the tile (Tile*) if the position is valid. Otherwise, returning NULL.
 */
Tile* get_tile_at(Board *board, int position) {
    int row = position / get_columns(board);
    int col = position % get_columns(board);
    return &(board->tiles[row][col]);
}
