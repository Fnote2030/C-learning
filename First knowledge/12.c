#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i = 0;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int *p = arr;
//     for (i = 0; i < sz;i++)
//     {
//         printf("%d ", *p);
//         p = p + 1;
//     }
//         return 0;
// }

// #define max 10
// int main()
// {
//     int val[max];
//     int *p = NULL;
//     for (p = val; p < &val[max];)  //数组的地址是连续递增的
//     {
//         *p++ = 0; //*p=0; p++;
//     }
//     return 0;
// }


// //指针-指针(同一个工作空间，同一个数组)
// int main()
// {
//     // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     // int val = &arr[9] - &arr[0];
//     // printf("%d\n", val);   //两个指针之间的元素个数--9

//     char s[10] = {0};
//     int num = &s[9] - &s[0];  //9
//     printf("%d\n", num);
//     return 0;
// }

// //应用
// int my_strlen(char *str)
// {
//     char *start = str;
//     char *end = str;
    
//     while(*end != '\0')
//     {
//         end++;
//     }
//     return end - start;  //指针-指针
// }

// int main()
// {
//     char arr[] = "hello world!";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
//     return 0;
// }


// //指针和数组
// int main()
// {
//     int a[10] = {0};
//     int *p = a;
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         *(p + i) = i;
//     }
//     for(i = 0; i < 10;i++)
//     {
//         printf("%d ", *(a+i));
//     }
//     printf("\n");
//     for(i = 0; i < 10;i++)
//     {
//         printf("%d ", *(p + i));
//     } 
//     return 0;
// }


// //二级指针
// int main()
// {
//     int a = 10;
//     int *pa = &a;
//     int **ppa = &pa;

//     printf("%d\n", **ppa);
//     return 0;
// }



// int main()
// {
//     //指针数组 --数组
//     int i = 0;  
//     int a = 10;
//     int b = 20;
//     int c = 30;
//     // int *pa = &a;
//     // int *pb = &b;
//     // int *pc = &c;
//     int *p[3] = {&a, &b, &c};  //指针数组，用来存放指针
//     for (i = 0; i < 3;i++)
//     {
//         printf("%d ", **(p+i));
//     }

//     return 0;
// }


//数组指针 --指针
// int main()
// {
//     int a[3][5] = {0};
//     int (*p)[5] = a;  //p指针变量指向包含5个int元素的一维数组（存放地址）  *p是一维数组a[0] ([0]-[4])的地址
//     int i = 0;
//     int j = 0;
//     //*(*p + 1) == a[0][1];   //*(数组名+i),这里的数组名是*p
//     //*(*(p + 1) + 1) == a[1][1];  //因为数组在内存中是连续存放的  *(a[1]+1)==*a(*(a+1)+1)

//     *(*(p + 1) + 2) = 10;  //a[1][2]=10
//     for (i = 0; i < 3;i++)
//     {
//         for (j = 0; j < 5;j++)
//         {
//             printf("%-3d", a[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }



// //作业
// //初始化
// void Init(int arr[],int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz;i++)
//     {
//         arr[i] = i; 
//     }
// }
// //打印
// void Print(int arr[],int sz)
// {
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// //逆置
// void Reverse(int arr[],int sz)
// {
//     int left = 0;
//     int right = sz - 1;
//     while(left < right)
//     {
//         int tmp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = tmp;
//         left++;
//         right--;
//     }
// }

// int main()
// {
//     int arr[10] = {0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     Init(arr, sz); //把数组初始化
//     Print(arr, sz);
//     Reverse(arr, sz); //逆置
//     Print(arr, sz);
//     return 0;
// }




// int main()
// {
//     int a = 0x11223344;
//     char c[32] = {0};
//     printf("%x\n", a);
//     itoa(a,c,2);  //转换成二进制数，存储在字符串中
//     printf("%s\n", c);
// }


// //计算补码中1的个数
// int count_bit(unsigned int n)  //类型不匹配
// {
//     int count = 0;
//     while(n != 0)  //负数或者正数
//     {
//         if(1 == (n & 1))
//         {
//             count++;
//         }
//         n = n >> 1;
//     }
//     return count;
// }

// int count_bit(int n)
// {
//     int count = 0;
//     while(n)
//     {
//         n = n & (n - 1);//将最低位的那个1置为0
//         count++;
//     }
//     return count;
// }



// int main()
// {
//     int input = 0;
//     scanf("%d", &input);
//     int count = count_bit(input);
//     printf("count=%d\n", count);
//     return 0;
// }


// int main()
// {
//     int a = -3;
//     int b = a >> 1;  //有符号右移运算高位补充符号位
//     printf("%d\n", b);
//     return 0;
// }

