#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: Hash table.
 * @key: Key in key/value pair.
 *
 * Return: Value associated with the element, else NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
    hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	new_node = ht->array[index];
	while (new_node && strcmp(new_node->key, key) != 0)
		new_node = new_node->next;

	return ((new_node == NULL) ? NULL : new_node->value);
}
