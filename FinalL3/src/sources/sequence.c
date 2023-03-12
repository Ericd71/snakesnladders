#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * TODO: Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre:
 * Post:
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
 * Pre:
 * Post:
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
 * Pre:
 * Post:
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
 * Pre:
 * Post:
 */
int get_sequence_size(Sequence* sequence) {
    return sequence->size;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre:
 * Post:
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
 * Pre:
 * Post:
 */
void print_sequence(Sequence* sequence) {
    Step* current_step = sequence->first_step;
    while (current_step != NULL){
        printf("Dice vale: %d, Resulting position: %d\n", current_step->dice_value, current_step->res_pos);
        current_step = current_step->next_step;
    }
}
