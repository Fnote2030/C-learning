#include<stdio.h>

//按位取反操作符号
// int main()
// {
//     for (unsigned int i = 0; i < 10;i++)
//     {
//         unsigned int a = ~i;
//         printf("%d",a);  //数据以补码的形式存储   int->32位2进制数
//         printf("    ");  //1的补码是   00000000 00000000 00000000 00000001    最高位为符号位                  
//     }                    //~1的补码是  11111111 11111111 11111111 11111110    
//     return 0;            //~1的原码是  10000000 00000000 00000000 00000010     即为-2
// }


//静态局部变量
// void test()
// {
//     static int a = 1;
//     printf("a=%d\n",a);
//     a++;
// }
// int main()
// {
//     int i = 0;
//     while(i<5)
//     {
//         test();
//         i++;
//     }
//     return 0;
// }


//调用
// int main()
// {   
//     int a = 10;
//     int b = 20;
//     int c = Add(a,b);
//     printf("sum=%d",c );
// }
// int Add(int x,int y)
// {
//     int z = x + y;
//     return z;
// }


//函数的宏定义
// #define Max(x, y) (x > y ? x : y)
// int main()
// {
//     int a = 1;
//     int b = 2;
//     int c = Max(a,b);
//     printf("%d\n",c );
// }

//指针
int main()
{
    int a = 10;
    int *p = &a;
    printf("a=%d\n",a );
    printf("a的地址为%p\n",p );

    printf("地址的长度%d\n", sizeof(p));
    //64位的操作系统的指针地址是八个字节，32位的操作系统的指针地址是四个字节
    printf("%d\n",sizeof(int *));
    printf("%d\n",sizeof(long *));
    printf("%d\n",sizeof(char *));
    printf("%d\n",sizeof(float *));

    *p = 20;  //*在这里为解引用符  ，指向地址p所表示的变量
    printf("a=%d\n",a );
}
