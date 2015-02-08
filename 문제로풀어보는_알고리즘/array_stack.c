/* 0.4 은행 대기번호 관리 */

#include <stdio.h>

// 생각해보기 Q. 배열을 이용하여 스택을 작성하라.

#define STACK_SIZE 8

int main()
{
	int i, input = 0;
	int header = 0;
	int stack[STACK_SIZE];

	// 스택의 모든 원소를 0으로 초기화
	for (i = 0; i < STACK_SIZE; ++i)
		stack[i] = 0;

	while (input > 0)
	{
		printf("Input Number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			if (header < STACK_SIZE)
			stack[header++] = input;
		}
		// 0이라면 추출
		else if (input == 0)
			printf("%d\n", stack[header--]);
		else
	}

	return 0;
}