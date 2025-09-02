typedef struct Node
{
	int	a;
	struct Node *next;
}Node;

#include <stdlib.h>
Node	*create_node(int a)
{
	
