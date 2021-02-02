#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

//密码登录
int main()
{
    int i = 0;
    char password[20] = {0};
    for (i = 0; i < 3;i++)
    {
        printf("请输入密码：");
        scanf("%s",password);
        if(strcmp(password,"123456")==0)  //两个字符串匹配就返回0
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("密码错误\n");
        }
    }
    if(3==i)
    {
        printf("三次密码都输入错误，程序退出\n");
    }
}

// //字符从两端移动，向中间汇聚
// int main()
// {
//     char arr1[256];
//     char arr2[256];
//     printf("请输入要演示字符(非中文)：\n");
//     //scanf("%s",arr1); //不能输入空格
//     char str;
//     int len = 0;
//     while((str=getchar())!='\n')
//     {
//         arr1[len] = str;
//         len++;
//     }
//     int left = 0;
//     int right = strlen(arr1)-1;  //len-1
//     for (int i = 0; i < len; i++)
//     {
//         arr2[i] = '#';
//     }

//     printf("%s", arr2);
//     Sleep(500);   //休息
//     system("cls");  //调用
//     while(left<=right)
//     {
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         printf("%s",arr2);
//         left++ ;
//         right--;
//         Sleep(500);
//         system("cls");
//     }
//     printf("%s",arr2);
//     return 0;
// }

// //字符串的大小是字符串的长度加1    sizeof(str)=strlen(str)+1
// int main()
// {
//     char arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//10
//     char arr1[] = "Welcome to China!";   //17
//     int len1 = sizeof(arr) / sizeof(arr[0]);  //10
//     int len2 = sizeof(arr1) / sizeof(arr1[0]); //18=17+1   字符串还有隐藏的'\0'结束标志
//     printf("%d  %d",len1,len2);
// }

// //二分/折半查找法   适用于有顺序的序列
// int main()
// {
//     int k;
//     printf("请输入你要查找的数字：");
//     scanf("%d", &k);
//     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int sz = sizeof(arr) / sizeof(arr[0]);  //元素个数
//     int left = 0;//左下标
//     int right = sz-1;//右下标
//     while(left <= right)
//     {
//         int mid = (left + right) / 2;//中间下标
//         if(arr[mid]>k)
//         {
//             right = mid - 1;
//         }
//         else if(arr[mid]<k)
//         {
//             left = mid + 1;
//         }
//         else   
//         {
//             printf("找到了，下标是%d\n",mid);
//             break;
//         }
//     } 
//     if(left>right)
//     {
//         printf("找不到\n");
//     }
//     return 0;
// }

// //阶乘
// int main()
// {
//     int i;
//     int val;
//     int all = 0;
//     int io = 1;
//     printf("请输入要求阶乘的数字：\n");
//     scanf("%d", &val);
//     for (i = 1; i <= val; i++)
//     {
//         io = io * i;
//         all = all + io;
//         printf("<%d的阶乘为%d>  ",i,io);
//     }
//     printf("\n1-%d的阶乘相加为%d\n",val,all );
//     return 0;
// }
 

////输入缓冲区 
// int main()
// {
//     int ret;
//     int k;
//     char password[20];
//     printf("请输入密码：");
//     scanf("%s",password);   //从输入缓冲区获得数据,缓冲区有密码+\n,读走密码留下\n 
//     //只读取输入缓冲区数据第一个空格之前的字符
//     printf("设置的密码为：%s\n",password);
//     while ((k = getchar()) != '\n')//读取输入缓冲区第一个空格之后的所有数据
//     {
//         ;
//     }    //清空输入缓冲区
//     printf("请确认（y/n）：");
//     ret = getchar();  //从输入缓冲区获得数据
//     if('y'==ret)
//     {
//         printf("确认成功\n");
//     }
//     else
//     {
//         printf("放弃确认\n");
//     }
// }