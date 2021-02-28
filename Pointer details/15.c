#include<stdio.h>


// int main()
// {
//     const char *p = "abcdef"; //常量字符串
//     printf("%s\n", p);
//     p = "abcde";
//     printf("%s\n", p);
//     return 0;
// }

// int main()
// {
//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     const char *p1 = "abcdef";  //指向同一个常量字符串
//     const char *p2 = "abcdef";  //指向同一个常量字符串
//     if (p2 == p1)
//     {
//         printf("hehe\n");  //打印hehe
//     }
//     else
//     {
//         printf("haha\n");
//     }

//     // if (arr1 == arr2)
//     // {
//     //     printf("hehe\n");
//     // }
//     // else
//     // {
//     //     printf("haha\n");
//     // }
//     return 0;
// }


////指针数组
// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 0};  //从栈区高地址开始使用
//     int arr2[] = {2, 3, 4, 5, 6, 7, 0};
//     int arr3[] = {3, 4, 5, 0};
//     int *parr[] = {arr3, arr2, arr1};
//     int i = 0;
//     int j = 0;
//     int val = 0;
//     for (i = 0; i < 3;i++)
//     {
//         j = 0;
//         while ((val = *(parr[i] + j)))
//         {
//             printf("%d ", val);
//             j++;
//         }
//         printf("\n");
//     }
//     printf("\n");

//     for (i = 0; i < 3;i++)
//     {
//         for (j = 0; j < 20;j++)
//         {
//             printf("%d ", *(parr[i] + j));
//         }
//         printf("\n");
//     }
//     printf("\n");

//     for (i = 0; i < 3;i++)
//     {
//         for (j = 0; j < 9;j++)
//         {
//             printf("%d ", *(*(parr + i) + j));
//         }
//         printf("\n");
//     }
//     return 0;
// }


// //数组指针
// int main()
// {
//     int *P = NULL; //p是整型指针-指向整型的指针 - 存放整型的地址
//     char *pc = NULL;//pc是字符指针-指向字符的指针 - 存放字符的地址
//     //什么是数组指针 --指向数组的指针 - 存放数组的地址
//     //int arr[10]={0};
//     //arr- 和 &arr[0] 首元素的地址
//     //&a- 数组的地址

//     //数组指针
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int(*p)[10] = &arr; //数组的指针要存起来    
//     return 0;
// }


// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 0};  //从栈区高地址开始使用
//     int arr2[] = {2, 3, 4, 5, 6, 7, 0};
//     int arr3[] = {3, 4, 5, 0};
//     int *parr[3] = {arr3, arr2, arr1}; //指针数组

//     int *(*pa)[3] = &parr;

//     int i = 0;
//     int val = 0;
//     int j = 0;
//     for (i = 0; i < 3;i++)
//     {
//         j = 0;
//         while ((val = *(*((*pa) + i) + j)))  //(*pa)[i][j]
//         {
//             printf("%d ", val);
//             j++;
//         }
//         printf("\n");
//     }
//     return 0;
// }


//参数是数组的形式
void print1(int arr[][5],int x,int y)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < x;i++)
    {
        for (j = 0; j < y;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
//参数是指针的形式
void print2(int (*p)[5],int x,int y)  //一整行的地址，五个int类型的元素 --数组指针
{
    int i = 0;
    int j = 0;
    for (i = 0; i < x;i++)
    {
        for (j = 0; j < y;j++)
        {
            printf("%d ", *(*(p + i) + j));
            //printf("%d ", (*(p + i))[j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[3][5] = {{1, 2, 3, 4, 5}, {4, 2, 5, 7, 2}, {2, 5, 7, 8, 9}};
    printf("%d\n", **arr);
    printf("%d\n" ,* *(arr + 1)); //arr是二维数组一整行的地址
    printf("%d\n", *(*arr + 1));

    print1(arr, 3, 5);
    print2(arr, 3, 5);
    return 0;
}