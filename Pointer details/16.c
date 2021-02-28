#include<stdio.h>
#include<assert.h>
// int main()
// {
//     const char *p1 = "abcdef";
//     const char *p2 = "abcdef";  //常量字符串 *p不能改变
//     char arr[] = "abcdef";
//     char *p3 = arr;
//     printf("%p\n", p1);
//     printf("%p\n", p2);
//     printf("%p\n", p3);
//     return 0;
// }


//地址的总结
// int main()
// {
//     int arr[3][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
//     printf("%p\n", arr);     //整个数组首元素的地址
//     printf("\n");

//     printf("%p\n", arr[0]);  //第一行首元素的地址
//     printf("%p\n", &arr[0][0]);
//     printf("%p\n", arr[1]);  //第二行首元素的地址
//     printf("%p\n", &arr[1][0]);
//     printf("%p\n", arr[2]);  //第三行首元素的地址
//     printf("%p\n", &arr[2][0]);
//     printf("\n");

//     printf("%p\n", &arr[0]);   //整个arr[0]([0]-[2])的地址  第一行数组的整个地址 跳过一行数组的地址
//     printf("%p\n", &arr[0]+1); //整个arr[1]([0]-[2])的地址  第二行数组的整个地址
//     printf("%p\n", &arr[0]+2); //整个arr[2]([0]-[2])的地址  第三行数组的整个地址
//     printf("\n");

//     printf("%p\n", &arr);   //整个数组的地址
//     printf("%p\n", &arr + 1);  //首元素地址加上 9*4==36 跳过整个数组地址
//     printf("\n");
//     return 0;
// }



// //函数指针  --指向函数地址的指针
// int Add(int x,int y)
// {
//     return x + y;
// }
// void Print(char *s)
// {
//     printf("%s\n", s);
// }
// int main()
// {
//     //函数名 和 &函数名 都是函数的地址
//     printf("%p\n", Add);
//     printf("%p\n", &Add);
//     printf("\n");
//     //函数指针
//     //1、类型为 int (*)(int,int)
//     int (*p)(int, int) = Add;  // int--函数的返回类型 （*p）--变量为指针  (int ,int)--函数参数类型
//     printf("%p\n", p);
//     printf("%d\n", (*p)(4, 7));  //11==4+7
//     printf("%d\n", p(4, 7));     //11==4+7
//     printf("\n");

//     //2、类型为 void (*)(char *)
//     void (*pa)(char *) = Print;// void--函数的返回类型 （*pa）--变量为指针  (char *)--函数参数类型
//     (*pa)("abcdef");    //输出abcdef

//     return 0;
// }


// int main()
// {
//     (*  (void (*)(void)) 0  ) ();

//     //void (*signal(int, void (*)(int)))(int);
//     typedef void (*pfun_t)(int);
//     pfun_t signal(int, pfun_t);

//     return 0;
// }

// typedef int arr[2];
// int main()
// {
//     arr a = {1, 2};
//     printf("%d", a[0]);
//     printf("%d", a[1]);
//     return 0;
// }


// //函数指针的数组
// int Add(int x,int y)
// {
//     return x + y;
// }
// int Sub(int x,int y)
// {
//     return x - y;
// }
// int Mul(int x,int y)
// {
//     return x * y;
// }
// int Div(int x,int y)
// {
//     return x / y;
// }

// int main()
// {
//     //int *arr[5];  //指针数组
//     //int (*pa)(int, int) = Add;
//     //需要一个数组，这个数组可以存放4个函数的地址， -函数指针 的数组
//     int (*parr[4])(int, int) = {Add, Sub, Mul, Div};
//     int i = 0;
//     for (i = 0; i < 4;i++)
//     {
//         printf("%d\n", parr[i](2, 3)); //5 -1 6 0
//     }
//     return 0;
// }



// //函数指针数组 --练习
// char* my_strcpy(char *dest,const char * src)
// {
//     char *dests = dest;
//     assert(dest != NULL);
//     assert(src != NULL);
//     while ((*dest++ = *src++))
//     {
//         ;
//     }
//     return dests;
// }
// int main()
// {
//     char arr[5] = "****";
//     //函数指针
//     char *(*pf)(char *, const char *) = my_strcpy;
//     printf("%s\n", pf(arr,"1234"));
//     printf("%s\n", arr);
//     //函数指针数组
//     char *(*pfArr[4])(char *, const char *) = {my_strcpy, my_strcpy, my_strcpy, my_strcpy};
//     int i = 0;
//     int j = 0;
//     char src[5] = {0};
//     for (i = 0; i < 4;i++)
//     {
//         for (j = 0; j <= i;j++)
//         {
//             src[j] = j + '0';
//         }
//         src[j] = 0;
//         printf("%s\n", pfArr[i](arr, src));
//     }

//     return 0;
// }


//函数指针数组的使用案例
//实现一个计算器
int Add(int x,int y)
{
    return x + y;
}
int Sub(int x,int y)
{
    return x - y;
}
int Mul(int x,int y)
{
    return x * y;
}
int Div(int x,int y)
{
    return x / y;
}
int Xor(int x,int y)
{
    return x ^ y;
}

void menu()
{
    printf("*************************\n");
    printf("***** 1,add  2,sub  *****\n");
    printf("***** 3,mul  4,div  *****\n");
    printf("***** 5,xor  0,exit *****\n");
    printf("*************************\n");
}
int main()
{
    int input = 0;
    int x = 0;
    int y = 0;
    int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        if (input >= 1 && input <= 5)
        {
            printf("请输入两个操作数:>");
            scanf("%d%d", &x, &y);
            printf("%d\n", pfArr[input](x, y));
        }
        else if (input == 0)
        {
            printf("退出！\n");
        }
        else
        {
            printf("输入错误！\n");
        }
    } while (input);
    return 0;
}
// int main()
// {
//     int input = 0;
//     int x = 0;
//     int y = 0;
//     do
//     {
//         menu();
//         printf("请选择：>");
//         scanf("%d", &input);
//         printf("请输入两个操作数:>");
//         scanf("%d%d", &x, &y);
//         switch(input) 
//         {
//             case 1:
//                 printf("%d+%d=%d\n", x, y, Add(x, y));
//                 break;
//             case 2:
//                 printf("%d-%d=%d\n", x, y, Sub(x, y));
//                 break;
//             case 3:
//                 printf("%d*%d=%d\n", x, y, Mul(x, y));
//                 break;
//             case 4:
//                 printf("%d/%d=%d\n", x, y, Div(x, y));
//                 break;
//             case 0:
//                 printf("退出！");
//                 break;
//             default:
//                 printf("选择错误！");
//                 break;
//         }
//     } while (input);
//     return 0;
// }