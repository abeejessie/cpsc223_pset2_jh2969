#include <stddef.h>
#include <stdbool.h>
#include "life.h"

bool isAlive(int array[], size_t index, size_t size) {
    return array[index] == 1;
}

bool shouldDie(int array[], size_t index, size_t size) {
    int live_neighbors = 0;

    // Check left neighbor
    if (index > 0) {
        live_neighbors += array[index - 1];
    }

    // Check right neighbor
    if (index < size - 1) {
        live_neighbors += array[index + 1];
    }

    if (array[index] == 1) {
        return live_neighbors == 2;
    } else {
        return false;
    }
}
