// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=931&sca=2020

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a == b)
    {
        printf("%d\n%d", a, b);
        return 0;
    }

    list<int> left;
    for (int i = 2; i < min(a, b); ++i)
    {
        while(!(a % i) && !(b % i))
        {
            left.push_back(i);
            a /= i; b /= i;
        }
    }

    int g = 1, l = 1;
    for (int n : left) g *= n;
    l = g * a * b;

    printf("%d\n%d", g, l);

    return 0;
}

