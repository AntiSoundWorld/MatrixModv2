#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
	int id;
	int value;
	struct Node* down;
	struct Node* right;
	struct Node* left;
	struct Node* up;
}node_t;

void CreateMatrix(node_t* head, int rows, int columns);
void ShowMatrix(node_t* head);
void LinkAdresses(node_t* head);
void MoveSnake(node_t* head,int rows, int columns);

void CreateMatrix(node_t* head, int rows, int columns)
{
	if (rows == 0 || columns == 0)
	{
		printf("Ne Baluysya");
		return;
	}

	head->down = NULL;
	head->right = NULL;
	head->left = NULL;
	head->up = NULL;

	node_t* pointer = head;
	node_t* pointerRight = pointer;
	int id = 0;

	printf("insert numbers \n");
	for (int i = 0; i != rows; i++)
	{
		pointer->id = id;
		id++;

		pointer->value;
		scanf("%d", &pointer->value);
		pointerRight->left = head;

		for (int j = 1; j != columns ; j++)
		{
			pointerRight->right = (node_t*)malloc(sizeof(node_t));
			pointerRight->right->id = id;
			pointerRight->right->value;
			scanf("%d", &pointerRight->right->value);
			pointerRight->right->right = NULL;
			pointerRight = pointerRight->right;
			id++;
		}
		pointer->down = (node_t*)malloc(sizeof(node_t));
		pointer->down->down = NULL;
		pointer = pointer->down;
		pointerRight = pointer;
	}
	LinkAdresses(head);
}

void LinkAdresses(node_t* head)
{
	node_t* pointerDown = head;
	node_t* pointer = pointerDown;
	node_t* pointer2 = pointerDown->down;
	int i = 0;

	while (pointerDown->down->down != NULL)
	{
		while (pointer != NULL)
		{
			pointer->down = pointer2;
			pointer2->up = pointer;
			if (pointer->right != NULL)
			{
				pointer->right->left = pointer;
				pointer2->right->left = pointer2;
			}
			pointer = pointer->right; 
			pointer2 = pointer2->right;
		}
		pointerDown = pointerDown->down;
		pointer = pointerDown;
		pointer2 = pointer->down;
	}
}

void ShowMatrix(node_t* head)
{
	node_t* pointer = head;
	node_t* pointer2 = pointer;
	while (pointer->down != NULL)
	{
		while (pointer2 != NULL)
		{
			printf("%d",pointer2->value);
			pointer2 = pointer2->right;
		}
		pointer = pointer->down;
		pointer2 = pointer;
		printf("\n");
	}
}

void MoveSnake(node_t* head, int rows, int columns )
{
	node_t* pointer = head;
	node_t* pointer2 = pointer;
	node_t* center = pointer2;
	int intCenter = rows * columns / 2 ;

	while (pointer->down != NULL)
	{
		while (pointer2!= NULL)
		{
			if (pointer2->id == intCenter)
			{
				center = pointer2;
			}
			pointer2 = pointer2->right;
		}
		pointer = pointer->down;
		pointer2 = pointer;
		printf("\n");
	}
	int step = 1;
	int right = 1;
	int down = 1;
	int left = 2;
	int up = 2;
	int fullSteps = rows * columns;
	

	printf("[%d]", center->value);
	while (1)
	{
		for (int i = 0; i < right; i++)
		{
			if (step == fullSteps )
			{
				return;
			}
			if (center->right == NULL)
			{
				break;
			}
			center = center->right;
			printf("[%d]", center->value);
			step++;
		}
		right = right + 2;
		
		for (int i = 0; i < down; i++)
		{
			if (step == fullSteps)
			{
				return;
			}
			if (center->down == NULL)
			{
				break;
			}
			center = center->down;
			printf("[%d]", center->value);
			step++;
		}
		down = down + 2;
		
		for (int i = 0; i < left; i++)
		{
			if (step == fullSteps)
			{
				return;
			}
			if (center->left == NULL)
			{
				break;
			}
			center = center->left;
			printf("[%d]", center->value);
			step++;
		}
		left = left + 2;

		for (int i = 0; i < up; i++)
		{
			if (step == fullSteps)
			{
				return;
			}
			if (center->up == NULL)
			{
				break;
			}
			center = center->up;
			printf("[%d]", center->value);
			step++;
		}
		up = up + 2;
	}
}
int main()
{
	int Rows;
	printf("Enter Rows \n");
	scanf("%d", &Rows);

	int Columns;
	printf("Enter Columns \n");
	scanf("%d", &Columns);
	
	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	
	CreateMatrix(head, Rows, Columns);
	ShowMatrix(head);
	MoveSnake(head, Rows, Columns);
}

