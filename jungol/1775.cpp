// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=1775&sca=2030
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_INPUT = 10000;

int main()
{
    char input[MAX_INPUT];
    scanf("%s", input);

    int nKoi = 0, nIoi = 0;
    for (int i = 1; i < MAX_INPUT-1; ++i)
    {
        if (input[i+1] == '\0') break;

        switch (input[i])
        {
        case 'O':
            if (input[i + 1] == 'I')
            {
                if (input[i - 1] == 'K')
                    ++nKoi;
                else if (input[i - 1] == 'I')
                    ++nIoi;
            }
            break;
        }
    }

    printf("%d\n%d", nKoi, nIoi);
    return 0;
}
