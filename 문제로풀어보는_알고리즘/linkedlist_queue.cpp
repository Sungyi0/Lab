// Q. 연결리스트로 큐 작성하기

#include <stdio.h>
#include <stdlib.h>

template<typename _Ty>
class CList
{
	struct node
	{
		node() : m_data(nullptr), m_next(nullptr) {}
		_Ty *m_data;
		node *m_next;

		bool isTail() {return m_next == nullptr;}
	};

public:
	CList()
		: m_next(nullptr), m_size(0)	{}

	node * end()
	{
		node *i = m_next;
		while (i != nullptr)
		{
			if (i->isTail())
				return i;

			i = i->m_next;
		}

		return i;
	}

	void push(_Ty *data)
	{
		// 새로 들어갈 노드를 만듭니다
		node *newData = new node;
		newData->m_data = data;
		newData->m_next = nullptr;

		// 꼬리에 붙입니다.
		node *tail = end();
		if (tail == nullptr)
			m_next = newData;
		else
			tail->m_next = newData;

		++m_size;
	}

	_Ty * pop()
	{
		if (m_next == nullptr)
			return nullptr;

		// 맨 앞을 빼고 next를 수정.
		_Ty* data = m_next->m_data;
		node* head = m_next;
		m_next = m_next->m_next;

		--m_size;

		free(head);

		return data;
	}

	node* GetNext() const { return m_next; }
	size_t GetSize() const { return m_size; }

private:
	size_t m_size;
	node* m_next;
};

int main()
{
	int input = 0;
	CList<int> queue;

	while (input >= 0)
	{
		printf("input number: ");
		scanf_s("%d", &input);

		// 0보다 크면 입력
		if (input > 0)
		{
			int *data = (int*)malloc(sizeof(int));
			*data = input;
			queue.push(data);
		}
		// 0이면 출력
		else if (input == 0)
		{
			int *data = queue.pop();
			if (data == nullptr)
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