#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>
/*
            《malloc》
    void *malloc(size_t size);
    size--申请多少字节的空间   size不能等于0
    void * --返回申请的空间的首地址
    失败返回空指针 --NULL

            《free》
    void free(void *memblock);
    *memblock 要释放的空间
    不能释放数组
    输入NULL指针，free相当于没有操作
*/
typedef struct S
{

} S;

//申请动态空间
int main()
{
    // int n = 0;
    // scanf("%d", &n);   //c99标准支持，但是大多数编译器不支持

    //动态内存
    //int *p = (int *)malloc(INT_MAX + 1);  //Not enough space
    int *p = (int *)malloc(10 * sizeof(int)); //(int *)可以不加，一般不会报错，不过建议添加
    if(p==NULL)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        //正常使用空间
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            *(p + i) = i;
        }
        for (i = 0; i < 10; i++)
        {
            printf("%d ", *(p + i));
        }
    }
    //当申请的动态空间不再使用的时候，就应该将空间还回操作系统
    free(p);   //只是将p指向的空间还回操作系统，p仍然指向之前的空间
    p = NULL;  //将p赋值空指针
    return 0;
}