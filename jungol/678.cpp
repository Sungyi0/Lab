// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=678&sca=2020

#include <iostream>

const int min_input = 1;
const int max_a = 10000;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (a < min_input || b < min_input) { printf("0\n"); return 0; }
    if (a > max_a || b > a) { printf("0\n"); return 0; }
    if (b == 1) { printf("1\n"); return 0; }
    
    int c = 0;
    for (int i = 1; i < a; ++i)
    {
        if ((a%i) == 0) ++c;
        if (c == b) { printf("%d\n", i);  return 0; }
    }
    
    printf("0");
    return 0;
}

