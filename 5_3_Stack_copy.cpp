#include<stdio.h>
#include<stdlib.h>

#define N 10
#define RAND_N 10

typedef struct item {
	int value;
	struct item *next;
} Item;

Item * Create_Stack(Item *top);
void Print_Stack(Item *top);
Item * Copy_Stack1(Item *top1);
Item * Copy_Stack(Item *top1);

int main()
{
	Item *top1 = NULL;
	Item *top2 = NULL;	

	top1 = Create_Stack(top1);
	Print_Stack(top1);
	top2 = Copy_Stack(top1);
	Print_Stack(top2);

	return 0;
}

Item * Create_Stack(Item *top)
{
	Item *p;
	int i = 0;

	while (i < N) {
		p = (Item *)malloc(sizeof(Item));
		p->value = rand() % RAND_N;
		p->next = top;
		top = p;
		i++;
	}

	return top;
}

void Print_Stack(Item *top)
{
	Item *p = top;

	printf("Stack is: \n");
	while (p != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}

Item * Copy_Stack1(Item *top1)
{
	Item *p = top1;
	Item *top3 = NULL;
	Item *p3;
	int n;

	while (p!= NULL) {
		p3 = (Item *)malloc(sizeof(Item));
		p3->value = p->value;
		p3->next = top3;
		top3 = p3;
		p = p->next;
	}

	return top3;
}

Item * Copy_Stack(Item *top1)
{
	Item *top3 = NULL;

	top3 = Copy_Stack1(top1);
	//Print_Stack(top3);
	top3 = Copy_Stack1(top3);

	return top3;
}