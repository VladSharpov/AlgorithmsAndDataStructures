#include <stdio.h>
#include <stdlib.h>

// 1
#define MaxN 1000
int Stack[MaxN];
int N = -1;

void push(int i)
{
	if (N < MaxN - 1)
	{
		N++;
		Stack[N] = i;
	}
	else
		printf("\nStack overflow\n");
}

int pop()
{
	if (N > -1)
	{
		return Stack[N--];
	}
	else
	{
		printf("\nStack is empty\n");
		return -1;
	}
}

int DecimalToBinary(int dec)
{
	int binLength = 0;

	while (dec > 0)
	{
		push(dec % 2);
		binLength++;
		dec /= 2;
	}

	int bin = 0;

	while (binLength > 0)
	{
		bin = bin * 10 + pop();
		binLength--;
	}

	return bin;
}

// 2
typedef struct Node
{
	char value;
	struct Node* next;
} Node;

typedef struct List
{
	Node* head;
	Node* tail; // needed only for Queue
	int size;
} List;

int pushStack(List *stack, char i)
{
	Node *temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL) return 0;

	temp->value = i;
	temp->next = stack->head;

	stack->head = temp;
	stack->size++;

	return 1;
}

char popStack(List* stack)
{
	if (stack->size == 0)
	{
		return '-1';
	}

	Node* current = stack->head;
	char result = current->value;
	stack->head = current->next;
	free(current);
	stack->size--;

	return result;
}

int checkParentheses(List* stack)
{
	if (stack->size <= 0)
		return 0;

	int br = 0; // '(', ')'
	int curly = 0; // '{', '}'
	int square = 0; // '[', ']'

	while (stack->size > 0)
	{
		switch (popStack(stack))
		{
			case ')':
				br++;
				break;

			case '(':
				if (br == 0) return -1;
				br--;
				break;

			case '}':
				curly++;
				break;

			case '{':
				if (curly == 0) return -1;
				curly--;
				break;

			case ']':
				square++;
				break;

			case '[':
				if (square == 0) return -1;
				square--;
				break;
		}
	}

	if (br == 0 && curly == 0 && square == 0)
		return 1;
	else
		return -1;
}

//4
int Enqueue(List* queue, char c)
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

char Dequeue(List* queue)
{
	if (queue->size <= 0)
		return '-1';

	Node* temp = queue->head;
	char result = temp->value;
	queue->head = temp->next;
	free(temp);
	queue->size--;

	return result;
}

// 3
void printList(List* list)
{
	Node* current = list->head;

	while (current != NULL)
	{
		printf("%c", current->value);
		current = current->next;
	}
}

void copyList(List* list1, List* list2)
{
	Node* current = list1->head;

	while (current != NULL)
	{
		Enqueue(list2, current->value);
		current = current->next;
	}
}

int main()
{
	// 1
	int dec = 16;
	printf("1) %d in binary is %d\n", dec, DecimalToBinary(dec));
	
	// 2
	List stack;
	stack.size = 0;
	stack.head = NULL;

	char arr[] = "[2/{5*(4+7)}]";
	int length = 13;

	for (int i = 0; i < length; i++)
		pushStack(&stack, arr[i]);

	printf("\n2) ");

	switch (checkParentheses(&stack))
	{
		case 1:
			printf("String is good");
			break;
		case 0:
			printf("Incorrect size");
			break;
		case -1:
			printf("String is NOT good");
			break;
	}

	printf("\n");

	// 3
	List list1;
	list1.head = NULL;
	list1.tail = NULL;
	list1.size = 0;

	Enqueue(&list1, 'l');
	Enqueue(&list1, 'i');
	Enqueue(&list1, 's');
	Enqueue(&list1, 't');

	printf("\n3) List: ");
	printList(&list1);

	List list2;
	list2.head = NULL;
	list2.tail = NULL;
	list2.size = 0;

	copyList(&list1, &list2);

	printf("\nCopied List: ");
	printList(&list2);

	return 0;
}