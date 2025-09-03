typedef struct Node
{
	int	a;
	struct Node *next;
}Node;

#include <stdlib.h>
Node	*create_node(int x)
{
	Node	*newNode;

	newNode = malloc(sizeof(Node));
	if (newNode == NULL)
		return (NULL);
	newNode ->a = x;	//新しく作った構造体newnodeのint型のメンバaにパラメータxを代入
	newNode ->next = NULL;	//nextを初期化
	return (newNode);
}

Node	*add_to_end(Node *head, int x)
{
	Node	*nextNode;
	Node	*current;

	nextNode = create_node(x);
	if (head == NULL)  //先頭がNULLの場合（リストが空の場合）、新しいノードをそのまま返して新しいリストになる
		return (nextNode);

	current = head;

	while (current ->next != NULL)
		current = current ->next;  //nextがNULLになるまで回して終端を探し、見つけたらそのノードのnextに新しいものを連結
	current ->next = nextNode;
	return (head);
}

#include <stdio.h>
void	print_list(Node *head)
{
	Node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d", current ->a);
		if (current ->next != NULL)
			printf(" -> ");
		current = current ->next;
	}
	printf("\n");
}

Node	*add_to_front(Node *head, int x)
{
	Node	*newnode;

	newnode = create_node(x);
	newnode ->next = head;
	return (newnode);
}

int main()
{
	Node *head = NULL;  // 空のリストで開始
    
	printf("5を追加:\n");
	head = add_to_end(head, 5);
	print_list(head);
    
	printf("3を追加:\n");
	head = add_to_end(head, 3);
	print_list(head);
    
	printf("8を追加:\n");
	head = add_to_end(head, 8);
	print_list(head);

	return 0;
}
