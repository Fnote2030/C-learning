#include<stdio.h>


// void FindBitNum(int arr[], int sz, int *arr1, int *arr2)
// {
//     //所有数异或
//     int i = 0;
//     int val = 0;
//     int num = 0;
//     for (i = 0; i < sz; i++)
//     {
//         val ^= arr[i];
//     }
//     //找出两个不同数字异或的二进制数哪位最开始不同
//     for (i = 0; i < 32; i++)
//     {
//         if(((val>>i)&1)==1)
//         {
//             num = i; //第几位
//             break;
//         }
//     }
//     for (i = 0; i < sz;i++)
//     {
//         if(((arr[i]>>num)&1)==1)
//         {
//             *arr1++ = arr[i];
//         }
//         else
//         {
//             *arr2++ = arr[i];
//         }
//     }
// }
// int FindDiffer(int *arr)
// {
//     int num = 0;
//     while(*arr!=0)
//     {
//         num ^= *arr++;
//     }
//     return num;
// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 8, 1, 2, 3, 4, 6};
//     int arr1[10] = {0};
//     int arr2[10] = {0};
//     int ret = 0;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     //根据二进制位的第几位来分组
//     FindBitNum(arr, sz, arr1, arr2);

//     ret = FindDiffer(arr1);
//     printf("%d\n", ret);
//     ret = FindDiffer(arr2);
//     printf("%d\n", ret);
//     return 0;
// }


//找出一组数字中 三个只出现一次的数字
int FindendOf1(int num)
{
    return num & ~(num - 1); //保留最后一个1
}

FindThreeDif(int arr[],int len)
{
    int i = 0;
    int val = 0;
    int flag = 0;
    int first = 0;
    int second = 0;
    int three = 0;
    for (i = 0; i < len; i++)
    {
        val ^= arr[i];
    }
    for (i = 0; i < len; i++)
    {
        flag ^= FindendOf1(val ^ arr[i]);  //三个不同数之间最后一个1是单独存在的位置
    }
    flag = FindendOf1(flag);  //三个不同数字保留最后一个1
    for (i = 0; i < len; i++)
    {
        if (FindendOf1(val ^ arr[i]) == flag) //找到最后的1单独存在的那个数
            first ^= arr[i];
    }
    val ^= first; //其他两个数
    arr[len] = first;  ;//变成两个数不同
    flag = FindendOf1(val);
    for (i = 0; i < len + 1; i++)
    {
        if(arr[i]&flag)
        {
            second ^= arr[i];
        }
    }
    three = val ^ second;

    printf("%d %d %d\n", first,second,three);
}
int main()
{
    int arr[20] = {1, 2, 3, 4, 8,15, 7, 1, 2, 3, 4};
    int len = sizeof(arr) / sizeof(*arr);
    FindThreeDif(arr, len);
    return 0;
}