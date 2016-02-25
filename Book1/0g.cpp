/*
10진수 정수를 입력받아서 이진수로 바꾸어 출력하는 프로그램을 작성하라.
*/

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	list<bool> binary;
	do
	{
		binary.clear();
		
		int in;
		cin >> in;
		
		for (; in > 0; in >>= 1)
			binary.push_back(in & 1);
		
		for (auto iter = binary.rbegin(); iter != binary.rend(); ++iter)
			cout << (*iter) ? 1 : 0;
		cout << endl;
	}while(true);
	
	return 0;
}