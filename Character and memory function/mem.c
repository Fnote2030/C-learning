#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct S
{
    char name[20];
    int age;
} S;

//相较于字符操作函数的只能操作函数的局限性，内存操作函数能够操作任意类型的变量



/*                 《一》
    void *memcpy(void *dest,const void *src,size_t num)函数    
    拷贝src位置的数组到dest位置，num为需要拷贝的字节大小
    注意！！！！
    目的空间和源空间有关联的话，目的空间的数据的改变会影响源空间的数据
    C语言标准:
    只要处理内存不重叠的的拷贝就可以了
*/

// //强大功能演示
// int main()
// {
//     S arr3[] = {{"张三", 43}, {"李四", 53}};
//     S arr4[3] = {0};
//     printf("%s  %d\n", arr3[0].name, arr3[0].age);
//     memcpy(arr4, arr3, sizeof(arr3));
//     printf("%s  %d\n", arr4[0].name, arr4[0].age);
//     return 0;
// }

// //内存重叠的情况可能会出现问题
// //模拟实现
// void *my_memcpy(void *dest,const void *src,size_t num)
// {
//     void *dests = dest;
//     assert(dest != NULL);
//     assert(src != NULL);
//     while(num--)//拷贝num字节
//     {
//         *(char *)dest++ = *(char *)src++; //拷贝一个字节
//     }
//     return dests;
// }
// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[5] = {0};
//     my_memcpy(arr2, arr1, sizeof(arr1));
//     int i = 0;
//     for (i = 0; i < 5;i++)
//     {
//         printf("%d ", arr2[i]);
//     }

//     // S arr3[] = {{"张三", 43}, {"李四", 53}};
//     // S arr4[3] = {0};
//     // printf("%s  %d\n", arr3[0].name, arr3[0].age);
//     // my_memcpy(arr4, arr3, sizeof(arr3));
//     // printf("%s  %d\n", arr4[0].name, arr4[0].age);

//     return 0;
// }




/*                 《二》
    void *memmove(void *dest,const void *src,size_t num)函数    
    拷贝src位置的数组到dest位置，num为需要拷贝的字节大小

    能够处理内存重叠的拷贝
*/

// //模拟实现
// void *my_memmove(void *dest,const void *src,size_t num)
// {
//     assert(dest != NULL);
//     assert(src != NULL);
//     void *dests= dest;
//     if(dest > src)  //目的空间在源空间右边 ，从后面向前面开始拷贝
//     {
//         dest = (char *)dest + num;
//         src = (char *)src + num;
//         while(num--)
//         {
//             *(char *)--dest = *(char *)--src;  //转换成char *类型，再自减
//         }
//     }
//     else
//     {
//         while(num--)
//         {
//             *(char *)dest++ = *(char *)src;
//         }
//     }
//     return dests;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     my_memmove(arr+2, arr, 20);  //将1，2，3，4，5拷贝到后面两个int身位的位置上
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         printf("%d ", arr[i]);//1，2，1，2，3，4，5，8，9，10
//     }
//     return 0;
// }





/*                 《三》
    void *memcmp(void *dest,const void *src,size_t num)函数    
    比较src位置的数据和dest位置的数据，num为需要比较的字节大小

*/

// int main()
// {
//     int arr1[10] = {1, 2, 3, 257, 5, 6, 7, 8, 9, 10};  //257 01 01 00 00
//     int arr2[10] = {1, 2, 3, 1, 7, 9, 10, 4, 5, 6};    //1   01 00 00 00
//     int ret = memcmp(arr1, arr2, 12); //12为需要比较的字节
//     printf("%d\n", ret);
//     ret = memcmp(arr1, arr2, 13); //13为需要比较的字节,返回0因为当前系统为小端存储，并且，257和1的第一个第一个字节的数据相同
//     printf("%d\n", ret);
//     return 0;
// }



/*                 《四》
    void *memset(void *dest,int c,size_t count)函数    
    在dest位置上向后放置数据，count为要放置多少字节的数据
    c为要放置的字符，理解成char类型
*/

int main()
{
    // char arr[11] = {0};
    // memset(arr, '#', 10);
    // printf("%s\n", arr);

    int arr[11] = {0};
    memset(arr, 258, 40);  //第二参数理解成是char类型的，258 == 2
    int i = 0;
    for (i = 0; i < 10;i++)
    {
        printf("%x ", arr[i]);
    }
    return 0;
}

