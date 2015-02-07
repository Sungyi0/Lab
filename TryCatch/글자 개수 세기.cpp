#include <iostream>
#include <string>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/14/%EA%B8%80%EC%9E%90-%EA%B0%9C%EC%88%98-%EC%84%B8%EA%B8%B0

	문제:
	문자열에서 각 단어의 길이를 구한다.
	알파벳, 기호, 공백 및 특수문자들로 이루어진 문자열을 입력받는다. 그리고 공백 문자로 구분되는 각 단어의 길이를 출력한다.

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	특수문자, 알파벳, 숫자, 공백 등으로 이루어진 문자열
	입력:
	Dark. Knight, Rises!
	
	공백문자로 구분되는 각 단어의 길이를 각각 출력한다.
	출력:
	5 7 6
*/

int main()
{
	string input;
	getline(cin, input);

	int charCount = 0;
	for (string::const_iterator iter = input.begin(); iter != input.end(); ++iter)
	{
		if (*iter == ' ')
		{
			cout << charCount << ' ';
			charCount = 0;
			continue;
		}

		++charCount;

		if (iter == input.end() -1)
		{	
			cout << charCount;
			break;
		}
	}

	return 0;
}