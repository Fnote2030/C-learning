#include<stdio.h>
int hannot(int n,char x,char y,char z)  //整体上全部圆盘从x到z
{
    static int count = 0;
    if(1==n)
    {
        printf("[%d] %c >> %c\n",n,x,z);
        count++;
    }
    else
    {  
        hannot(n-1,x,z,y);  //n-1个圆盘从x到y
        printf("[%d] %c >> %c\n",n,x,z);  //上面的移走后，最大的圆盘从x到z
        count++;
        hannot(n-1,y,x,z);  //n-1个圆盘从y到z
    }
    return count;
}

int main()
{
    int n = 0;
    printf("请输入圆盘数：");
    scanf("%d",&n);
    int count = hannot(n,'A','B','C');
    printf("实现汉诺效果一共移动了%d次\n",count);
    return 0;
}