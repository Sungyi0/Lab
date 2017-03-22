// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=310&sca=2040
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

/*
11 12 2 24 10
16 1 13 3 25
6 20 5 21 17
19 4 8 14 9
22 15 7 23 18
5 10 7 16 2
4 22 8 17 13
3 18 1 6 25
12 19 23 14 21
11 24 9 20 15

15
*/

const int LENGTH = 5;

int main()
{
    array<array<pair<bool, int>, LENGTH>, LENGTH> table;
    for (auto& n : table)
    {
        for (auto& nn : n)
        {
            nn.first = false;
            cin >> nn.second;
        }
    }

    array<int, LENGTH * LENGTH> bingo;
    for (auto& n : bingo)
    {
        cin >> n;
    }

    int bingoCnt = 0;
    size_t cnt = 0;
    for (; cnt < bingo.size(); ++cnt)
    {
        auto n = bingo[cnt];
        auto YX = [n, &table]()->pair<int, int>
        {
            for (int y = 0; y < LENGTH; ++y)
            {
                for (int x = 0; x < LENGTH; ++x)
                {
                    if (table[y][x].second == n)
                    {
                        table[y][x].first = true;
                        return make_pair(y,x);
                    }
                }
            }
            
            cout << 0;
            exit(0);
            return make_pair(0, 0);
        }();

        /* | - / \ */
        for (int i = 0; i < LENGTH; ++i)
        {
            if (table[i][YX.second].first == false)
                break;
            else if (i + 1 == LENGTH)
                ++bingoCnt;
        }
        for (int i = 0; i < LENGTH; ++i)
        {
            if (table[YX.first][i].first == false)
                break;
            else if (i + 1 == LENGTH)
                ++bingoCnt;
        }
        if (YX.first == YX.second)
        {
            for (int i = 0; i < LENGTH; ++i)
            {
                if (table[i][i].first == false)
                    break;
                else if (i + 1 == LENGTH)
                    ++bingoCnt;
            }
        }
        if (YX.first + YX.second == LENGTH-1)
        {
            for (int i = 0; i < LENGTH; ++i)
            {
                if (table[i][(LENGTH-1)-i].first == false)
                    break;
                else if (i + 1 == LENGTH)
                    ++bingoCnt;
            }
        }

        if (bingoCnt >= 3)
            break;
    }

    cout << cnt+1;
    return 0;
}
