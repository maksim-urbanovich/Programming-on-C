#include<stdio.h>

#define N 5

void Set_Matrix(int a[][N]);
void Change_Diagonals(int a[][N]);
void Print_Matrix(int a[][N]);

int main()
{
	int a[N][N];
	
	Set_Matrix(a);

	printf("Initial Matrix\n");
	Print_Matrix(a);

	Change_Diagonals(a);

	printf("\nChanged Matrix\n");
	Print_Matrix(a);

	return 0;
}

void Set_Matrix(int a[][N])
{
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			a[i][j] = 2 * i + j;
}

void Change_Diagonals(int a[][N])
{
	int temp = 0;

	for (int i = 0; i < N; i++) {
		temp = a[i][N - i - 1];
		a[i][N - i - 1] = a[i][i];
		a[i][i] = temp;
	}
}

void Print_Matrix(int a[][N])
{
	for (int i = 0; i < N; i++) 
	{
		for(int j = 0; j < N; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
}