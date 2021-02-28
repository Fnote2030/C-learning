#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


// //1、其他函数中动态内存的开辟
// void GetMemory(char **str)
// {
//     *str = (char *)malloc(20 * sizeof(char));
// }
// void Test()
// {
//     char *str = NULL;
//     GetMemory(&str);
//     strcpy(str, "hello world");
//     printf("%s\n",str);

//     free(str);
//     str = NULL;
// }
// int main()
// {
//     Test();
//     return 0;
// }



// //2、
// //  使用指针前判断是否可用   
// //  释放空间之后应该将指向该空间的指针置为NULL 
// void Test()
// {
//     char *str = (char *)malloc(100);
//     strcpy(str, "hello");
//     free(str);  //释放空间之后应该将指向该空间的指针置为NULL  连体使用
//     str = NULL;
//     if(str != NULL)
//     {
//         strcpy(str, "world");
//         printf(str);
//     }
// }
// int main()
// {
//     Test();
//     return 0;
// }



// //柔性数组成员
// typedef struct S
// {
//     int n;
//     int arr[];  //未知大小--柔性数组成员,数组的大小是可以调整的
// } S;

// int main()
// {
//     // S s;  
//     // printf("%d\n", (int)sizeof(s));//4   柔性数组成员不占空间

//     S *ps = (S *)malloc(sizeof(S) + 5 * sizeof(int));
//     printf("%d\n", (int)sizeof(*ps));

//     ps->n = 100;
//     int i = 0;
//     for (i = 0; i < 5; i++)
//     {
//         ps->arr[i] = i;
//     }   

//     //ps指针类型还是S，加1还是向后访问4个字节
//     //printf("%p\n", ps);
//     //printf("%p\n", ps + 1);
//     //printf("%d\n", *ps);     //100
//     //printf("%d\n", *(ps + 2));     //1
   
//     S *str = realloc(ps, 44);   //调整柔性数组的大小，调整为44-4个字节大小
//     if(str!=NULL)
//     {
//         ps = str;
//         str = NULL;
//         for (i = 5; i < 10; i++)
//         {
//             ps->arr[i] = i;
//         }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", ps->arr[i]);
//         }
//     }
//     else
//     {
//         //空间调整失败
//         for (i = 0; i < 5; i++)
//         {
//             printf("%d ", ps->arr[i]);
//         }
//     }
//     return 0;
// }


//能实现和柔性数组功能相同的操作
typedef struct S
{
    int n;
    int *arr;
} S;

// int main()
// {
//     S *p = (S *)malloc(sizeof(struct S));
//     p->n = 100;
//     p->arr = (int *)malloc(10 * sizeof(int));
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {

//         p->arr[i] = i;
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", p->arr[i]);
//     }
//     //释放
//     free(p->arr);
//     p->arr = NULL;
//     free(p);
//     p = NULL;
//     return 0;
// }

int main()
{
    S p;  //定义S类型的变量p
    p.n = 100;
    p.arr = (int *)malloc(10 * sizeof(int));
    //成功开辟动态空间
    if(p.arr!=NULL)
    {
        int i = 0;
        for (i = 0; i < 10; i++)
        {
        p.arr[i] = i;
        }
        for (i = 0; i < 10; i++)
        {
        printf("%d ", p.arr[i]);
        }
    }
    else
    {
        //没有开辟成功
        printf("%s\n", strerror(errno));
    }
    
    //释放空间
    free(p.arr);
    p.arr = NULL;
    return 0;
}