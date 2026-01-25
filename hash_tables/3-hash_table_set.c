#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_value - updates an existing node's value
 * @node: node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
static int update_value(hash_node_t *node, const char *value)
{
	char *dup;

	dup = strdup(value);
	if (dup == NULL)
		return (0);

	free(node->value);
	node->value = dup;

	return (1);
}

/**
 * create_node - creates a new hash node
 * @key: key string
 * @value: value string
 *
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);

	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (NULL);
	}

	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key);
		free(new);
		return (NULL);
	}

	new->next = NULL;
	return (new);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: hash table
 * @key: key (cannot be empty)
 * @value: value to associate (can be empty)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *new;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return (0);
	if (key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node = ht->array[idx];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (update_value(node, value));
		node = node->next;
	}

	new = create_node(key, value);
	if (new == NULL)
		return (0);

	new->next = ht->array[idx];
	ht->array[idx] = new;

	return (1);
}
