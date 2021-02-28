#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stddef.h>
/*
        《C语言预处理》
    1、编译 
        (1)编译
            a、预处理/编译      -> 文件操作      >>.i文件        (gcc -E *.c)
            b、编译            -> 翻译成汇编代码 >>.s文件        (gcc -S *.i)
            c、汇编(二进制指令) -> 形成符号表     >>.o文件        (gcc -c *.s)
        (2)链接  >> 可执行程序
            a、合并段表
            b、符号表的合并和重定位（多个.o文件之间的处理）
    2、运行
*/

/*
    __FILE__    当前.c文件的绝对路径
    __LINE__    当前的行号
    __DATE__    执行的日期
    __TIME__    执行的时间
    __STDC__    如果定义了，值为1
*/

// //预编译
// int main()
// {
//     FILE *log = fopen("log.txt", "w");
//     if(log==NULL)
//     {
//         perror("open log.txt");
//     }
//     int i = 0;
//     int arr[10] = {0};
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
//         fprintf(log, "data=%s time=%s\n", __TIME__, __DATE__);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     //printf("%d\n", __STDC__);  输出1
//     fclose(log);
//     log == NULL;
//     return 0;
// }


// //宏定义不是传参的而是完全替换的
// //如果宏替代的是表达式，表达式都加上括号
// 宏的名字使用大写的字母

// //#define SQUARE(X) (X)*(X)
// #define SQUARE(X) ((X)*(X))
// //#define SQUARE(X) X*X

// int main()
// {
//     int ret = SQUARE(5 + 1);  //X*X 输出11==5+1*5+1         (X)*(X) 输出36==(5+1)*(5+1)
//     int n = 50 / SQUARE(5);   //(X)*(X) 输出50==50/(5)*(5)  ((X)*(X)) 输出2==50/((5)*(5))

//     printf("%d\n", ret);
//     printf("%d\n", n);
//     return 0;
// }



// //把宏的参数传到字符串中
// #define PRINT(X) printf(""#X"=%d\n",X)   //#X 是X要代替的数字的字符型表示形式 "a" / "b"
//                                          //而 ""两端的字符是连接在一起的
// int main()
// {
//     int a = 10;
//     int b = 20;
//     PRINT(a);
//     PRINT(b);
//     printf("hello "       "bit\n");   //字符串中的 ""两端的字符是默认连接在一起的
//     printf("hello " "er" " bit\n");
//     return 0;
// }


// //##会将两端的符号连成一个符号
// #define CAT(X,Y) (X##Y)
// int main()
// {
//     int val88 = 2021;
//     //printf("%d\n", val88);  //2021
//     printf("%d\n", CAT(v, al88)); //(v##al88) == (val88) ==val88
//     return 0;
// } 



// //求两个数的较大值
// //宏是直接完全替换的，不是算好再替换的
// #define MAX(X,Y)  ((X)>(Y))?(X):(Y)
// int main()
// {
//     int a = 10;
//     int b = 11;
//     int max = MAX(a++, b++);//12
//     //int max=((a++)>(b++))?(a++):(b++)    //因为a>b 所有b++执行了两次 ，a++执行了一次
//     printf("%d\n", max);
//     printf("%d\n", a);  //11
//     printf("%d\n", b);  //13
//     return 0;
// }


//宏的优点
//
// #define MAX(X,Y)  ((X)>(Y))?(X):(Y)
// int Max(int x,int y)
// {
//     return x > y ? x : y;
// }
// int main()
// {
//     int a = 10;
//     int b = 11;
//     //不用准备工作
//     int max = MAX(a, b);

//     //函数在调用和返回会有额外的开销
//     //函数的参数必须声明为特定的类型
//     int max2 = Max(a, b);
//     printf("%d\n", max);
//     printf("%d\n", max2);
//     return 0;
// }

// //宏可以传递类型
// #define MALLOC(num,type) (type *)malloc(num*sizeof(type))
// int main()
// {
//     int *p = malloc(10 * sizeof(int));

//     int *p2 = MALLOC(10, int); //宏传递类型
//     return 0;
// }


// //移除一个宏定义
// #define MAX 10
// int main()
// {
//     printf("%d\n", MAX);
//     return 0;
// }
// // #define MAX 10
// // #undef MAX
// // int main()
// // {
// //     printf("%d\n", MAX);
// //     return 0;
// // }



//条件编译指令  判断是否参加编译
/*
    1、#if
    2、#ifdef

    3、#if 表达式
       #elif 表达式
       #else
       #endif

    4、#ifdef  宏名字   //==#if defined(宏名字)
       #endif

    5、#ifndef  宏名字   //==#if !defined(宏名字)
       #endif
*/
// #define PRINT
// int main()
// {
//     int a = 10;
//     int b = 20;
//     //1、
//     #ifdef PRINT
//     printf("%d\n", a);  //条件编译，定义了PRINT,这行代码参与编译
//     #endif

//     //2、
//     #if 1   //条件为真下面的代码参与编译
//     printf("%d\n", b);
//     #endif

//     return 0;
// }



// // 防止头文件多次包含
// //1、
// // #ifndef __TEST_H__
// // #define __TEST_H__
// // int Add(int x, int y);
// // #endif
// //2、
// #pragma once
// int Add(int x, int y);



//使用宏定义返回结构体中某个变量的偏移量
//不能创建结构体变量
struct S
{
    char c;  //0
    int i;   //4
    double d;  //8
};
//将结构体的地址置为0，结构体其他变量的地址减去0等于偏移量

#define OFFSETOF(struct_name,member_name)  (int)&(((struct_name *)0)->member_name)
int main()
{
    int ret = OFFSETOF(struct S, d);
    printf("%d\n", ret);

    printf("%d\n", (int)offsetof(struct S, d));
    return 0;
}