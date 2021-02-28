#include<stdio.h>
#include<assert.h>
#include<string.h>
// //const在指针变量中的使用
// int main()
// {
//     int num = 10;
//     int n = 20;
//     //1、const放在指针变量的*左边的时候，修饰的是*p，也就是说不能通过p来改变*P（num）的值。
//     const int *p = &num;
//     //*p = 20;    //*p只能读取，不能改变，此处编译不通过
//     p = &n;
//     printf("%d\n", *p); 

//     // //2、const放在指针变量的*右边的时候，修饰的是p，p不能被改变了
//     // int *const p = &num;
//     // *p = 20;
//     // //p = &n;  //p只能读取，不能改变，此处编译不通过
//     // printf("%d\n", *p);

//     //也可以两个位置同时使用
//     return 0;
// }





// //字符串拷贝 ，逐渐完善
// // //1
// // void my_strcpy(char *dest,char *src)
// // {
// //     if (dest != NULL && src != NULL)  //跳过
// //     {
// //         while ((*dest++ = *src++))
// //         {
// //             ;
// //         }
// //     }
// // }
// // //2
// // void my_strcpy(char *dest,char *src)
// // {
// //     assert(dest != NULL);
// //     assert(src != NULL);  //断言
// //     while ((*dest++ = *src++))
// //     {
// //         ;
// //     }
// // }
// // //3
// // void my_strcpy(char *dest,const char *src)  //const修饰，*src不能被改变
// // {
// //     assert(dest != NULL);
// //     assert(src != NULL);
// //     while ((*dest++ = *src++))  //加了const，写反编译器会报错
// //     {
// //         ;
// //     }
// // }
// //3
// char *my_strcpy(char *dest, const char *src) //const修饰，*src不能被改变 //返回值类型位char *
// {
//     char *ret = dest;  //目的字符串首地址存储起来
//     assert(dest != NULL);
//     assert(src != NULL);   //断言，里面的表达式不为真，编译不通过
//     while ((*dest++ = *src++))  //加了const，写反编译器会报错
//     {
//         ;
//     }
//     return ret;  //返回目的字符串首地址
// }

// int main()
// {
//     char arr1[]="****************";
//     char arr2[] = "hello world!";
//     my_strcpy(arr1, arr2);
//     printf("%s\n", arr1);

//     printf("%s\n", my_strcpy(arr1, arr2));
//     return 0;
// }



// //大小端模式的判断
// int check_sys(void)
// {
//     int a = 1;
//     // char *p = (char *)&a;
//     // if (1 == *p)
//     // {
//     //     return 1;//小端模式
//     // }
//     // else
//     // {
//     //     return 0;//大端模式
//     // }
//     //小端返回1；大段返回0
//     return *(char *)&a;
// }

// int main()
// {
//     //判断当前机器的字节序是什么
//     if(check_sys())
//     {
//         printf("小端模式\n");
//     }
//     else 
//     {
//         printf("大端模式\n");
//     }
//     return 0;
// }


// int main()
// {
//     // unsigned int i = 0;
//     // printf("%u\n", i - 1);  //2^32-1  //11111111 11111111 11111111 11111111

//     // unsigned char i = -1;  //11111111 11111111 11111111 11111111->11111111
//     // printf("%d\n", i);     //00000000 00000000 00000000 11111111 补码

//     char i = -129;
//     printf("%u\n", i);
//     return 0;              
// }


// //-126 10000010
// //-127 10000001 
// //-128 10000000
// //127  01111111   //-128+(-1) ==127
// //-1   11111111
// int main() 
// {
//     int i = 0;
//     char a[1000] = {0};
//     for (i = 0; i < 1000;i++)
//     {
//         a[i] = -1 - i;   //-128-1 == 127
//     }
//     printf("%d\n", (int)strlen(a));
//     return 0;
// }


int main()
{
    int n = 9;
    //00000000 00000000 00000000 00001001 -补码
    float *pFloat = (float *)&n;
    printf("n的值为：%d\n", n);
    //0  00000000  00000000000000000001001 -补码
    //s==0;M==0.00000000000000000001001;E==-126
    //(-1) ^ 0 * 0.00000000000000000001001 * 2 ^ -126;  无限接近0
    printf("*pFloat的值为：%f\n", *pFloat);  //打印0.0000000
    printf("\n");


    *pFloat = 9.0;
    //1001.0
    //1.001 * 2 ^ 3 == (-1) ^ 0 * 1.001 * 2 ^ 3;
    //0 10000010 0010000 00000000 00000000 
    printf("n的值为：%d\n", n); ////0 10000010 0010000 00000000 00000000 补码   1091567616 十进制
    printf("*pFloat的值为:%f\n", *pFloat);
    return 0;
}
