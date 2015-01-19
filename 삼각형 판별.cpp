#include <iostream>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/8/%EC%82%BC%EA%B0%81%ED%98%95-%ED%8C%90%EB%B3%84

	문제:
	삼각형의 종류를 판별하라
	삼각형의 세변의 길이가 주어질때 직각삼각형인지, 예각삼각형인지, 둔각 삼각형인지를 판별하시오

	제한:
	Time Limit : 100ms, Memory Limit : 512kb

	삼각형 각 변의 길이를 나타내는 3개의 양의 정수(이루어질 수 없는 삼각형은 주어지지 않음)
	입력:
	5 3 4
	
	입력받은 변의 길이를 분석하여 직각, 예각, 둔각 중 하나임을 판별한 뒤 출력한다.
	출력:
	직각
*/

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	// 제일 긴 변을 c로 설정합니다.
	if (a > b)
		swap(a, c);
	else if(b > c)
		swap(b, c);

	// 피타고라스의 정리를 이용해서 삼각형을 판별합니다.
	int aabb = (a*a) + (b*b);
	int cc = c*c;

	if (aabb > cc)
		cout << "예각 삼각형!";
	else if(aabb < cc)
		cout << "둔각 삼각형!";
	else
		cout << "직각 삼각형!";

	return 0;
}