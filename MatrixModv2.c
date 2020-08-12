#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int value;
    struct Node* nextRows;
    struct Node* nextColumns;

}node_t;

void CreateMatrix(int rows, int columns);
void ShowMatrix(node_t* head);

void CreateMatrix(int rows, int columns)
{
    node_t* head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
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
    ShowMatrix(head);
}

void ShowMatrix(node_t * head)
{
	node_t * pointerRows = head;
	node_t * pointerColumns = pointerRows;
	
	while(pointerRows->nextRows != NULL)
	{
		printf("%d ", pointerRows->value);
		pointerRows = pointerRows->nextRows;
	
		while(pointerColumns->nextColumns != NULL)
		{
			printf("%d ", pointerColumns->nextColumns->value);
			pointerColumns = pointerColumns->nextColumns;
		}
		printf("\n");
		pointerColumns = pointerRows;
	}
}
int main()
{
    int quantityOfRows;
    printf("Enter quantityOfRows \n");
    scanf("%d", &quantityOfRows);

    int quantityOfСolumns;
    printf("Enter quantityOfСolumns \n");
    scanf("%d", &quantityOfСolumns);

    CreateMatrix(quantityOfRows, quantityOfСolumns);
}

