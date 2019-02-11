#include <stdio.h>
#include <stdlib.h>

#define M 8

int adjacancyMatrix[M][M] =
{
	{ 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 0, 0, 1, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0 }
};

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

typedef struct List
{
	Node* head;
	Node* tail;
	int size;
} List;

// 1. Depth-First Search

int pushStack(List *stack, int i)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->value = i;
	temp->next = stack->head;

	stack->head = temp;
	stack->size++;

	return 1;
}

int popStack(List* stack)
{
	if (stack->size == 0)
	{
		return '-1';
	}

	Node* current = stack->head;
	int result = current->value;
	stack->head = current->next;
	free(current);
	stack->size--;

	return result;
}

void dfs(int source, int visited[M], List* list)
{
	if (list->size == 0)
		return;

	visited[source] = 1;
	printf("\nVisiting %d", source);

	for (int j = 0; j < M; j++)
	{
		if (adjacancyMatrix[source][j] == 1 && visited[j] == 0)
		{
			pushStack(list, j);
			dfs(j, visited, list);
		}
	}

	popStack(list);
}

// 2. Breadth-First Search

int enqueue(List* queue, int c)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
		return 0;

	temp->next = NULL;
	temp->value = c;

	if (queue->size == 0)
	{
		queue->head = temp;
		queue->tail = temp;
	}

	queue->tail->next = temp;
	queue->tail = temp;
	queue->size++;

	return 1;
}

int dequeue(List* queue)
{
	if (queue->size <= 0)
		return '-1';

	Node* temp = queue->head;
	int result = temp->value;
	queue->head = temp->next;
	free(temp);
	queue->size--;

	return result;
}

void bfs(int source)
{
	int visited[M];
	for (int i = 0; i < M; i++)
		visited[i] = 0;

	List list;
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;

	enqueue(&list, source);
	visited[source] = 1;

	while (list.size != 0)
	{
		int current = dequeue(&list);
		printf("\nVisiting %d", current);

		for (int j = 0; j < M; j++)
		{
			if (adjacancyMatrix[current][j] != 0 && visited[j] == 0)
			{
				enqueue(&list, j);
				visited[j] = 1;
			}
		}
	}
}

int main()
{
	// 1
	List list;
	list.size = 0;
	list.head = NULL;

	int source = 0;
	pushStack(&list, source);

	int visited[M];
	for (int i = 0; i < M; i++)
		visited[i] = 0;

	printf("\n1) DFS: ");
	dfs(source, visited, &list);

	// 2
	printf("\n\n2) BFS: ");
	bfs(0);

	return 0;
}