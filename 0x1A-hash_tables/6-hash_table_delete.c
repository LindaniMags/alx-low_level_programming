#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: Hash table.
 */

void hash_table_delete(hash_table_t *ht)
{
    hash_table_t *head = ht;
    hash_node_t *node, *pos;
    unsigned long int index;

    for (index = 0; index < ht->size; index++)
    {
        if (ht->array[index] != NULL)
        {
            node = ht->array[index];
            while (node != NULL)
            {
                pos = node->next;
                free(node->key);
                free(node->value);
                free(node);
                node = pos;
            }
        }
    }
    free(head->array);
    free(head);
}
