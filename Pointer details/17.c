#include<stdio.h>
#include<stdlib.h>
typedef struct Stu
{
    char name[20];
    int age;
}Stu;


////void *
// int main()
// {
//     int a = 10;
//     char ch = 'a';
//     //void *可以接收任意类型的地址
//     void *p = &a;
//     void *pa = &ch;

//     //void *类型的指针，不能解引用操作
//     return 0;
// }    




// //qsort库函数
// //第一个参数；待排数组的首元素地址
// //第二个元素：待排数组的元素个数
// //第三个元素：待排数组的每个元素的大小-单位为字节
// //第四个元素：是函数指针，比较两个元素的所用函数的地址-函数使用者自己实现，
// //第一个元素大于第二个元素返回1，小于返回-1，等于返回0

// //比较函数
// int cmp_float(const void*a,const void *b)
// {
//     if (*(const float *)a < *(const float *)b)
//     {
//         return -1;
//     }
//     if(*(const float *)a > *(const float *)b)
//     {
//         return 1;
//     }
//     return 0;
// }
// int cmp_stu_by_age(const void *a, const void *b)
// {
//     return (((const Stu *)a)->age > ((const Stu *)b)->age) - (((const Stu *)a)->age < ((const Stu *)b)->age);
// }


// void test1()
// {
//     float f[] = {9.1, 3.5, 23.45, 3.56, 4.56, 3.9};
//     int sz = sizeof(f) / sizeof(*f);
//     qsort(f, sz, sizeof(float), cmp_float); //
//     int i = 0;
//     for (i = 0; i < sz;i++)
//     {
//         printf("%f ", f[i]);
//     }
//     printf("\n");
// }
// void test2()
// {
//     Stu s[] = {{"张三", 23}, {"李四", 43}, {"王五", 34}};
//     int sz = sizeof(s) / sizeof(s[0]);
//     qsort(s, sz, sizeof(Stu), cmp_stu_by_age);  //
//     int i = 0;
//     for (i = 0; i < sz;i++)
//     {
//         printf("%s  %d\n", s[i].name, s[i].age);
//         printf("%s  %d\n", (s + i)->name, (s + i)->age);
//     }
// }


// int main()
// {
//     test1();
//     test2();
//     return 0;
// }


//自定义函数，实现qsort库函数的功能
void Swap(char *buf1,char *buf2,int width)
{
    int i = 0;
    for (i = 0; i < width;i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}
void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *a, const void *b))
{
    int i = 0;
    int j = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int flag = 1; //假设本趟为有序的
        //每一趟的比较
        for (j = 0; j < sz - 1 - i; j++)
        {
            //比较两个元素
            if (cmp((char *)base + width * j, (char *)base + width * (j + 1)) > 0)
            {
                //交换
                Swap((char *)base + width * j, (char *)base + width * (j + 1), width);
                flag = 0; //本趟为无序
            }
        }
        if(flag)
        {
            break;  //结束排序
        }
    }
}

int cmp_stu_by_age(const void *a, const void *b)
{
    Stu *s1 = (Stu *)a;
    Stu *s2 = (Stu *)b;
    return (s1->age > s2->age) - (s1->age < s2->age);
}
int cmp_int(const void *a,const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return (num1 > num2) - (num1 < num2);
}
void test1()
{
    int arr[] = {1, 23, 4, 5, 7, 5, 35, 74, 12, 45};
    int sz = sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, sz, sizeof(*arr), cmp_int);
    int i = 0;
    for (i = 0; i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void test2()
{
    Stu s[] = {{"张三", 23}, {"李四", 43}, {"王五", 34}};
    int sz = sizeof(s) / sizeof(s[0]);
    bubble_sort(s, sz, sizeof(Stu), cmp_stu_by_age);  //
    int i = 0;
    for (i = 0; i < sz;i++)
    {
        printf("%s  %d\n", s[i].name, s[i].age);
    }
}

int main()
{
    test1();
    test2();
    return 0;
}

