#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//printf函数的返回值  
int main()
{
    int a=printf("%d",43);  // 43
    int b=printf("%d",a);  // 3
    printf("%d",b);   // 2

    printf("\n");

    printf("%d", printf("%d", printf("%d",43)));  //printf()函数返回值为打印字符的个数,""里面的字符，\n也算一个字符
    return 0;
}


// int main()
// {
//     char s1[] = {2, 3, 4, 5, 6, 7, 0};  //\0的ascii值为0
//     char *s2 = "abc";  //abc\0
//     printf("%d\n",strlen(s1));  //strlen遇到\0结束计算长度  --输出6
//     printf("%d\n",strlen(s2));                             --输出3
//     return 0;
// }


// //写一个函数从有序数组中查找具体的某个数，找到返回下标，没有找到返回-1
// int binary_search(int s[],int val,int sz)   //s[]实际上是一个地址
// {

//     //int sz = sizeof(s) / sizeof(s[0]);   //等于2  ，64位的系统sizeof(s)是八个字节 ，int型的s[0]是四个字节
//     int left = 0;
//     int right = sz - 1;
//     while(left<=right)
//     {
//         int mid = (left + right) / 2;  //中间元素的下标，每次都要获得中间元素的下标
//         if(val<s[mid])
//         {
//             right = mid - 1;
//         }
//         else if(val>s[mid])
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int k = 10;
//     int sz = sizeof(arr) / sizeof(arr[0]); //先求得有序数组的长度
//     //int ret = binary_search(arr,k);   //arr传的是首元素的地址
//     int ret = binary_search(arr,k,sz);   
//     if(-1==ret)
//     {
//         printf("找不到指定的数字！\n");
//     }
//     else
//     {
//         printf("找到了！下标为:%d\n",ret);
//     }
//     return 0;
// }

// //写一个函数判断数字是否为素数
// int is_prime(int x)
// {
//     int i = 0;
//     for (i = 2; i <= sqrt(x);i++)  //试除法
//     {
//         if(x%i==0)
//         {
//             return 0;  //不是素数
//         }
//     }//试完最小的试除范围，没有找到能整除x的，说明x是素数
//     return 1;  //是素数
// }

// int main()
// {
//     while(1){
//         int input = 0;
//         printf("请输入你要判断的数字：");
//         scanf("%d",&input);
//         if(1==is_prime(input))
//         {
//             printf("%d是素数！\n",input);
//         }
//         else
//         {
//             printf("%d不是素数!\n\n",input);
//         }
//     }
//     return 0;
// }


// //交换两个整型变量
// void Swap(int* x,int* y)//输入参数为 a,b的地址
// {
//     int tmp = 0;
//     tmp = *x;  //解引用符号，指向a
//     *x = *y;   //*x指向a，对a进行操作
//     *y = tmp;  //*y指向b，对b进行操作
// }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("a=%d b=%d\n",a,b);
//     Swap(&a,&b);   //输入参数为 a,b的地址
//     printf("a=%d b=%d\n",a,b);
//     return 0;
// }