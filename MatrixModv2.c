#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

typedef struct Node
{
    int id;
    int value;
    bool point;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    struct Node* up;
}node_t;

void CreateMatrix(node_t* head, int rows, int columns)
{
	if (rows == 0)
	{
		printf("Ne Baluysya");
		return;
	}
	node_t* pointerRows = head;
	node_t* pointerColumns = pointerRows;

	for (int i = 0; i < rows  ; i++)
	{
		pointerRows->point = false;

		pointerRows->value;
		scanf("%d",&pointerRows->value);

		pointerRows->right = NULL;
		pointerRows->down = NULL;
		pointerRows->left = NULL;
		pointerRows->up = NULL;

		for (int j = 0; j < columns - 1; j++)
		{
			pointerColumns->right = (node_t*)malloc(sizeof(node_t));

			pointerColumns->right->value;

			scanf("%d",&pointerColumns->right->value);
			pointerColumns->right->point = false;

			pointerColumns->right->right = NULL;
			pointerColumns->right->down = NULL;
			pointerColumns->right->left = NULL;
			pointerColumns->right->up = NULL;

			pointerColumns = pointerColumns->right;
		}

		pointerRows->down = (node_t*)malloc(sizeof(node_t));

		pointerRows = pointerRows->down;
		pointerColumns = pointerRows;

		if(i == rows - 1)
		{
			pointerRows->down = NULL;
		}
	}
}
void LinkAdresses(node_t* head)
{
	node_t* pointerRows = head;
	node_t* pointerRows2 = pointerRows->down;
	node_t* pointerColumns = pointerRows;
	node_t* pointerColumns2 = pointerRows2;

	while(pointerRows2->down != NULL)
	{
		while(pointerColumns->right != NULL)
		{
			pointerColumns->right->left = pointerColumns;
			pointerColumns2->right->left = pointerColumns2;

			pointerColumns->right->down = pointerColumns2->right;
			pointerColumns2->right->up = pointerColumns->right;

			pointerColumns = pointerColumns->right;
			pointerColumns2 = pointerColumns2->right;
		}
		pointerRows2->up = pointerRows;

		pointerRows2 = pointerRows2->down;
		pointerRows = pointerRows->down;

		pointerColumns = pointerRows;
		pointerColumns2 = pointerRows2;
	}
}
void ShowMatrix(node_t * head)
{
	node_t* pointerRows = head;
	node_t* pointerColumns = pointerRows;

	printf("Your matrix \n");

	while(pointerRows->down != NULL)
	{
		while(pointerColumns != NULL)
		{
			printf("[%d]", pointerColumns->value);
			pointerColumns = pointerColumns->right;
		}
		pointerRows = pointerRows->down;
		pointerColumns = pointerRows;
		printf("\n");
	}
	printf("---------------------------------------- \n");
}
bool ParityDefinition(int rows, int columns)
{
	bool isMatrixEven = false;

	if (rows == 2 && columns == 2)
	{
		isMatrixEven = true;
	}
	if (rows == 3 && columns == 3)
	{
		isMatrixEven = false;
	}
	if (rows == 4 && columns == 4)
	{
		isMatrixEven = true;
	}
	if (rows == 5 && columns == 5)
	{
		isMatrixEven = false;
	}
	if (rows == 6 && columns == 6)
	{
		isMatrixEven = true;
	}
	if (rows == 7 && columns == 7)
	{
		isMatrixEven = false;
	}
	if (rows == 8 && columns == 8)
	{
		isMatrixEven = true;
	}
	return isMatrixEven;
}

node_t* FindStartItem(node_t* head, bool ParityDefinition, int rows, int columns)
{
    int editRows = 0;
    int editColumns = 0;

    node_t* pointer = head;

    if (ParityDefinition == true)
    {
        editRows = rows;
        editColumns = columns;

        for (int i = 1; i < editRows / 2; i++)
        {
            pointer = pointer->right;
            pointer = pointer->down;
        }
    }
    if (ParityDefinition == false)
    {
        editRows = rows - 1;
        editRows = columns - 1;

        for (int i = 1; i < editRows / 2 + 1; i++)
        {
            pointer = pointer->right;
            pointer = pointer->down;
        }
    }
	pointer->point = true;
    return pointer;
}

void LounchSnake(node_t* startItem)
{
	node_t* pointer = startItem;
	printf("Your Snake \n");
	pointer->point = true;
	printf("[%d]", pointer->value);
	pointer = pointer->right;
	
	while(true)
	{
		while(pointer->left->point == true)
		{
			pointer->point = true;
			printf("[%d]",pointer->value);
			pointer = pointer->down;
		}
		
		while(pointer->up->point == true)
		{
			pointer->point = true;
			printf("[%d]",pointer->value);
			if(pointer->left == NULL)
			{
				return;
			}
			pointer = pointer->left;
		}
		
		while(pointer->right->point == true)
		{
			pointer->point = true;
			printf("[%d]",pointer->value);
			pointer = pointer->up;
		}
		
		while(pointer->down->point == true)
		{
			pointer->point = true;
			printf("[%d]",pointer->value);
			if(pointer->right == NULL)
			{
				return;
			}
			pointer = pointer->right;
		}
	}
}

int main()
{
	printf("Enter quantity of rows \n");
	int rows;
	scanf("%d", &rows);

	printf("Enter quantity of columns \n");
	int columns;
	scanf("%d", &columns);

	printf("Enter values \n");

	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	CreateMatrix(head, rows, columns);

	ShowMatrix(head);
	LinkAdresses(head);

	LounchSnake(FindStartItem(head, ParityDefinition(rows, columns), rows, columns));
	return 0;
}

