#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>

/*
            《calloc》
    void *calloc(size_t num,size_t,size)
    num -- 开辟的空间的有多少个元素
    size -- 每个元素的大小（单位字节）
    成功返回开辟好的空间的首地址，失败返回NULL
    空间的每个字节初始化为 0
*/
// int main()
// {
//     int *p = (int *)calloc(10, sizeof(int));
//     if(p==NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//     }
//     free(p);
//     p = NULL;
//     return 0;
// }

//常见的错误

int main()
{
    // //1、对NULL指针解引用操作
    // int *p = malloc(40);
    // //空间可能开辟失败，返回NULL
    // if(p!=NULL)
    // {
    //     *p = 10;
    // }
    // //释放空间
    // free(p);
    // p = NULL;

    // //2、对动态开辟内存的越界访问
    // int *p = calloc(5, sizeof(int));
    // *(p + 5) = 10;   //越界访问
    // //释放空间
    // free(p);
    // p = NULL;

    //3、对动态开辟的内存使用free释放
    // int a = 10;
    // int *p = &a;
    // free(p);
    // p = NULL;

    // //4、使用free释放动态开辟内存的一部分 （p只能是开辟的动态内存的首地址）
    // int *p = (int *)malloc(10 * sizeof(int));
    // if(p==NULL)
    // {
    //     return 0;
    // }
    // int i = 0;
    // for (i = 0; i < 5; i++)
    // {
    //     *p++ = i;  //p改变了
    // }
    // //回收空间
    // free(p);
    // p = NULL;

    //5、对同一块动态内存多次释放
    int *p = (int *)malloc(10 * sizeof(int));
    if(p==NULL)
    {
        return 0;
    }
    //释放
    free(p);
    //p = NULL; //很有必要，指向NULL,再次free，就不会产生多次释放
    free(p);
    p = NULL;

    //6、开辟空间，不释放空间（内存泄漏）

    return 0;
}