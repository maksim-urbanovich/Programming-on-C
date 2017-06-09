/*Условие задачи:
	Сдвиг. Циклически сдвиньте элементы массива на n позиций влево.
*/

#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<malloc.h>

#define N 12
#define RAND_MAX_ 11

int Init_n();
void Init_Array(int a[]);
void Print_Array(int a[]);
void Cycle_Shift(int a[], int n);

int main()
{
	int a[N], n = 1;

	n = Init_n();

	if (n < 1){
		printf("You enter wrong Shift\n");
		return 1;
	}

	Init_Array(a);
	printf("Initial array a: \n");
	Print_Array(a);

	Cycle_Shift(a, n);
	printf("Shifted array a: \n");
	Print_Array(a);

	return 0;
}

int Init_n()
{
	int n;

	printf("Enter number of shift n (n < %d) = ", N);
	scanf("%d", &n);

	if ((n > N) || (n < 1))
	{
		printf("You enter a wrong n\n");
		return 0;
	}

	return n;
}

void Init_Array(int a[])
{
	srand(time(NULL));
	for (int i = 0; i < N; i++ ) 
		a[i] = rand() % RAND_MAX_;
}

void Print_Array(int a[])
{
	for (int i = 0; i < N; i++ )
		printf("%d ", a[i]);
	printf("\n");
}

void Cycle_Shift(int a[], int n)
{
	int *b;

	b = (int *)calloc(n, sizeof(int));

	for (int i = n; i > 0; i--)
		b[n - i] = a[N - i];

	for (int i = N - 1; i >= n; i--)
		a[i] = a[i - n];

	for (int i = 0; i < n; i++)	
		a[i] = b[i];	
	
	free(b);
}