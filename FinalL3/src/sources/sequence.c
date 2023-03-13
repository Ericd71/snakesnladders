#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * TODO: Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre: Having a structure type Sequence with fields "first_step", "last_step" and "size".
 * Post: Having set "first_set" and "last_set" to NULL and "size" to 0 (Having initialized the structure type Sequence).
 */
Step * init_sequence(Sequence* sequence) {
    sequence->first_step = NULL;
    sequence->last_step = NULL;
    sequence->size = 0;
    return 0;
}

/**
 * TODO: Adds a step, creating it if needed, as the first step of the sequence.
 *
 * Pre: Having a structure type Sequence with fields "first_step", "last_step" and "size" and another structure type
 *      Step with fields "dice_value" "res_pos" and "next_step". Also having the variables type int "position" and "dice_value".
 * Post: Having added a step as the "first_step". That is, in case there wasn't a first step (empty sequence of steps)
 *       having created a new step and set it as the "first_step" and "last_step" at the same time since it's the only step in the
 *       sequence. And, in case there already existed a first step, having created a new step
 *       and set it as the first one while setting the previous first step as the new first step's "next_step"
 *       (previous "first_step" -> second step).
 *       Also, having increased the size of the sequence by one since a new step has been added.
 */
void add_step_as_first(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*) malloc (sizeof(Step));
    step->dice_value = dice_value;
    step->res_pos = position;
    step->next_step = NULL;
    if (sequence->first_step == NULL){
        sequence->first_step = step;
        sequence->last_step = step;
    }
    else{
        step->next_step = sequence->first_step;
        sequence->first_step = step;
    }
    sequence->size ++;
}

/**
 * TODO: Adds a step, creating it if needed, as the last step of the sequence.
 *
 * Pre: Having a structure type Sequence with fields "first_step", "last_step" and "size" and another structure type
 *      Step with fields "dice_value" "res_pos" and "next_step". Also having the variables type int "position" and "dice_value".
 * Post: Having added a step as the "last_step". That is, if the sequence of steps was empty ("first_step" == NULL), having
 *       created a new step and set it as the "first_step" and "last_step" at the same time since it's the only step in the sequence.
 *       And, in case there already existed a first step, having created a new step, set it as the last step's next step and as
 *       the new last step. (Previous "last_step" -> penultimate step so its "next_step" is the new step. And the new step is now
 *       the "last_step").
 *       Also, having increased the size of the sequence by one since a new step has been added.
 */
void add_step_as_last(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*)malloc(sizeof(Step));
    step->dice_value = dice_value;
    step->res_pos = position;
    step->next_step = NULL;
    if (sequence->first_step == NULL){
        sequence->first_step = step;
        sequence->last_step = step;
    }
    else{
        sequence->last_step->next_step = step;
        sequence->last_step = step;
    }
    sequence->size++;
}

/**
 * TODO: Returns the number of steps stored in the sequence.
 *
 * Pre: Having a structure type Sequence with field "size".
 * Post: Having returned the size of the sequence.
 */
int get_sequence_size(Sequence* sequence) {
    return sequence->size;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre:  Having a structure type Sequence with field "first_step" and a structure Step with the field "next_step".
 * Post: Having freed each step of the sequence and initialized a new one in case the initial sequence wasn't empty. In case the sequence was empty,
 *       directly having initialized a new one.
 */
 void clear_sequence(Sequence* sequence) {
    Step* tmp = sequence->first_step; //Check if it's correct
    while (tmp != NULL){
        sequence->first_step = sequence->first_step->next_step;
        free(tmp);
        tmp = sequence->first_step;
    }
    init_sequence(sequence);
}

/**
 * Prints the sequence of moves leading to the state.
 * @param sequence The sequence to be shown.
 *
 * Pre: Having a structure type Sequence with field "first_step" and a structure Step with the field "next_step", "dice_value" and "res_pos".
 * Post: Having printed the dice value and the resulting position of each step in the sequence.
 */
void print_sequence(Sequence* sequence) {
    Step* current_step = sequence->first_step;
    while (current_step != NULL){
        printf("Dice value: %d, Resulting position: %d\n", current_step->dice_value, current_step->res_pos);
        current_step = current_step->next_step;
    }
}
