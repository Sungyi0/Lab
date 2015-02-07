#include <iostream>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/7/%EC%86%8C%EC%88%98-%EC%B0%BE%EA%B8%B0

	문제:
	해당하는 모든 소수를 출력하라
	소수란 1과 자기 자신만을 약수로 가지는 수이다. 100이하의 자연수 중 모든 소수를 출력하시오

	제한:
	Time Limit : 100ms, Memory Limit : 512kb

	입력값 없음

	소수를 오름차순으로 출력한다. 각 출력값 사이는 공백으로 구분하고, 출력값 5개 마다 줄바꿈을 한다.
	출력:
	2 3 5 7 11 
	13 17 19 23 29 
	31 37 41 43 47 
	53 59 61 67 71 
	73 79 83 89 97
*/

const int limitNumber = 100;		// 100이하의 소수만 판별합니다.

int main()
{
	int outCount = 0;
	for (int i = 2; i <= limitNumber; ++i)
	{
		bool isContinue = false;
		for (int j = 2; j < i; ++j)
			if (i % j == 0)
				isContinue = true;

		if (isContinue)
			continue;

		// 소수다!
		cout << i << ' ';
		if (++outCount %5 == 0)
			cout << endl;
	}

	return 0;
}