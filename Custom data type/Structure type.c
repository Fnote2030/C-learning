#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
// //             《结构体类型》
// //声明一个学生结构体类型,是通过学生类型来创建学生变量的（对象）
// //描述学生：属性：名字-电话-性别-年龄
// struct Stu
// {
//     char name[20];//名字
//     char tele[12];//电话
//     char sex[5];//性别
//     int age;//年龄
// } s4, s5, s6;   //声明结构体类型的同时创建全局的结构体变量  //不建议的代码风格

// //匿名结构体类型 --用一次之后不能再次使用
// struct 
// {
//     int a;
//     char s;
// }ar;//没有类型名字，后续不能创建结构体变量，只能声明的同时创建变量
// struct 
// {
//     int a;
//     char s;
// }*par;

// int main()
// {
//     //创建结构体变量
//     struct Stu s1;
//     struct Stu s2;
//     //par = &ar; //编译器认为结构体类型不相同
//     return 0;
// }



// //结构体自引用
// typedef struct Node   //重命名也不能省略Node （不能匿名）
// {
//     int data;
//     struct Node *p;
// }Node;

// int main()
// {
//     printf("%d\n", (int)sizeof(struct Node));
//     printf("%d\n", (int)sizeof(Node));
//     return 0;
// }




//              《结构体内存对齐》
//1、第一个成员在与结构体变量偏移量为0的地址处（与之重合）
//2、其他成员变量要对齐到某个数字（对齐数）整数倍的地址处
//3、对齐数=min(成员变量大小，8) （vscod默认是8）
//4、结构体的总大小为 “最大对齐数”（每个成员变量都有一个对齐数）的整数倍
//5、如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
//   结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍。
//技巧： 让占空间小的成员放在一起
// struct S1
// {
//     char c1;
//     int a;
//     char c2;
// };
// struct S2
// {
//     char c1;
//     char c2;
//     int a;
// };
// struct S3
// {
//     double b;
//     char c;
//     int i;
// };
// struct S4
// {
//     char c;
//     struct S3 s3;
//     double d;
// };
// int main()
// {
//     struct S1 s1 = {0};
//     struct S2 s2 = {0};
//     struct S3 s3 = {0};
//     struct S4 s4 = {0};
//     printf("%d\n", (int)sizeof(s1));  //1+3 4 1+3  max(4)
//     printf("%d\n", (int)sizeof(s2));  //1 1+2 4    max(4)
//     printf("%d\n", (int)sizeof(s3));  //8 1+3 4    max(8)
//     printf("%d\n", (int)sizeof(s4));  //1+7 16 8   max(8)
//     return 0;
// }



// //              《设置默认对齐数》
// #pragma pack(4)
// struct S1
// {
//     char c1;
//     double d;
// };
// #pragma pack() //取消前面的设置的对齐数，恢复默认对齐数
// struct S2
// {
//     char c1;
//     double d;
// };

// int main()
// {
//     printf("%d\n", (int)sizeof(struct S1));
//     printf("%d\n", (int)sizeof(struct S2));
//     return 0;
// }



// //         《结构体成员相对结构体起始位置的偏移量》
// //宏       size_t offsetof(structName ,memberName)
// //         structName结构体类型  ，menberName结构体的成员 
// struct S
// {
//     char c;
//     int i;
//     double d;
// };
// int main()
// {
//     printf("%d\n", (int)offsetof(struct S, c));
//     printf("%d\n", (int)offsetof(struct S, i));
//     printf("%d\n", (int)offsetof(struct S, d));
//     return 0;
// }



// //            《结构体变量的传参》
// typedef struct S
// {
//     char name[20];
//     int age;
// } S;

// void Init(S *s)
// {
//     s->age = 23;
//     strcpy(s->name, "张三");
// }
// void Print1(S s)
// {
//     printf("name-%s age-%d\n", s.name, s.age);
// }
// void Print2(const S *s)
// {
//     printf("name=%s age=%d\n", s->name, s->age);
// }
// int main()
// {
//     S s = {0};
//     Init(&s); //初始化
//     Print1(s);
//     Print2(&s);
//     return 0;
// }




//             《位段》
//int类型的位段，一次性开辟4个字节的空间，32个bit位 ，  :后面的数字不能大于32
typedef struct S
{
    int a : 2;   //2
    int b : 5;   //7 
    int c : 10;  //17 -- 剩余15个bit位
    int d : 30;  //bit位不够，继续开辟4个字节空间
}S;

int main()
{
    printf("%d\n",(int)(sizeof(S)));  //8个字节
    return 0;
}