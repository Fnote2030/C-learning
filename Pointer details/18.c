#include<stdio.h>
#include<stdlib.h>

// int main()
// {
//     char *p = "abcdef";
//     printf("%c\n", p[0]);     //a
//     printf("%c\n", *(&p[0]+1));  //b

//     int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
//     printf("%p\n", a);  //a数组中第一个元素的地址 ，一行所有元素为一个元素
//     printf("%p\n", a + 1);  //第二个元素的地址 ，第二行的地址，一行所有元素为一个元素
//     printf("%d\n", (int)sizeof(*(a + 1))); //第二行的大小
//     printf("%d\n", **(a + 1));  //第二行首元素

//     printf("%p\n", *a);  //第一行的首元素的地址 ，*a表示第一行，不在sizeof()里面，不与&相连，表示首元素地址
//     printf("%d\n", (int)sizeof(*a)); //第一行的大小

//     printf("%d\n", (int)sizeof(a[3])); //第四行的大小
//     return 0;
// }


//指针面试题

// //第一题
// int main()
// {
//     int a[5] = {1, 2, 3, 4, 5};
//     int *ptr = (int *)(&a + 1);
//     int(*parr)[5] = &a;  //数组指针
//     printf("%d,%d\n", *(a + 1), *(ptr - 1));
//     printf("%d\n", *((int *)(parr + 1)-1));
//     return 0;
//}

////第二题
// int main()
// {
//     int a[] = {1, 2, 3, 4};
//     int *ptr1 = (int *)(&a + 1);  //数组最后一个元素的地址加4
//     int *ptr2 = (int *)((int)a + 1);  //首元素加一个字节  0x00000001 0x00000002  01 (00 00 00 02) 00 00 00
//     printf("%x,%x\n", ptr1[-1], *ptr2); //4
//     return 0;
// }

// //第三题
// int main()
// {
//     int a[3][2] = {(0, 1), (2, 3), (4, 5)};  //初始化  1,3,5,0,0,0
//     int *p;
//     p = a[0]; //
//     printf("%d\n", p[0]); //*(p+0)
//     return 0;
// }

// //第四题
// int main()
// {
//     int a[5][5];
//     int(*p)[4];
//     p = a;
//     //地址-地址等于它们之间的元素个数 ，小-大求的是负数
//     //以地址形式打印直接输出补码
//     //10......0000 0100
//     //11......1111 1011
//     //11......1111 1100
//     //ffff ffff ffff fffc  64位
//     printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//     return 0;
// }


// //第五题
// int main()
// {
//     int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int *ptr1 = (int *)(&aa + 1);
//     int *ptr2 = (int *)(*(aa + 1));//右边：(int *)(aa+1) 或者 (*(aa+1))
//     printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
//     return 0;
// }

// //第六题
// int main()
// {
//     char *a[] = {"work", "at", "alibaba"};
//     char **p = a;
//     p++;
//     printf("%s\n", *p);  //*p == a[1] == *(a+1)
//     //printf("%s\n", *(a + 1));
//     return 0;
// }


//第七题
int main()
{
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp + 3);
    printf("%s\n", *cpp[-2] + 1);
    printf("%s\n", cpp[-1][-1] + 1);
    return 0;
}