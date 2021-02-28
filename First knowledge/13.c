//结构体
#include<stdio.h>


// // //struct 结构体关键字   Stu --结构体标签   struct Stu 结构体类型
// // struct Stu
// // {
// //     char name[20];
// //     short age;
// //     char sex[2];
// //     char tele[12];
// // };

// // struct Stu
// // {
// //     char name[20];
// //     short age;
// //     char sex[2];
// //     char tele[12];
// // }s1,s2,s3;   //声明的同时定义三个struct Stu类型的全局变量  //不建议

// typedef struct Stu
// {
//     char name[20];
//     short age;
//     char sex[5];
//     char tele[12]; 
// }Stu;  //将结构体类型 struct Stu 重命名为 Stu   //推荐风格


// int main()
// {
//     struct Stu s2={"李四",24,"保密","12523134124"};
//     Stu s1 = {"张三", 20, "男", "1234567890"};
//     return 0;
// }



//嵌套结构体类型
// typedef struct S
// {
//     int a;
//     char arr[20];
//     double d;
// } S;

// typedef struct T
// { 
//     char ch[20];
//     S s;    //结构体的类型为结构体类型
//     char *pc; //结构体的类型为指针 

// } T;

// int main()
// {
//     char arr[] = "hello world!";
//     T t = {"haha", {100, "hello world!", 3.14}, arr};
    
//     //打印 
//     printf("%s\n", t.ch);  //haha

//     printf("%s\n", t.s.arr); //hello world!
//     printf("%lf\n", t.s.d);  //3.140000

//     printf("%s\n", t.pc);  //hello world!
//     return 0;
// }


// //结构体变量的打印
// typedef struct Stu
// {
//     char name[20];
//     short age;
//     char sex[5];
//     char tele[12]; 
// }Stu;  //将结构体类型 struct Stu 重命名为 Stu   //推荐风格

// void Print1(Stu stu)
// {
//     printf("name:%s\n", stu.name);  
//     printf("age: %d\n", stu.age);
//     printf("sex: %s\n", stu.sex); 
//     printf("tele:%s\n", stu.tele);
// }
// void Print2(Stu *stu)  //推荐1、不用开辟空间，不用临时拷贝2、能对变量进行操作
// {
//     printf("name:%s\n", stu->name);  //(*stu).name
//     printf("age: %d\n", stu->age);  //(*stu).age
//     stu->age = 20;
//     printf("sex: %s\n", stu->sex);
//     printf("tele:%s\n", stu->tele);
// }

// int main()
// {
//     Stu s = {"李四", 34, "男", "124535124"};
//     Print2(&s);
//     Print1(s);
//     return 0;
// }
 

// //可能的死循环
// int main()
// {
//     //局部变量放在栈区，从高位地址开始使用  
//     int i = 0;   //分配较高的地址位
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   //分配较低的地址位
//     for (i = 0; i <= 13;i++)    //调试出现死循环  //&i == &arr[11]  i的地址和arr[11]的地址相同
//     {
//         printf("hehe\n");
//         arr[i] = 0;   //arr[11]=0; 等价于  i=0;
//     }
//     return 0;
// }


