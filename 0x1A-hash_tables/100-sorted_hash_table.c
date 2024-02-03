#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: Size ofhash table.
 *
 * Return: Sorted hash table, else NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    unsigned long int i;
    shash_table_t *ht;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
        ht->array[i] = NULL;
    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: Hash table.
 * @key: Key in key/value pair.
 * @value: Value in key/value pair.
 *
 * Return: On success - 1, else 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    char *val;
    shash_node_t *new_node, *pos;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    val = strdup(value);
    if (val == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    pos = ht->shead;
    while (pos)
    {
        if (strcmp(pos->key, key) == 0)
        {
            free(pos->value);
            pos->value = val;
            return (1);
        }
        pos = pos->snext;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
    {
        free(val);
        return (0);
    }
    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(val);
        free(new_node);
        return (0);
    }
    new_node->value = val;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (ht->shead == NULL)
    {
        new_node->sprev = NULL;
        new_node->snext = NULL;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else if (strcmp(ht->shead->key, key) > 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        pos = ht->shead;
        while (pos->snext != NULL && strcmp(pos->snext->key, key) < 0)
            pos = pos->snext;
        new_node->sprev = pos;
        new_node->snext = pos->snext;
        if (pos->snext == NULL)
            ht->stail = new_node;
        else
            pos->snext->sprev = new_node;
        pos->snext = new_node;
    }

    return (1);
}

/**
 * shash_table_get - Retrieves the value.
 * @ht: A pointer to the sorted hash table.
 * @key: Key in key/value pair.
 *
 * Return: Value, else NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *current_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return (NULL);

    current_node = ht->shead;
    while (current_node != NULL && strcmp(current_node->key, key) != 0)
        current_node = current_node->snext;

    return ((current_node == NULL) ? NULL : current_node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: Hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current_node;

    if (ht == NULL)
        return;

    current_node = ht->shead;
    printf("{");
    while (current_node != NULL)
    {
        printf("'%s': '%s'", current_node->key, current_node->value);
        current_node = current_node->snext;
        if (current_node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: Hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current_node;

    if (ht == NULL)
        return;

    current_node = ht->stail;
    printf("{");
    while (current_node != NULL)
    {
        printf("'%s': '%s'", current_node->key, current_node->value);
        current_node = current_node->sprev;
        if (current_node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *current_node, *pos;
    shash_table_t *head = ht;

    if (ht == NULL)
        return;

    current_node = ht->shead;
    while (current_node)
    {
        pos = current_node->snext;
        free(current_node->key);
        free(current_node->value);
        free(current_node);
        current_node = pos;
    }

    free(head->array);
    free(head);
}
