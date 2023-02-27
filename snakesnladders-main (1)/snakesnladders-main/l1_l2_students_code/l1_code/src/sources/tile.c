#include "../headers/tile.h"

/**
 * TODO (2nd submission): Initializes a tile, setting the position and initializing the target to EMPTY_TARGET.
 * @param tile The tile to be initialized.
 * @param position The position of the tile.
 *
 * Pre: To have tile (structure type "Tile") with, at least, the fields "position" (int) and "target" (int). Also, position must be >= 0
 * Post: Having set the fields "position" and "target" of the structure tile to the values of "position" and "EMPTY_TARGET" respectively.
 */
void init_tile(Tile* tile, int position) {
    tile->position = position;
    tile->target = EMPTY_TARGET;
}

/**
 * TODO (2nd submission): Returns the position of the tile.
 * @param tile The tile to be queried.
 * @return The position of the tile.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the field "position".
 * Post: Having returned the value of the field "position" of the tile structure
 */
int get_position(Tile* tile) {
    return (tile->position);
}

/**
 * TODO (2nd submission): Returns the position the tile targets to, if any.
 * @param tile The tile to be queried.
 * @return The position the tile targets or EMPTY_TARGET, if does not target another tile.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the field "target".
 * Post: Having returned the value of the field "target" of the tile structure in case its value is different than 0.
 */
int get_target_position(Tile* tile) {
    if (tile->target != 0){
        return tile->target;
    }
    else{
        return EMPTY_TARGET;
    }
}

/**
 * TODO (2nd submission): Sets the position the tile targets to.
 * @param tile The tile to be modified.
 * @return INVALID_POSITION if the target_position is less than 0, SUCCESS otherwise.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the field "target".
 * Post: Returning INVALID_POSITION in case target_position < 0 or SUCCESS otherwise.
 */
 int set_target_position(Tile* tile, int target_position) {
     if (target_position < 0) {
         return INVALID_POSITION;
     }
     else{
         tile->target = target_position;
         return SUCCESS;
     }
}

/**
 * TODO (2nd submission): Clears the tile target position, setting its value to EMPTY_TARGET.
 * @param tile The tile to be modified.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the field "target"
 * Post: Having set the value of the field "target" of the tile structure to EMPTY_TARGET.
 */
void clear_target_position(Tile* tile) {
    tile->target = EMPTY_TARGET;
}

/**
 * TODO (2nd submission): Returns TRUE if the tile contains a ladder (targets a higher tile).
 * @param tile The tile to be queried.
 * @return TRUE if the tile contains a ladder.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the fields "target" and "position".
 * Post: Having returned TRUE in case of the tile containing a ladder (target > position and target != EMPTY_TARGET) or FALSE otherwise.
 */
int is_ladder(Tile* tile) {
    if ((tile->target > tile->position) && (tile->target != EMPTY_TARGET)){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/**
 * TODO (2nd submission): Returns TRUE if the tile contains a snake (targets a lower tile), FALSE otherwise.
 * @param tile The tile to be queried.
 * @return TRUE if the tile contains a snake, FALSE otherwise.
 *
 * Pre: Having tile (Type structure "Tile") with, at least, the fields "target" and "position".
 * Post: Having returned TRUE in case of the tile containing a ladder (target < position and target != EMPTY_TARGET) or FALSE otherwise.
 */
int is_snake(Tile* tile) {
    if ((tile->target < tile->position) && (tile->target != EMPTY_TARGET))
        return TRUE;
    else{
        return FALSE;
    }
}
