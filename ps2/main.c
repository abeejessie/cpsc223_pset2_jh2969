#include <stdio.h>
#include <stdlib.h>
#include "life.h"
#include <string.h>
#include <math.h>


int main(int argc, char *argv[]) {
    // define arguments
    int time_steps = atoi(argv[1]);
    int game_size = atoi(argv[2]);
    char* start = argv[3];

    // turn "start" into array called "array"
    int len = strlen(start);
    int array[len]; 
    int next_array[len];
    
    for( int i = 0; i < len; i++) {
        if (start[i] == '0') {
           array[i] = 0;
           next_array[i] = 0;
        }
        else if (start[i] == '1') {
            array[i] = 1;
            next_array[i] = 1;
        }
    }
    // Print initial values
    printf("Initial values                   [");
    for ( int i = 0; i < len - 1; i++ ) {
        printf("%d, ", array[i]);
    }
    printf("%d]", array[len - 1]);
    // loop entire thing for time_steps
    for( int i = 0; i < time_steps; i++ ){
    // loop evaluate until game_size
        for ( int j = 0; j < game_size; j++ ) {
    // evaluate each item of "array" - check "is alive" and "should die" 
        if ( len == 1) {
            next_array[0] = array[0];
        }
        // first cell
        else if (j == 0) {
            if (array[0] == 1 && array[1] == 0) {
                next_array[1] = 1;
            }
        }
        // kill cells that should be killed
        else if ( shouldDie(array, j, len) ) {
            next_array[j] = 0;
        }
        //revive cells that should be revived
        else if ( isAlive(array, j, len) ) {
            if ( array[j-1] == 0|| array [j+1] == 0) {
                if ( array[j-1] == 0 ) {
                    next_array[j-1] = 1;
                }
                if ( array[j+1] == 0 ) {
                    next_array[j+1] = 1;
                }
            }
        }
        }
        // update array
        for( int k = 0; k < len ; k++ ){ 
        array[k] = next_array[k];
        }
        // Print each array after timestep i
        printf("\nValues after timestep %d",i+1);
        //whitespace counter 
        int time_step_digit = (int)floor(log10(i+1)+1);
        for( int k = 0; k < 11 - time_step_digit ; k++) {
            printf(" ");
        }
        printf("[");
        for ( int k = 0; k < len - 1; k++ ) {
        
            printf("%d, ", array[k]);
        }
        printf("%d]", array[len - 1]);
            
    }
    printf("\n");
    return 0;
}
