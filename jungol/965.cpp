// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=965&sca=20

#include <iostream>

int main()
{
    int a, b, c = 0;
    scanf("%d\n%d", &a, &b);
    
    int i = 0;
    while(b > 0)
    {
        int digit = b%10;
        int t = digit*a;
        printf("%d\n", t);
        
        for (int j = 0; j < i; ++j)
            t *= 10;
        c += t;
        b /= 10;
        ++i;
    }
    printf("%d\n", c);
}