// //分别打印二进制数的奇数位和偶数位
// void Print(int m)
// {
//     int n = 0;
//     printf("奇数位：\n");
//     for (n = 30; n >= 0; n -= 2)
//     {
//         printf("%d ", (m >> n) & 1);
//     }
//     printf("\n");
//     printf("偶数位：\n");
//     for (n = 31; n >= 1; n -= 2)
//     {
//         printf("%d ", (m >> n) & 1);
//     }
// }

// int main()
// {
//     int m = 0;
//     scanf("%d", &m);
//     Print(m);
//     return 0;
// }


// //打印乘法表
// void print_table(int n)
// {
//     int i = 0;
//     int j = 0;
//     for (i = 1; i <= n;i++)
//     {
//         for (j = 1; j <= i;j++)
//         {
//             printf("%d*%d=%-3d", i, j, i * j);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int n = 0;
//     printf("请输入要打印几阶的乘法表：\n");
//     scanf("%d", &n);
//     print_table(n);
//     return 0;
// }


// //递归打印一个整数的每一位
// void print_val(int n)
// {
//     if(n<10)
//     {
//         printf("%d ", n);
//     }
//     else
//     {
//         print_val(n / 10);  //先打印高位
//         printf("%d ", n % 10);
//     }
// }

// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     print_val(n);
//     return 0;
// }


// //把字符串逆序然后打印,不使用库函数
// int my_strlen(char arr[])
// {
//     int len = 0;
//     while(*arr!='\0')
//     {
//         len++;
//         arr++;
//     }
//     return len;
// }
// // //普通循环
// // void reverse_string(char arr[])
// // {
// //     int left = 0;
// //     int right = my_strlen(arr)-1;
// //     while(left<right)
// //     {
// //         char tmp = arr[left];
// //         arr[left] = arr[right];
// //         arr[right] = tmp;
// //         left++;
// //         right--;
// //     }
// // }

// //递归法
// void reverse_string(char arr[])
// {
//     int len = my_strlen(arr) - 1;
//     char tmp = arr[0];  //左边的存起来
//     arr[0] = arr[len];  //右边的先给左边

//     arr[len] = '\0';   //长度减一
//     if(my_strlen(arr+1)>=2)//长度再减一  ,这次递归除去两端的各一个字符，中间剩余的字符串长度不小于2继续递归
//     {
//         reverse_string(arr + 1);
//     }

//     arr[len] = tmp;  //中间的交换完再将左边的给右边
// }

// int main()
// {
//     char arr[] = "abcdef";
//     reverse_string(arr);
//     printf("%s\n", arr);
//     return 0;
// }


// //使用递归法将一个整数的每位相加返回
// int DigitSum(unsigned int num)
// {
//     if(num>9)
//     {
//         return DigitSum(num / 10) + num % 10;
//     }
//     else
//     {
//         return num;
//     }
// }

// int main()
// {
//     unsigned int num = 0;
//     int sum = 0;
//     scanf("%d", &num);
//     sum = DigitSum(num);
//     printf("%d\n", sum);
//     return 0;
// }

// //使用递归法求n的k次方
// double Pow(int n,int k)
// {
//     if(k<0)
//     {
//         return 1.0 / (Pow(n, -k));
//     }
//     else if (1 == k)
//     {
//         return n;
//     }
//     else
//     {
//         return n * Pow(n, k - 1);
//     }
// }
// int main()
// {
//     int n = 0;
//     int k = 0;
//     scanf("%d%d", &n, &k);
//     double ret = Pow(n, k);
//     printf("%lf\n", ret);
//     return 0;
// }

//输出水仙花数
int main()
{
    int i = 0;
    int count = 0;
    for (i = 0; i <= 10000;i++)
    {
        if(i<10)
        {
            printf("%-5d", i);
            count++;
        }
        else if(i<100)
        {
            if(i==(pow(i%10,2)+pow(i/10%10,2)))
            {
                printf("%-5d",i);
                count++;
            }
        }
        else if(i<1000)
        {
            if(i==(pow(i%10,3)+pow(i/10%10,3)+pow(i/100%10,3)))
            {
                printf("%-5d", i);
                count++;
            }
        }
        else if(i<10000)
        {
            if(i==(pow(i%10,4)+pow(i/10%10,4)+pow(i/100%10,4)+pow(i/1000%10,4)))
            {
                printf("%-5d", i);
                count++;
            }
        }
        else
        {
            if(i==(pow(i%10,5)+pow(i/10%10,5)+pow(i/100%10,5)+pow(i/1000%10,5)+pow(i/10000%10,5)))
            printf("%-5d", i);
        }
    }
    return 0;
}