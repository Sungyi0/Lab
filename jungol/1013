// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1013&sca=20
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_INPUT = 10000;

int main()
{
    int M, N;
    scanf("%d\n%d", &M, &N);

    if ((M > MAX_INPUT || N > MAX_INPUT) || M > N)
    {
        printf("-1");
    }

    M = max(2, M);

    vector<bool> m(N - M + 1, true);
    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 2; j < i + M; ++j)
        {
            if ((i + M) % j == 0)
            {
                m[i] = false;
                break;
            }
        }
    }

    int sum = 0, min = 0;
    int a = M - 1;
    for (auto n : m)
    {
        ++a;
        if (n)
        {
            sum += a;
            if (min == 0)
                min = a;
        }
    }

    if (sum > 0)
        printf("%d\n%d", sum, min);
    else
        printf("-1");
    return 0;
}
