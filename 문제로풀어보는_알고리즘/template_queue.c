#include <stdio.h>
#include <stdlib.h>
/* 0.4 은행 대기번호 관리 */

// Q. 일반적인 데이터 타입을 다를 수 있도록 큐를 수정하라

#define QUEUE_SIZE 8

int main()
{
	void* queue[QUEUE_SIZE];
	int i, header = 0, tail = 0;

	// queue를 NULL로 초기화합니다.
	for (i = 0; i < QUEUE_SIZE; ++i)
		queue[i] = NULL;
	
	while (1)
	{
		int input = 0;

		printf("Input Number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			if (queue[header] != NULL)
			{
				printf("queue is full!\n");
				continue;
			}
			else
			{
				int* newData = (int*)malloc(sizeof(input));
				*newData = input;
				queue[header] = newData;
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
				printf("[%d]\n", *((int*)queue[tail]));
				free(queue[tail]);
				queue[tail] = NULL;	//  추출 후 0으로 채웁니다.
				tail = (tail + 1) % QUEUE_SIZE;
			}
		}
		// 0보다 작으면 종료
		else
			break;
	}

	return 0;
}