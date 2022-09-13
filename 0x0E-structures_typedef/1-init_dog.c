#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - a function that initializes a variable of type struct dog
 * @d: struct dog
 * @name: character string for name
 * @age: float for age
 * @owner: character string for owner 
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}