#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/18/%EC%A4%91%EA%B0%84%EA%B0%92

	문제:
	배열에서 중간값(median)을 찾아보자
	정렬되지 않은 임의의 정수들이 입력으로 주어졌을 때 중간값을 찾아서 출력하라. 중간값은 주어진 배열을 정렬하였을 때 가운데에 위치하는 값을 말한다.

	제한:
	Time Limit : 100ms, Memory Limit : 512kb

	첫번째 줄에는 배열의 길이(3 ≤ x ≤ 1023, x는 홀수), 두번째 줄에는 서로 다른 임의의 정수들로 이루어진 배열이 입력된다.
	입력:
	7 
	79 20 32 66 18 38 50
	
	주어진 배열 가운데 중간값을 출력한다.
	출력:
	38
*/

int main()
{
	int arrCount = 0;
	cin >> arrCount;

	// 입력 조건 불일치
	if ((arrCount % 2 == 0) || (arrCount < 3 || arrCount > 1023))
	{
		cout << "입력 조건 불일치" << endl;;
		return 0;
	}
	// clear the buffer (cin)
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(arrCount);

	string input;
	getline(cin, input);
	// string으로 입력받고 공백을 구분자로 int 배열로 parsing합니다.
	{
		int cursor = 0;
		for (string::const_iterator iter = input.begin(); iter != input.end(); ++iter)
		{
			// 공백은 구분자입니다.
			if ((*iter) == ' ' || (*iter) == '\t' || (*iter) == '\n')
			{
				//if (::find(arr.begin(), arr.begin() + cursor, arr[cursor]) != arr.end())
				//{
				//	cout << "배열 내의 수가 중복되면 안됩니다." << endl;
				//	return 0;
				//}

				++cursor;
				continue;
			}

			// intInput[iter] (십진수)<< 1;
			arr[cursor] *= 10;
			arr[cursor] += (*iter) - '0';
		}
	}

	::sort(arr.begin(), arr.end());

	cout << arr[arr.size() / 2];

	return 0;
}