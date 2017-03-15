// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1865&sca=2030
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_INPUT = 50;

int main()
{
    char input[MAX_INPUT];
    scanf("%s", input);

    const int height = 10;
    const int dheight = 5;

    int total = height;
    char last = input[0];
    for (int i = 1; i < MAX_INPUT; ++i)
    {
        if (input[i] == '\0') break;
        if (input[i] != last)
        {
            last = input[i];
            total += height;
        }
        else
            total += dheight;
    }

    printf("%d", total);
    return 0;
}
