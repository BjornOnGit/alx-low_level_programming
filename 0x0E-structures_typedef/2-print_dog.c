#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - create a function that prints the struct dog
 * @d: the dog struct
 */

void print_dog(struct dog *d)
{
    if (d != NULL)
    {
        printf("Name: %s\nAge: %2.2f\nOwner: %s\n", (*d).name != NULL ? d->name : "(nil)", (*d).age, (*d).owner != NULL ? d->owner : "(nil)");
    }  
}