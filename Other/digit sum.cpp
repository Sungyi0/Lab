#include <iostream>
#include <vector>

using namespace std;

int digitSum(int num)
{
	int ret = 0;
	for (int i = num; i > 0; i /= 10)
		ret += i % 10;
	return ret;
}

int main()
{
	vector<int> results;

	while (true)
	{
		int M, N;
		cin >> M >> N;

		if (M == 0 && N == 0)
			break;

		int base = digitSum(M), total = base;
		for (int i = 1; i <= N - M; ++i)
		{

		}

		results.push_back(total);
	}

	for (int r : results)
		cout << r << endl;

	return 0;
}

/*  // real code
int main ()
{
while (true)
{
int M, N;
cin >> M >> N;

if (M == 0 && N == 0)
break;

int total = 0;
for (int i = M; i <= N; ++i)
total += digitSum(i);

cout << total << endl;
}
}
*/