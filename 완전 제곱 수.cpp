#include <iostream>
#include <cmath>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/11/%EC%99%84%EC%A0%84-%EC%A0%9C%EA%B3%B1-%EC%88%98

	문제:
	완전 제곱수를 찾아보자.
	하나의 자연수가 입력으로 주어졌을 때 그 수와 가장 가까운 (차가 가장 작은) 완전 제곱수를 찾아 출력한다.

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	1개의 자연수
	입력:
	75
	
	입력값과 가장 가까운 완전제곱수
	출력:
	81
*/

// 첫째자리로 반올림하는 함수.
// 0.5를 더한 후 내림하는 방식입니다.
inline int myround(double number)
{
	return static_cast<int>(floor(number + 0.5));
}

int main()
{
	int input;
	cin >> input;

	double sqrtInput = sqrt(input);
	sqrtInput = myround(sqrtInput);

	cout << sqrtInput * sqrtInput;

	return 0;
}