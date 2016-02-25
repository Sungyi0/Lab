/* 1.2 연결리스트 출력하기
	
*/

#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int>& ll)
{
	for (auto e: ll)
		cout << e << ", ";
	cout << endl;
}

void print_list2(list<int>& ll)
{
	if (ll.empty())
		return;
		
	cout << *ll.begin() << ", ";
	ll.pop_front();
	print_list2(ll);
}

int main()
{
	list<int> ll;
	
	while (true)
	{
		int n;
		cout << "input number: ";
		cin >> n;
		if (n == 0)
		{
			cout << *ll.begin() << endl;
			ll.pop_front();
		}
		else if (n < 0)
		{
			print_list(ll);
			print_list2(ll);
			break;
		}
		else
			ll.push_back(n);
	}
}