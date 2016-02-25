/*
스택 두 개를 이용하여 큐를 만드는 방법은 무엇일까? 큐에 원소를 넣고(enqueue), 빼는(dequeue) 동작은 가능한 효율적이어야 한다.
*/
#include <iostream>
#include <stack>

using namespace std;

const int StackMaxSize = 5;

typedef stack<int> stack_int;

void MoveStack(stack_int& s1, stack_int&s2)
{
    while (s1.empty() == false)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

int main(int argc, char* argv[])
{
    stack_int s1, s2;

    char in;
    do
    {
        cout << "1 : Enqueue, 2: Dequeue, 3: Print StackSize" << endl;
        cin >> in;
        if (in == '1')
        {
            if (s1.size() >= StackMaxSize)
            {
                if (s2.empty() == false)
                {
                    cout << "stack is full" << endl;
                    continue;
                }

                MoveStack(s1, s2);
            }

            char in2;
            cout << "Number.." << endl;
            cin >> in2;
            s1.push(in2 - '0');
        }
        else if (in == '2')
        {
            if (s2.empty())
            {
                if (s1.empty())
                {
                    cout << "stack is empty" << endl;
                    continue;
                }

                MoveStack(s1, s2);
            }

            cout << s2.top() << endl;
            s2.pop();
        }
        else if (in == '3')
        {
            stack_int tmp;
            cout << "s1 ";
            tmp = s1;
            while (tmp.empty() == false)
            {
                cout << tmp.top() << ' ';
                tmp.pop();
            }
            cout << endl;

            cout << "s2 ";
            tmp = s2;
            while (tmp.empty() == false)
            {
                cout << tmp.top() << ' ';
                tmp.pop();
            }
            cout << endl;
        }
    }while (in != 'q');

	return 0;
}