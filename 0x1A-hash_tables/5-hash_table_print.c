#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: Hash table.
 *
 * Return: Prints hash table.
 */

void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *new_node;
    unsigned char position = 0;
    unsigned long int index;

    if (ht == NULL)
        return;

    printf("{");
    for (index = 0; index < ht->size; index++)
    {
        if (ht->array[index] != NULL)
        {
            if (position == 1)
                printf(", ");

            new_node = ht->array[index];
            while (new_node != NULL)
            {
                printf("'%s': '%s'", new_node->key, new_node->value);
                new_node = new_node->next;
                if (new_node != NULL)
                    printf(", ");
            }
            position = 1;
        }
    }
    printf("}\n");
}
