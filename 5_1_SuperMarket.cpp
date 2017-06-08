#include<stdio.h>
#include<stdlib.h>

#define SECONDS 60
#define RAND_N 4

typedef struct item {
	int start_time;
	struct item *next;
} Item;

Item *head = NULL;
Item *tail = NULL;

int RandSeconds();
void AddCustomer(int time1);
void Queue(int *, int *);
void DelCustomer();
void PrintGraph(int i, int count);
void PrintAnswer(char ans[], int answer);
void FreeQueue();

int main()
{
	int maxCustomers = 0;
	int maxWaitingTime = 0;

	Queue(&maxCustomers, &maxWaitingTime);

	PrintAnswer("maxCustomers =", maxCustomers);
	PrintAnswer("maxWaitingTime =", maxWaitingTime);
	
	FreeQueue();
	
	return 0;
}

int RandSeconds() {
	return rand() % RAND_N + 1;
}

void PrintAnswer(char ans[], int answer)
{
	printf("%s %d \n", ans, answer);
}

void AddCustomer(int time1)
{
	Item *p = NULL;
	p = (Item *)malloc(sizeof(Item));
	p->start_time = time1;
	p->next = NULL;

	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}	
}

void DelCustomer()
{
	Item* p = head;

	if (head != NULL)
		head = head->next;
	else
		tail = NULL;

	free(p);
}

void FreeQueue()
{
	while(tail) {
		DelCustomer();
	}
}

void PrintGraph(int i, int count)
{
	int j = 0;

	printf("%2d sec - ", i);
	while (j < count)
	{
		printf("*");
		j++;
	}
	printf("\n");
}

void Queue(int *maxCustomers, int *maxWaitingTime)
{
	int i = 0;
	int m = 0, n = 0;
	int new_customer_time = 0;
	int waiting_time = 0;
	int count = 0;
	int time2 = 0;
	
	new_customer_time = RandSeconds();
	for (i = 0; i <= SECONDS; i++){
		if (head == NULL)
			time2 = i + RandSeconds();
		if (new_customer_time == i) {
			AddCustomer(i);
			count++;		
			n = RandSeconds();
			new_customer_time += n;
			// find maxCustomers			
		}

		if (time2 == i) {
			m = RandSeconds();
			time2 += m;

			waiting_time = i - head->start_time;
			if (waiting_time > *maxWaitingTime)
				*maxWaitingTime = waiting_time;

			DelCustomer();
			count--;
		}

		if (count > *maxCustomers)
			*maxCustomers = count;

		PrintGraph(i, count);
	}
}