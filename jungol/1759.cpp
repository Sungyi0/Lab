// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1759&sca=2020
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int min_input = 2;
const int max_input = 100000000;

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    return a % b == 0 ? b : gcd(b, a%b);
}

int main()
{
    int g, l;
    scanf("%d %d", &g, &l);

    // same case
    if (g == l)
    {
        printf("%d %d", g, l);
        return 0;
    }

    vector<int> ld;
    for (int i = 2; i*i < l; ++i)
    {
        if (l % i == 0)
        {
            ld.push_back(i);
            ld.push_back(l / i);
        }
    }
    ld.push_back(l);

    auto enditer = remove_if(ld.begin(), ld.end(), [g](int n) {return (n % g) != 0; });
    ld.erase(enditer, ld.end());

    vector<pair<int, int>> r;
    for (int n1 : ld)
    {
        for (int n2 : ld)
        {
            if (n1 == n2) continue;

            // gcd(n1, n2)
            int nl = n1, ng = n2;
            if (nl < ng) swap(nl, ng);
            while (nl % ng != 0)
            {
                int t = nl;
                nl = ng;
                ng = t%nl;
            }

            if (g == ng && l == ng * (n1 / ng) * (n2 / ng))
                r.push_back(make_pair(n1, n2));
        }
    }

    // no answer
    if (r.empty())
    {
        printf("0 0");
        return 0;
    }

    // sort sum
    vector<int> sum;
    for (auto n : r)
    {
        sum.push_back(n.first + n.second);
    }

    auto minSum = min_element(sum.begin(), sum.end());
    int r1 = r[minSum - sum.begin()].first, r2 = r[minSum - sum.begin()].second;
    printf("%d %d", min(r1, r2), max(r1, r2));
    return 0;
}
