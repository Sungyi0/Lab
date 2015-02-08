#include <stdio.h>
/* 0.4 은행 대기번호 관리 */

// Q. 원형 큐 작성
#define QUEUE_SIZE 8

int main()
{
	int queue[QUEUE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0};

	int header = 0, tail = 0, input = 0;

	while (1)
	{
		printf("Input Number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			if (queue[header] != 0)
			{
				printf("queue is full!\n");
				continue;
			}
			else
			{
				queue[header] = input;
				header = (header + 1) % QUEUE_SIZE;
			}
		}
		// 0이라면 추출
		else if (input == 0)
		{
			if (queue[tail] == 0)
			{
				printf("queue is empty!!\n");
				continue;
			}
			else
			{
				printf("[%d]\n", queue[tail]);
				queue[tail] = 0;	//  추출 후 0으로 채웁니다.
				tail = (tail + 1) % QUEUE_SIZE;
			}
		}
		// 0보다 작으면 종료
		else
			break;
	}

	return 0;
}