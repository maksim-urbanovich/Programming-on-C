#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10
#define RAND_N 10
#define OUR_STRING "pab ca"

typedef struct item {
	char value;
	struct item *next;
	struct item *prev;
} Item;

Item *head = NULL;
Item *tail = NULL;

int IsLetter(char c);
void Create_List(char *s);
void PrintList();
int IsPalindrom(char *s);
void PrintAnswer(int answer, char *s);
void FreeList();

int main()
{
	int answer = 0;
	
	char *s = strlwr(OUR_STRING);	

	Create_List(s);
	PrintList();
				
	answer = IsPalindrom(s);
	PrintAnswer(answer, s);
	FreeList();

	return 0;
}

int IsLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}

void Create_List(char *s)
{
	Item *p;

	while (*s != '\0') {
		if (!IsLetter(*s)) {
			s++;
			continue;
		}

		p = (Item *)malloc(sizeof(Item));
		p->value = *s;
		p->next = p->prev = NULL;		

		if (head == NULL) {
			head = tail = p;
			s++;
			continue;
		}

		tail->next = p;
		p->prev = tail;
		tail = p;

		s++;
	}
}

void PrintList()
{
	Item *p = head;

	if (head != NULL)
		printf("List is: \n");
	while (p != NULL) {
		printf("%c ", p->value);
		p = p->next;
	}
	if (head != NULL)
		printf("\n");
}

int IsPalindrom(char *s)
{		
	if (head == NULL) {		
		return 0;
	}

	while (head != NULL)
	{		
		if (head->value != tail->value) {			
			return -1;
		}

		head = head->next;		
		tail = tail->prev;
	}	

	return 1;
}

void PrintAnswer(int answer, char *s)
{
	switch (answer) {
		case  0: printf("The string is empty\n"); break;
		case -1: printf("No, the string \"%s\" is not palindrom\n", s); break;
		case  1: printf("Yes, the string \"%s\" is palindrom\n", s); break;
		default: printf("Unknown result \n"); break;
	}
}

void FreeList()
{
	while(tail) {
		Item* p = tail;

		if (head != tail)
			tail = tail->prev;
		else
			head = tail = NULL;

		free(p);
	}
}