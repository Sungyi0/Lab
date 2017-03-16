// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1779&sca=2030
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char ChangeTable[numeric_limits<char>::max()] = { 0, };

int main()
{

    int input_n;
    cin >> input_n;

    for (int i = 0; i < input_n; ++i)
    {
        char key, data;
        cin >> key >> data;
        ChangeTable[key] = data;
    }

    cin >> input_n;
    vector<char> sentence(input_n);
    for (size_t i = 0; i < sentence.size(); ++i)
    {
        cin >> sentence[i];
    }

    for (size_t i = 0; i < sentence.size(); ++i)
    {
        if (ChangeTable[sentence[i]] != 0)
            sentence[i] = ChangeTable[sentence[i]];
    }

    for (auto n: sentence)
    {
        cout << n;
    }
    return 0;
}
