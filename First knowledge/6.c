#include<stdio.h>
#include<string.h>

//数组名是数组首元素的地址  ，除了下面两种情况
//1、sizeof(数组名) ， 数组名表示整个数组  
//2、&数组名 ，取出来的是整个数组的地址
int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    // printf("%p\n",arr);
    // printf("%p\n",&arr[0]);//&arr[0] == arr 数组首元素的地址

    // printf("%p\n",&arr);  //整个数组的地址
    // printf("%p\n",&arr+1);  //地址增加了20 == 4*5


    //二维数组
    int arr2[][3] = {{1, 2, 3}, {4, 5, 6}};   //二维数组可以分为arr2[0]和arr2[1]两个一维数组 ，两个一维数组的元素都为3个
    int i = 0;
    for (i = 0; i < 2;i++)
    {
        int j = 0;
        for (j = 0; j < 3;j++)
        {
            printf("&arr[%d][%d]=%p\n", i, j, &arr2[i][j]);
        }
    }
    printf("%p\n",&arr2[0]);  //整个arr2[0]的地址
    printf("%p\n",&arr2[0]+1);
    printf("%p\n",&arr2[1]);  //整个arr2[1]的地址 ，地址比arr[0]增加了12
    return 0;
}


// //冒泡排序，升序输出
// void bubble_sort(int arr[],int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz-1;i++)  //sz-1趟冒泡排序
//     {
//         int j = 0;
//         int flag = 1;//假设本趟排序的数据是有序递增的
//         for (j = 0; j < sz - 1 - i;j++)
//         {
//             if(arr[j]>arr[j+1])  //较大的往后移动
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//                 flag = 0;  //存在后一个元素比前一个元素小  ，说明本趟要排序的数据不是有序递增的
//             }
//         }
//         if(1==flag)
//         {
//             break;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {21, 12, 43, 75, 18, 76, 47, 16, 86, 66, 234, 23, 64, 28};
//     int i = 0;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr,sz);
//     for (i = 0; i < sz ;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//         return 0;
// }


// //二维数组
// int main()
// {
//     int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8};//二维数组的列不能省略，行能省略
//     int arr2[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
//     int i = 0;
//     for (i = 0; i < 2;i++)
//     {
//         int j = 0;
//         for (j = 0; j < 4;j++)
//         {
//             printf("&arr[%d][%d]=%p  ",i,j, &arr[i][j]);   // &arr[i][j]  == arr[i]+j  ==arr[0]+(i+1)*4+j
//             printf("%d\n",*(arr[i]+j));   // 把arr[i]当成一个一维数组 , arr[0]指向arr数组的第一个元素的地址
//         }                                 //*(arr[i]+j) == arr[i][j]
//     }
//     return 0;
// }

// //数组在内存中是连续存放的
// int main()
// {
//     int  arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     for (i = 0; i < sz;i++)
//     {
//         printf("&arr[%d]=%p\n",i,&arr[i]);
//     }
// }

// int main()
// {
//     char arr1[] = {'a', 'b', 'c'};
//     char arr2[] = "abc";
//     printf("%d\n",sizeof(arr1));    //3
//     printf("%d\n",sizeof(arr2));    //4

//     //如果指定了大小数组的大小，未分配的空间默认赋值0，
//     //所以如果数组的大小大于所要分配的大小，strlen能够计算出数组的大小
//     //如果是arr1[4] ，strlen(arr1)输出是3
//     printf("%d\n",strlen(arr1));    //4 随机值  
//     printf("%d\n",strlen(arr2));    //3
//     return 0;
// }


// //斐波那契数列   1 1 2 3 5 8 13 21  当前数值等于前两个数之和
// // int Fib(int n){
// //     if(n<=2)
// //     {
// //         return 1;
// //     }
// //     else
// //     {
// //         return Fib(n-1) + Fib(n-2);
// //     }
// // }  //不适合效率太低了

// int Fib(int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 1;
//     while(n>2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }

// int main()
// {
//     int n = 0;
//     int ret = 0;
//     printf("请输入要求的斐波那契数：");
//     scanf("%d",&n);
//     ret = Fib(n);
//     printf("第%d个斐波那契数是%d\n",n,ret);
//     return 0;
// }

////递归求阶乘
// int Facl(int val)
// {
//     if(val>1){
//         return val*Facl(val-1);
//     }
//     else
//     {
//         return 1;
//     }
// }
// int main()
// {
//     int val = 0;
//     int ret = 0;
//     printf("请输入你要求阶乘的数：");
//     scanf("%d",&val);
//     ret = Facl(val);
//     printf("%d的阶乘时%d\n",val,ret);
//     return 0;
// }

// int my_strlen(char* arr)
// {
//     int len = 0;
//     while(*arr++!='\0')   //arr先用再加
//     {
//         len++;
//     }
//     return len;
// }

// //使用递归的方法求字符串的长度
// int my_strlen(char* arr)
// {
//     if('\0'!=*arr)   //当前不是结束符，长度至少为1，再加上后面的长度
//     {
//         return 1+my_strlen(arr+1); //地址加一
//     }
//     else
//     {
//         return 0;
//     }
// }
// int main()
// {
//     char arr[] = "hello";
//     printf("%d\n",strlen(arr));

//     printf("%d\n",my_strlen(arr));
//     return 0;
// }


// //递归有两个必要条件
// //1、存在限制条件，当满足这个限制条件时，递归不再继续
// //2、每次递归调用之后越来越接近这个限制条件

// //递归将数分开打印
// void print(int num)
// {
//     if(num>9)
//     {
//         print(num/10);  //打印除最低位的数字
//     }
//     printf("%d ",num%10);  //打印最低位的数字
// }

// int main()
// {
//     unsigned int val;
//     printf("请输入你要分开打印的数字：");
//     scanf("%d",&val);
//     print(val);
//     return 0;
// }