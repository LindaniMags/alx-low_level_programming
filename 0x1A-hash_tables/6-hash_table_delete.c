#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: Hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *new_node, *pos;
    unsigned long int index;

    if(ht == NULL)
        return;

    for(index = 0; index < ht->size; index++)
    {
        if(ht->array[index] != NULL)
        {
            new_node = ht->array[index];
            while(new_node != NULL)
            {
                pos = new_node->next;
                free(new_node->key);
                free(new_node->value);
                free(new_node);
                new_node = pos;
            }
        }
    }
    free(ht->array);
    free(ht);
}
