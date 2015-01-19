#include <iostream>
#include <cmath>

using namespace std;

/*
	문제 출처: try-cat.ch
	URL : http://www.try-cat.ch/contest/view/exercise/6/%EC%88%AB%EC%9E%90-%EC%9D%BD%EA%B8%B0

	문제:
	주어진 숫자를 한글로 읽어보자
	숫자단위에 아직 미숙한 어린 아이들을 대상으로 숫자가 한글로 출력되는 프로그램을 만들고자 한다.

	제한:
	Time Limit : 100ms, Memory Limit : 512kb

	0부터 1억 사이의 정수
	입력:
	1358 
	132742

	입력받은 숫자를 한글로 읽어 출력한다.
	출력:
	천 삼백 오십 팔 
	십 삼만 이천 칠백 사십 이
*/

/*
	일	십	백	천
	만	십만	백만	천만
	억	십억	백억	천억
	조	십조	백조	천조
*/

const char* magnitude[] = {"", "십", "백", "천"};
const char* magnitude2[] = {"", "만", "억", "조"};
const char* num2kor[] = {"", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구"};

// 자릿수 구하기
int calc_numbercount (const int input)
{
	int numbercount = 0;
	for (int number = input; number > 0; number /= 10)
		++numbercount;

	return numbercount;
}

int main()
{
	int input;
	cin >> input;

	// 자릿수 구하기
	int numbercount = calc_numbercount(input);

	// 루틴마다 숫자 하나씩 읽는다.
	int number = input;
	while (number > 0)
	{
		int readNumber = -1;

		// 앞부터 읽습니다.
		int ten = static_cast<int>(pow(10, numbercount-- -1));		// 십의자리수
		readNumber = number / ten;
		number = number % ten;

		// 일십, 일백, 일천에서 일은 생략됩니다.
		if (readNumber != 1 || numbercount % 4 == 0)
			cout << num2kor[readNumber];
		cout << magnitude[numbercount%4];

		if (numbercount%4 == 0)
			cout << magnitude2[numbercount/4];
		cout << ' ';

	}


	return 0;
}