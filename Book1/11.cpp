/*	1.1 팩토리얼 계산하기
n!은 1부터 n까지의 자연수를 모두 곱한 것이다. 예를 들어, 3!=1*2*3=6이고 6!= 1*2*3*4*5*6 =720 이다.
경우의 수를 게산하거나 알고리즘의 성능을 분석할 때 n!을 다뤄야 할 일이 많다.

n!은 다음과 같이 정의할 수 있다.
n! = 1*2*...*n
*/

#include <iostream>

using namespace std;

int factorial(int n)
{
	if (n == 1)
		return 1;
		
	return factorial(n-1) * n;
}

int factorial_for(int n)
{
	int r = 1;
	for (int i = 2; i <= n; ++i)
		r *= i;
	return r;
}

int main()
{
	int a = 1;
	
	while(true)
	{
		cin >> a;
		if (a < 1)
			break;
		cout << factorial(a) << endl;
		cout << factorial_for(a) << endl;
	}
}