#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void game(){
    int guess = 0;
    int ret = 0;
    int count = 0;
    printf("\n游戏开始，猜1-100的数字!\n");
    //1、生成随机数字
    ret = rand() % 100 + 1; //随机生成1-100的数
    //printf("%d\n",ret);
    //2、猜数字
    while(1)
    {
        printf("请输入你猜测的数字>：");
        scanf("%d",&guess);
        if(guess<ret)
        {
            printf("猜小了！\n\n");
            count++;
        }
        else if(guess>ret)
        {
            printf("猜大了！\n\n");
            count++;
        }
        else
        {
            printf("恭喜你猜对了！你一共猜测了%d次。\n\n",count+1);
            break;
        }
    }
}

void menu(){
    printf("**************************************\n");
    printf("*****  1、开始游戏  0、退出游戏  *****\n");
    printf("**************************************\n");
}
//猜数字的游戏
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));  //拿时间戳来设置随机数的生成起始点
    do
    {
        menu();
        printf("请选择>：");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("关闭游戏!\n");
                break;
            default:
                printf("输入错误!\n");
                break;
        }
    } 
    while (input);   //do while 适用于最少执行一次的操作
    return 0;
}

// //9*9乘法表
// int main()
// {
//     int i = 0;
//     //确定多少行
//     for (i = 1; i <= 9;i++)
//     {
//         int j = 0;
//         //打印一行
//         for (j = 1; j <= i;j++)
//         {
//             printf("%d*%d=%-2d ",i,j,i*j);   //i*j占两个字节，-表示左对齐，不加-右对齐
//         }
//         printf("\n"); //打印完一行
//     }
// }

// int main()
// {
//     int i = 0;
//     for (i = 2; i < 10;i++)
//     {
//         break;   //i没有调整,执行break语句，跳出循环，i没有加1
//     }
//     printf("%d",i);  //输出2
//     return 0;
// }

// //打印100-200的素数
// int main()
// {
//     int i = 0;
//     int count = 0;
//     for (i = 101; i <= 200;i+=2)  //大于2的偶数不是素数
//     {
//         //判断是否为素数 
//         //试除法  2-sqrt(i)
//         int j = 0;
//         for (j = 2; j <= sqrt(i) ;j++)  //sqrt()开平方的数学库函数
//         {                               //如果i是不素数，i=a*b中至少有一个数<=开平方i 
//             if(i%j==0)                  //只要求出一个数能整除i就能说明i不是素数（要考量2-sqrt(i)的范围）
//             {
//                 break;
//             }
//         }
//         if(j>sqrt(i))
//         {
//             printf("%d ",i);
//             count++;
//         }
//     }
//     printf("\ncount=%d",count);
//     return 0;
// }

// //打印1000年到2000年的闰年
// int main()
// {
//     int year = 0;
//     int count = 0;
//     for (year = 1000; year <= 2000;year++)
//     {
//         if((0==year%4 && year%100!=0) || (0==year%400))  //闰年：1、能被4整除不能被100整除2、能被400整除
//         {
//             printf("%d ",year);
//             count++;
//         }
//     }
//     printf("\n%d",count);
//     return 0;
// }

// //求两个数的最大公约数
// int main()
// {
//     int a, b, tmp;
//     printf("输入两个整数：");
//     scanf("%d %d",&a,&b);
//     if(a<b)
//     {
//         int c = a;
//         a = b;
//         b = c;
//     }
//     while(tmp=a%b)
//     {
//         a = b;
//         b = tmp;
//     }
//     printf("最大公约数为：%d",b);
//     return 0;
// }

// //三个数字排序输出
// int main()
// {
//     int a, b, c;
//     int tmp;
//     printf("请输入你要输入的三个数字：\n");
//     scanf("%d %d %d",&a,&b,&c);
//     if(a<b)
//     {
//         tmp = a;
//         a = b;
//         b = tmp;
//     }
//     if(a<c)
//     {
//         tmp = a;
//         a = c;
//         c = tmp;
//     }
//     if(b<c)
//     {
//         tmp = b;
//         b = c;
//         c = tmp;
//     }
//     printf("%d %d %d",a,b,c);
// }

// int main()
// {
//     int k=1;
//     int b=0;
//     switch(k)
//     {

//         case 1:
//             b=1;           //执行完符合条件的case，如果没有break，后面所有的case都会执行。
//             printf("1\n"); //如果default在后面则default里面的语句也执行，否则则不执行；        
//         case 2:
//             b=2;
//             printf("2\n");
//         case 3:
//             b=3;
//             printf("3\n");
//         default:
//             b=4;
//             printf("4\n");  //如果放在第一个，则最终的b输出结果为3
//     }
//     printf("%d\n",b);
//     return 0;
// }