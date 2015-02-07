#include <iostream>
#include <string>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/15/2%EB%93%B1

	문제:
	정수의 배열에서 두번째로 큰 숫자를 출력한다.
	정수의 배열에서 두번째로 큰 숫자를 출력하는 프로그램을 작성하라.

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	10개 미만의 자연수로 이루어진 배열
	입력:
	9 5 2 7 7 8
	
	입력된 자연수 배열 내에서 두번째로 큰 자연수를 출력한다. (두번째로 큰 자연수가 여러개 존재하더라도 1번만 출력한다.)
	출력:
	8
*/

const int MaxInputCount = 9;

int main()
{
	string input;
	getline(cin, input);

	int intInput[MaxInputCount] = {0,};

	// string으로 입력받고 공백을 구분자로 int 배열로 parsing합니다.
	{
		int cursor = 0;
		for (string::const_iterator iter = input.begin(); iter != input.end(); ++iter)
		{
			if ((*iter) == ' ' || (*iter) == '\t' || (*iter) == '\n')
			{
				++cursor;
				continue;
			}

			// intInput[iter] (십진수)<< 1;
			intInput[cursor] *= 10;
			intInput[cursor] += (*iter) - '0';
		}
	}

	int big = max(intInput[0], intInput[1]);
	int big2 = min(intInput[0], intInput[1]);

	for (int i = 2; i < MaxInputCount; ++i)
	{
		if (intInput[i] < 1)
			break;

		if (intInput[i] > big2)
		{
			if (intInput[i] > big)
			{
				big2 = big;
				big = intInput[i];
			}
			else
			{
				big2 = intInput[i];
			}
		}
	}

	cout << big2;

	return 0;
}