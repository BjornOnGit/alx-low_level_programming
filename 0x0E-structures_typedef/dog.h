#ifndef DOG_H
#define DOG_H

/**
 * struct dog - the definition of a structure for a dog
 * @name: character string matching the name of a dog.
 * @age: float matching the age of a dog
 * @owner: character string matching the name of a dog's owner
 */

typedef struct dog
{
    char *name;
    float age;
    char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
int _strlen(char *s);
char *_strcopy(char *dest, char *src);
void free_dog(dog_t *d);

#endif