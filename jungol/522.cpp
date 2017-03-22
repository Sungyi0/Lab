// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=522&sca=2030
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int MAX_INPUT = 10;

/*
3
001111000000011100
BAD

5
011111000000111111000000111111
3
*/

// A 000000 0 
// B 001111 15
// C 010011 19
// D 011100 28
// E 100110 38
// F 101001 41
// G 110101 53
// H 111010 58

bool repair(string a, string b)
{
    int ignore = 1;
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (a[i] != b[i])
        {
            if (ignore-- < 1)
                return false;
        }
    }
}

int main()
{
    map<string, char> table;
    table["000000"] = 'A';
    table["001111"] = 'B';
    table["010011"] = 'C';
    table["011100"] = 'D';
    table["100110"] = 'E';
    table["101001"] = 'F';
    table["110101"] = 'G';
    table["111010"] = 'H';

    int n;
    cin >> n;

    if (n > MAX_INPUT)
    {
        cout << 0;
        return 0;
    }

    string sentence;
    cin >> sentence;

    vector<string> ss(n);
    for (size_t i = 0; i < sentence.size(); ++i)
    {
        ss[i/6].push_back(sentence[i]);
    }

    bool success = true;
    vector<char> answer;
    size_t i = 0;
    for (;i < ss.size(); ++i)
    {
        auto n = ss[i];

        auto it = table.find(n);
        if (it != table.end())
            answer.push_back(it->second);
        else
        {
            auto it1 = table.begin();
            while (it1 != table.end())
            {
                if (repair(n, it1->first))
                {
                    answer.push_back(it1->second);
                    break;
                }

                if (++it1 == table.end())
                {
                    success = false;
                    break;
                }
            }
            if (success == false)
                break;
        }
    }
    if (success)
    {
        for (auto n : answer)
            cout << n;
    }
    else
        cout << i + 1;
    return 0;
}
