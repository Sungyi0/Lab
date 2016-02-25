/* 1.3 이항계수(binomial coefficient)
			n * (n-1) * ... (n-r+1)
	nCr = -----------------------------
					r!
*/

#include <iostream>
#include <map>

using namespace std;

struct chunk 
{
	chunk(int n_, int r_)
		: n(n_), r(r_)
	{}

	short n; 
	short r;
	
	int toKey()
	{
		return *reinterpret_cast<int*>(this);
	}
	
	operator int() {return toKey();}
};

map<int, long long> memo;

long long calcBC(int n, int r)
{
	if(memo.find(chunk(n, r)) != memo.end())
		return memo[chunk(n, r)];
		

	if (n == r || r == 0)
		return 1;
		
	auto a = calcBC(n-1, r-1);
	memo[chunk(n-1, r-1)] = a;
	auto b = calcBC(n-1, r);
	memo[chunk(n-1, r)] = b;
	
	return a + b;
}

int main()
{
	while(true)
	{
		int n, r;
		cin >> n >> r;
		if (n == 0)
			break;
		cout << calcBC(n, r) << endl;
	}
}