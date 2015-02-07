#include <iostream>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/24/%EC%98%A8%EB%8F%84-%EB%8B%A8%EC%9C%84-%EB%B3%80%ED%99%98

	문제:
	화씨온도를 섭씨온도로 바꿔라
	화씨온도 단위를 F, 섭씨온도 단위를 C라 한다. 화씨온도를 입력하여 그값을 섭씨온도로 변환하는 계산기를 프로그래밍하라. (단, 변환 공식은 다음과 같다. 섭씨온도(C) = (화씨온도(F) - 30) / 2)

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	정수로 이루어진 화씨 온도(단위 F 포함)
	입력:
	97F
	
	정수로 이루어진 섭씨 온도(단위 C 포함), 소수점 이하는 모두 버린다.
	출력:
	33C
*/

int main()
{
	int f;
	cin >> f;

	cout << (f - 30) / 2 << 'C';

	return 0;
}
