#ifndef DOG_H
#define DOG_H

/**
 * struct dog - dog info
 * @name: First
 * @age: Second
 * @owner: Third
 *
 * Description: description
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog1 - typedef for struct dog
 */
typedef struct dog dog1;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog1 *new_dog(char *name, float age, char *owner);
void free_dog(dog1 *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
