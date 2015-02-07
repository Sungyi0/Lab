#include <iostream>
#include <string>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/21/%EB%8B%A8%EC%96%B4-%EB%92%A4%EC%A7%91%EA%B8%B0

	문제:
	단어들을 뒤집어 출력한다.
	문자열을 입력받아 해당 문자열의 단어들을 역으로 출력하는 프로그램을 작성하라

	제한:
	Time Limit : 200ms, Memory Limit : 512kb

	임의의 문자열을 입력받는다. 단어와 단어 사이는 공백 문자로 구분된다.
	입력:
	olleh dlrow
	
	문자열에 속한 단어들을 각각 뒤집어서 출력한다. 문자열에서 단어들의 순서는 변하지 않는다.
	출력:
	hello world
*/

//void reverseString(string::iterator begin, string::iterator end)
//{
//	while (begin != end)
//	{
//		swap((*begin), (*end));
//
//		++begin; --end;
//	}
//}

int main()
{
	//string input;
	//getline(cin, input);

	//// 마지막을 공백으로 끝냅니다..
	//if (input[input.size()] != ' ' && input[input.size()] != '\t' && input[input.size()] != '\n')
	//	input.push_back(' ');

	//{
	//	string::iterator begin = input.begin();
	//	for (string::iterator iter = input.begin(); iter != input.end(); ++iter)
	//	{
	//		// 구분자는 공백
	//		if ((*iter) == ' ' || (*iter) == '\t' || (*iter) == '\n')
	//		{
	//			reverseString(begin, iter -1);
	//			begin = iter +1;
	//		}
	//	}
	//}

	//cout << input;

	string input;

	while (cin >> input)
	{
		string rever(input.rbegin(), input.rend());
		cout << rever << ' ';
	}

	return 0;
}