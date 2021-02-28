#include<stdio.h>
#include<stdlib.h>


// //                《枚举》
// //                 enum
// //枚举类型   大小是四个字节

// enum Sex
// {
//     //枚举的可能取值  
//     //1、不赋值，默认从0开始逐渐加1递增
//     //2、赋值的等于赋值的，没赋值的等于上一个取值加一
//     //3、这里面赋初值，之后不能更改
//     //4、用,分开,只能是整数
//     MALE,         //0
//     FEMALE=3,     //3
//     SECRET        //4
// };

// int main()
// {
//     enum Sex s = MALE;    //只能拿枚举类型{}里面的可能取值赋值；
//     printf("%d %d %d\n", MALE, FEMALE, SECRET);
//     printf("%d\n", (int)sizeof(s));  //四个字节大小
//     return 0;
// }





// //          《联合/共用体》
// //
// union Un
// {
//     char c;
//     int i;
// };
// int main()
// {
//     union Un u;
//     //大小 --
//     1、至少是最大成员的大小
//     2、最大对齐数的倍数
//     printf("%d\n", (int)sizeof(u));
//     //地址 --- 共用同一块空间
//     printf("%p\n", &u);
//     printf("%p\n", &u.i);
//     printf("%p\n", &u.c);
//     return 0;
// }


// //判断当前电脑大小端
// int check_sys()
// {
//     union Un
//     {
//         char c;
//         int i;  //共用同一个空间，从低地址开始共用
//     }u;  
//     u.i = 1;    
//     return u.c;
// }
// int main()
// {
//     int ret = check_sys();
//     if(1 == ret)
//     {
//         printf("小端模式！");
//     }
//     else
//     {
//         printf("大端模式！");
//     }
//     return 0;
// }

//联合体的大小
union Un
{
    int i;  //对齐数4
    char a[5]; //对齐数 1
};
int main()
{
    union Un u;
    printf("%d\n", (int)sizeof(u));  //最大对齐数为4
    return 0;
}