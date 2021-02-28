#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>

/*
            《realloc》
    void *realloc(void * memblock,size_t size);
    memblock 之前开辟的内存块
    size  调整之后的新的空间大小（单位字节）

    注意事项！！！！
    后面的地址有足够的空间 让动态内存空间调整到相应的大小，返回旧的空间地址
    否则realloc会重新寻找一个新的内存区域，开辟一块满足需求空间的地址，
    并且把原来的内存中的数据拷贝回来，释放旧的内存空间，返回新开辟空间的大小
    调整失败返回NULL
    （将要调整的内存空间较大时，会发生这样的情况）
*/


// int main()
// {
//     int i = 0;
//     int *p = (int *)calloc(5, sizeof(int));
//     if(p==NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         for (i = 0; i < 5; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//         printf("\n");
//     }
//     //调整动态内存空间的大小
//     //int *ptr = realloc(p, INT_MAX+1); 
//     int *ptr = realloc(p, 10*sizeof(int)); //调整大小
//     if(ptr==NULL)  //失败
//     {
//         printf("%s\n", strerror(errno));
//         for (i = 0; i < 5; i++)
//         {
//         printf("%d ", *(p + i));
//         }
//         printf("\n");
//     }
//     else
//     {
//         p = ptr;  //成功，p继续接管开辟的动态内存空间
//         ptr = NULL;
//         for (i = 0; i < 10; i++)
//         {
//         printf("%d ", *(p + i));
//         }
//         printf("\n");
//     }


//     //释放空间
//     free(p);
//     p = NULL;
//     return 0;
// }


// //与malloc()功能相似
// int main()
// {
//     int *P = realloc(NULL, 20); //等价于malloc(20);
//     return 0;
// }

