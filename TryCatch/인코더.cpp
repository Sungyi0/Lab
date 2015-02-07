#include <iostream>
#include <string>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/27/%EC%9D%B8%EC%BD%94%EB%8D%94

	문제:
	문자열을 지정된 형식으로 변환하여 출력한다.
	알파벳 문자열이 입력으로 주어졌을 때 다음과 같은 형식으로 인코딩해 출력하는 프로그램을 작성하라.

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	문자열(단, 문자열 길이는 20 미만)
	입력:
	AAABBGFFFF
	
	각 알파벳 별 갯수와 해당 알파벳을 연속적으로 출력한다.
	출력:
	3A2B1G4F
*/

int main()
{
	string input;
	cin >> input;

	int count = 0;
	char ch = input[0];
	for (string::const_iterator iter = input.begin(); iter != input.end(); ++iter)
	{
		++count;

		if ((iter +1) == input.end())
		{
			cout << count << ch;
		}
		else if ((*(iter +1)) != ch)
		{
			cout << count << ch;

			ch = *(iter +1);
			count = 0;
		}
	}

	return 0;
}