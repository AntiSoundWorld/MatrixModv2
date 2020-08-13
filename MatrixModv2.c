#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int value;
    struct Node* nextRows;
    struct Node* nextColumns;
}node_t;

void CreateMatrix(node_t*  head, int rows, int columns);
void ShowMatrix(node_t* head, int columns);

void CreateMatrix(node_t* head, int rows, int columns)
{
	if(rows == 0 || columns == 0)
	{
		printf("Ne Baluysya");
		return;
	}

    head->nextRows = NULL;
    head->nextColumns = NULL;
	
    node_t* pointerRows = head;
    node_t* pointerColumns = pointerRows;

    printf("insert numbers \n");
	for (int i = 0; i != rows; i++)
	{
		pointerRows->value;
		scanf("%d", &pointerRows->value);
		for (int j = 0; j != columns - 1; j++)
		{
			pointerColumns->nextColumns = (node_t*)malloc(sizeof(node_t));
			pointerColumns->nextColumns->value;
			scanf("%d", &pointerColumns->nextColumns->value);
			pointerColumns->nextColumns->nextColumns = NULL;
			pointerColumns = pointerColumns->nextColumns;
		}
		pointerRows->nextRows = (node_t*)malloc(sizeof(node_t));
		pointerRows->nextRows->nextRows = NULL;
		pointerRows = pointerRows->nextRows;
		pointerColumns = pointerRows;
	}
}

void ShowMatrix(node_t * head,int columns)
{
	node_t * pointerRows = head;
	node_t * pointerColumns = pointerRows;
	
	int j = 0;
	while(pointerRows->nextRows != NULL)
	{
		int i = j;
		printf("%d ", pointerRows->value);
		pointerRows = pointerRows->nextRows;
		
		while(i != columns -1)
		{
			printf("%d ", pointerColumns->nextColumns->value);
			pointerColumns = pointerColumns->nextColumns;
			i++;
		}
		printf("\n");
		pointerColumns = pointerRows;
		j++;
	}
}
int main()
{
	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));

	int quantityOfRows;
	printf("Enter quantityOfRows \n");
	scanf("%d", &quantityOfRows);

	int quantityOfColumns;
	printf("Enter quantityOfColumns \n");
	scanf("%d", &quantityOfColumns);

	CreateMatrix(head, quantityOfRows, quantityOfColumns);
	ShowMatrix(head, quantityOfColumns);
}

