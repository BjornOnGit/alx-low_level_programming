#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free dog - create a function that frees allocated space for dog
 * @d: dog struct
 */

void free_dog(dog_t *d)
{
    if (d == NULL)
    {
        return;
    }
    free(d->name);
    free(d->owner);
    free(d);
}