#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: Hash table.
 * @key: Key in key/value pair.
 * @value: Value in key/value pair.
 *
 * Return: 1 if it succeeded, else 0.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *pos;

	if (!ht || !key || !*key || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	pos = ht->array[index];
	while (pos)
	{
		if (!strcmp(pos->key, key))
		{
			free(pos->value);
			pos->value = strdup(value);
			return (1);
		}
		pos = pos->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
