/* 1.4 피보나치 수열
	f1 = 1, f2 = 1, fn = fn-1 + fn-2
*/

#include <iostream>
#include <map>

using namespace std;

map<int, long long> memo;

long long fibonacci(int n)
{
	if (memo.find(n) != memo.end())
		return memo[n];
		
	return memo[n] = fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
	memo[1] = 1;
	memo[2] = 1;

	while(true)
	{
		int a;
		cin >> a;
		if (a < 1)
			break;
			
		cout << fibonacci(a) << endl;
	}
}