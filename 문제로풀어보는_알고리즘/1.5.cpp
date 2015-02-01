#include <stdio.h>
#include <stdlib.h>

int numberBills, inputMoney;
int counter = 0;
int *bills;

int foo(int i, int money)
{
	int count = 0;

	int j = 0;
	for (j = money; j > 0; j -= bills[i])
		if (foo(i+1, j) != 0)
			++count;

	return count;
}

int main()
{
	int i, j, l, k;

	printf("input number of bills: ");
	scanf("%d", &numberBills);

	bills = (int *)malloc(numberBills * sizeof(int));

	printf("input bills: ");
	for (i = 0; i < numberBills; ++i)
		scanf("%d", &bills[i]);

	printf("input money: ");
	scanf("%d", &inputMoney);

	foo(inputMoney);

	free(bills);
}