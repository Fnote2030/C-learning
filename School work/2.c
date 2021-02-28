#include<stdio.h>
#include<string.h>
#include<assert.h>

// int main()
// {
//     char arr[2] = {'a', 'b'};
//     char(*p)[2] = &arr;  //p==&arr  *p==arr

//     printf("%c\n", (*p)[0]);
//     printf("%c\n", (*p)[1]);
//     printf("%c\n", **p); //**p ==*(*p+0)
//     printf("%c\n", *(*p + 1));

//     printf("%p\n", *p);
//     printf("%p\n", *p+1);
//     printf("%p\n", *(p + 1)-2);
//     printf("%p\n", *(p + 1)-1);
//     return 0;
// }



// //旋转字符串
// //左旋字符串中的k个字符
// void reverse(char *left, char *right)
// {
//     while(left<right)
//     {
//         char tmp = *left;
//         *left = *right;
//         *right = tmp;
//         right--;
//         left++;
//     }
// }
// void Left_move(char *src, int k)
// {
//     int len = strlen(src);
//     assert(src != NULL);
//     assert(k <= len);
//     reverse(src, src + k - 1);
//     reverse(src + k, src + len - 1);
//     reverse(src, src + len - 1);
// }

// int main()
// {
//     char arr[256] = {0};
//     int k = 0;
//     printf("请输入要字符串：\n");
//     gets(arr);
//     printf("请输入要左旋的个数：\n");
//     scanf("%d", &k);
//     Left_move(arr, k);
//     printf("左旋后的字符串如下：\n");
//     printf("%s\n", arr);
//     return 0;
// }



// //s2 是 s1 左旋之后的字符串

// int Is_left_move(char *s1,char *s2)
// {
//     int len1 = strlen(s1);
//     int len2 = strlen(s2);
//     if (len1 != len2)
//     {
//         return 0;   
//     }

//     strncat(s1, s1, len1);
//     char *ret = strstr(s1, s2); //s2是否为s1的字串
//     if(ret!=NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }


// int main()
// {
//     char arr1[64] = "abcdefgh";
//     char arr2[] = "defghabc";
//     int ret = Is_left_move(arr1, arr2);
//     if(1==ret)
//     {
//         printf("Yes!\n");
//     }
//     else
//     {
//         printf("No\n");
//     }
//     return 0;
// }


//从杨氏矩阵查找某个数字是否存在(矩阵的每行从左到右逐渐递增，每列从上到下递增)
//时间复杂度小于O(n)
int FindNum(int arr[3][3],int k,int *px,int *py)
{
    int x = 0;
    int y = *py - 1;
    while (x <= 2 && y >= 0)
    {
        if(arr[x][y]<k)
        {
            x++;
        }
        else if(arr[x][y]>k)
        {
            y--;
        }
        else
        {
            //找到了
            *px = x;
            *py = y;
            return 1;
        }
    }
    //没找到
    return 0;
}
int main()
{
    int k = 6;
    int x = 3;
    int y = 3;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int ret = FindNum(arr, k, &x, &y);
    if(ret>=0)
    {
        printf("找到了，下标是%d,%d\n",x,y);
    }
    else
    {
        printf("没找到\n");
    }
    return 0;
}