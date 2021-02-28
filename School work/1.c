#include<stdio.h>
#include<math.h>
#include<string.h>

// //求自幂数
// int main()
// {
//     int i = 0;
//     for (i = 0; i <= 100000;i++)
//     {
//         //计算i的位数--n位数
//         int n = 1;
//         int a = i;
//         int sum = 0;
//         while (a /= 10)
//         {
//             n++;
//         }
//         //计算每一位的n次方之和 sum
//         a = i;
//         while(a) 
//         {
//             sum += pow(a % 10, n);
//             a /= 10;
//         }
//         //比较 sum == i
//         if(i==sum)
//         {
//             printf("%-6d", i);
//         }
//     }
//     return 0;
// }


// //输出菱形的*
// int main()
// {
//     int n = 0;
//     int i = 0;
//     printf("请输入上面部分的行数：\n");
//     scanf("%d", &n);
//     //打印上半部分
//     for (i = 0; i < n;i++)
//     {
//         int j = 0;
//         //空格
//         for (j = 0; j < n - 1 - i; j++)
//         {
//             printf(" ");
//         }
//         //*
//         for (j = 0; j < 2 * i + 1; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     //打印下半部分
//     for (i = 0; i < n - 1; i++)
//     {
//         int j = 0;
//         //空格
//         for (j = 0; j <= i; j++)
//         {
//             printf(" ");
//         }
//         //*
//         for (j = 0; j < 2 * (n - 1 - i) - 1; j++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }



// //喝汽水，一瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶汽水？
// int main()
// {
//     int empty = 0;
//     int total = 0;
//     int momey = 0;
//     printf("一共给多少钱：\n");
//     scanf("%d", &momey);
//     //
//     //买回来的
//     total = momey;
//     empty = momey;
//     //换回来的
//     while(empty>1)
//     {
//         total += empty / 2;
//         empty = empty / 2 + empty % 2;
//     }

//     printf("%d\n", total);
//     return 0;
// }


// //整型提升
// int main()
// {
//     unsigned char a = 200;
//     unsigned char b = 400;  //400-256 == 144
//     unsigned char c = 0;
//     c = a + b;  //344 - 256 == 88
//     printf("%d %d\n", a + b, c);
//     return 0;
// }


// //-127 10000001
// //-128 10000000
// //127  01111111
// //-1   11111111
// //127== -128+(-1)
// int main()
// {
//     char a[1000] = {0};
//     int i = 0;
//     for (i = 0; i < 1000;i++)
//     {
//         a[i] = -1 - i;   //127 == -128+(-1)
//     }
//     printf("%d\n", (int)strlen(a));
//     return 0;
// }



// //输出杨辉三角
// //        1
// //       1  1
// //      1  2  1
// //     1  3  3  1
// //    1  4  6  4  1

// // 1
// // 1  1
// // 1  2  1
// // 1  3  3  1
// // 1  4  6  4  1
// int main()
// {
//     int arr[10][10] = {0};
//     int i = 0;
//     int j = 0;
//     for (i = 0; i < 10;i++)
//     {
//         for (j = 0; j <= i; j++)
//         {
//             if (0 == j)
//             {
//                 arr[i][j] = 1;
//             }
//             if (i == j)
//             {
//                 arr[i][j] = 1;
//             }
//             if (i >= 2 && j >= 1)
//             {
//                 arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//             }
//         }
//     }
//     for (i = 0; i < 10;i++)
//     {
//         for (j = 0; j <= i;j++)
//         {
//             printf("%-4d", arr[i][j]);
//         }
//         printf("\n");
//     }
//         return 0;
// }


// //谁是凶手
// //a:凶手不是我，  b:凶手是c,   c:凶手是d,   d:c说的是假话
// int main()
// {
//     int killer = 0;
//     for (killer = 'a'; killer <= 'd'; killer++)  //逐个假设为凶手
//     {
//         //说真话为三人时，假设的凶手为真凶手
//         if (((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3)
//         {
//             printf("凶手是%c\n", killer);
//             break;
//         }
//     }
//     return 0;
// }



//5个远动员参加十米台跳水比赛，有人让他们预测比赛结果。
//a:b第二，我第一
//b:我第二，e第四
//c:我第一，d第二
//d：c最后，我第三
//e：我第四，a第一
//比赛结束后，每个选手都说对了一半，请确定他们的排名
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    for (a = 1; a <= 5;a++)
    {
        for (b = 1; b <= 5; b++)
        {
            for (c = 1; c <= 5; c++)
            {
                for (d = 1; d <= 5; d++)
                {
                    for (e = 1; e <= 5; e++)
                    {
                        if (((b == 2) + (a == 3) == 1) &&
                            ((b == 2) + (e == 4) == 1) &&
                            ((c == 1) + (d == 2) == 1) &&
                            ((c == 5) + (d == 3) == 1) &&
                            ((e == 4) + (a == 1) == 1))
                        {
                            if(a*b*c*d*e==120)
                            {
                                printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
                                printf("\n"); 
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

