// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=706&sca=20

#include <iostream>

int main()
{
    int r[10] = {0,};
    
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    
    long long d = a*b*c;
    while(d > 0)
    {
      int e = d%10;
      ++r[e];
      d /= 10;
    }
    
    for(int i = 0; i < 10; ++i)
    printf("%d\n", r[i]);
}

