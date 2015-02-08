#include <stdio.h>
/* 0.4 은행 대기번호 관리 */

//#include "0.3.c"
extern void left_rotate(int[], int, int);

// Q. 배열로 큐 작성하기

#define QUEUE_SIZE 8

int main()
{
	int queue[QUEUE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0};

	int header = 0, input = 0;

	while (1)
	{
		printf("Input Number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			if (header >= QUEUE_SIZE)
			{
				printf("queue is full!\n");
				continue;
			}
			else
			{
				queue[header++] = input;
			}
		}
		// 0이라면 추출
		else if (input == 0)
		{
			if (queue[0] == 0)
				printf("queue is empty!!\n");
			else
			{
				printf("[%d]\n", queue[0]);
				queue[0] = 0;		//  추출 후 0으로 채웁니다.
				left_rotate(queue, 0, header--);
			}
		}
		// 0보다 작으면 종료
		else
			break;
	}

	return 0;
}