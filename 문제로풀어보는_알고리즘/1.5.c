#include <stdio.h>
#include <stdlib.h>

int foo(int bills[], int billCount, int money)
{
	if (billCount == 0 && bills[billCount])
		return 1;

	//int count = 0;

	//int j = 0;
	//for (j = money; j > 0; j -= bills[billCount])
	//	if (foo(billCount+1, j) != 0)
	//		++count;

	//return count;
}

int main()
{
	int numberBills, inputMoney;
	int counter = 0;
	int *bills;
	int i;

	printf("input number of bills: ");
	scanf_s("%d", &numberBills);

	bills = (int *)malloc(numberBills * sizeof(int));

	printf("input bills: ");
	for (i = 0; i < numberBills; ++i)
		scanf_s("%d", &bills[i]);

	printf("input money: ");
	scanf_s("%d", &inputMoney);

	foo(bills, numberBills, inputMoney);

	free(bills);
}