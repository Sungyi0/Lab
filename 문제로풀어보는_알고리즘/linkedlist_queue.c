// Q. 연결리스트로 큐 작성하기

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	void *m_data;
	struct _node *m_next;
} SNode;

void SNode_init(SNode *node)
{
	node->m_data = NULL;
	node->m_next = NULL;
}

typedef struct _list
{
	SNode *m_next;
} SList;

void SList_init(SList *list)
{
	list->m_next = NULL;
}

SNode * SList_end(SList *list)
{
	SNode *i = list->m_next;
	while (i != NULL)
	{
		if (i->m_next == NULL)
			return i;

		i = i->m_next;
	}

	return i;
}

void SList_push(SList *list, void *data)
{
	SNode *tail;

	// 새로 들어갈 노드를 만듭니다
	SNode *newData = (SNode *)malloc(sizeof(SNode));
	SNode_init(newData);
	newData->m_data = data;
	newData->m_next = NULL;

	// 꼬리에 붙입니다.
	tail = SList_end(list);
	if (tail == NULL)
		list->m_next = newData;
	else
		tail->m_next = newData;
}

void * SList_pop(SList* list)
{
	void *data;
	SNode *head;

	if (list->m_next == NULL)
		return NULL;

	// 맨 앞을 빼고 next를 수정.
	data = list->m_next->m_data;
	head = list->m_next;
	list->m_next = list->m_next->m_next;

	free(head);

	return data;
}

int main()
{
	int input = 0;
	SList queue;
	SList_init(&queue);

	while (input >= 0)
	{
		printf("input number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			int *data = (int*)malloc(sizeof(int));
			*data = input;
			SList_push(&queue, data);
		}
		// 0이면 출력
		else if (input == 0)
		{
			int *data = (int *)SList_pop(&queue);
			if (data == NULL)
			{
				printf("queue is empty!\n");
			}
			else
			{
				printf("[%d]\n", *data);
				free(data);
			}
		}
	}

	return 0;
}