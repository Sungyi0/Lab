// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1516&sca=2020

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int max_n = 20000;
const int max_loop = 2000000000;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);

    if (a % b == 0)
        return b;
    else
        return gcd(a%b, b);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > max_n) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; ++i)
    {
        int ptr = i;
        do
        {
            if (cnt[ptr] > 0)
            {
                cnt[i] = cnt[ptr];
                break;
            }
            ptr = arr[ptr]-1;
            ++cnt[i];
        } while (ptr != i);
    }
    // get count END

    int r = cnt[0];
    for (int i = 1; i < cnt.size(); ++i)
    {
        int q = gcd(r, cnt[i]);
        int q1 = q * (r / q) * (cnt[i] / q);
        r = q1;
    }

    printf("%d", r);

    return 0;
}
