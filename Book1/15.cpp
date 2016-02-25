/*	1.5 금액 맞추기
지폐의 종류와, 지불해야 하는 액수를 입력받아서, 몇 가지 지불 방법이 있는지를 출력하는 프로그램을 작성하라.
단, 지폐의 종류는 50가지를 넘지 않는다.

ex)
input number of bills: 6
input bills: 1 2 5 10 20 50
input money: 100
4562

7
1 2 5 10 20 50 100
300
466800
*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	while (true)
	{
		int billsCount, money;
		list<int> bills;
		
		cin >> billsCount;
		for (int i = 0; i < billsCount; ++i)
		{
			int a;
			cin >> a;
			bills.push_back(a);
		}
	}
}