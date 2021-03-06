#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a new tree
 * @parent:  pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent == NULL) /* Validate if there's no parent */
	{
		parent = newNode;
		newNode->parent = NULL;
		return (newNode);
	}
	if (parent->left == NULL) /* Check if left child has parent */
	{
		newNode->parent = parent;
		parent->left = newNode;
		return (newNode);
	}
	/*If the left parent is not null, add parent to right*/
	newNode->parent = parent;
	parent->right = newNode;
	return (newNode);
}
