#include<stdio.h>
#include<string.h>
// int main()
// {
//     int i = 0;
//     //char s[10] ={'a','b','c','d','e','f','g','\0'};
//     //加不加'\0'都一样，但是要预留一个char大小的空间给系统自己补全'\0'，如果将10改为7,strlen(s)的值将会是随机的
//     char s[10] ={'a','b','c','d','e','f','g'}; 
//     char b[10] = {'0','1','2'};
//     printf("%d\n", (int)strlen(s));  
//     printf("%d\n", (int)sizeof(s));
//     strcpy(s,b);  //将"012\0"拷贝到s

//     for (i = 0; i < 10;i++)
//     {
//         printf("%c", s[i]);
//     }
//     printf("\n%s\n", s);  //'\0'之前表示一串字符串
//     printf("%s\n", s + 4);

//     printf("%d\n", (int)strlen(s));  //遇到'\0'结束计算
//     printf("%d\n", (int)sizeof(s));  //分配空间的大小
//     return 0;
// }


// int main()
// {
//     short a = 0;
//     int b = 10;
//     printf("%d\n", (int)sizeof(a = b + 5));  //输出a的类型的大小，在sizeof()中的表达式不会真的去计算
//     printf("%d\n", a);  //输出0
//     return 0;
// }


//逻辑操作符  &&和||使用时要注意的事项
// int  main()
// {

//     //逻辑与
//     // int i = 0;
//     // int a = 1, b = 2, c = 3, d = 4;
//     // i = a++ && ++b && d++;   
//     // printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);//2 3 3 5

//     // int i = 0;
//     // int a = 0, b = 2, c = 3, d = 4;
//     // i = a++ && ++b && d++;//&&操作符 左边表达式算到的值是0的时候，右边的表达式都不算了 a++
//     // printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);//1 2 3 4

//     //逻辑或
//     int i = 0;
//     int a = 1, b = 2, c = 3, d = 4;
//     i = a++ || ++b || d++;//||操作符 左边表达式算到的值是1的时候，右边的表达式都不算了 a++
//     printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);//2 2 3 4
//     return 0;
// }

// //三目操作符
// int main()
// {
//     int a = 10;
//     int b = 20;

//     // int max = 0;
//     // if(a>b)
//     // {
//     //     max = a;
//     // }
//     // else
//     // {
//     //     max = b;
//     // }
//     // max = (a > b) ? a : b;

//     if(a>5)
//     {
//         b = 3;
//     }
//     else
//     {
//         b = -3;
//     }
//     b = (a > 5 ? 3 : -3);

//     return 0;
// }


// //创建了一个结构体类型--struct Stu
// struct Stu
// {
//     char name[20];
//     int age;
//     char id[20];
// };

// int main()
// {
//     //使用struct Stu这个类型创建了一个学生对象s1，并初始化
//     struct Stu st1 = {"张三", 20, "20200210"};
//     struct Stu *p = &st1;  //指针变量p
//     printf("%s\n", st1.name);
//     printf("%d\n", st1.age);
//     printf("%s\n", st1.id);
//     //结构体变量.成员名

//     //通过指针变量打印，一般用于函数的定义中
//     printf("%s\n", (*p).name);//
//     printf("%d\n", (*p).age);
//     printf("%s\n", (*p).id);

//     printf("%s\n", p->name);
//     printf("%d\n", p->age);
//     printf("%s\n", p->id);   //结构体指针->成员名
//     return 0;
// }


// //隐式类型转换
// //字符型或者短整型在计算过程中为了精度会被提升为普通整型
// int main()
// {
//     char a = 3;
//     //00000000 00000000 00000000 00000011
//     //00000011  
//     char b = 127;
//     //00000000 00000000 00000000 01111111
//     //01111111
//     char c = a + b;
//     //00000000 00000000 00000000 00000011  //提升为普通整型，补充符号位
//     //00000000 00000000 00000000 01111111  //提升为普通整型，补充符号位
//     //00000000 00000000 00000000 10000010
//     //10000010   //c的值  //c为char类型第7位为符号位--1 
//     printf("%d\n", c);
//     //11111111 11111111 11111111 10000010  //提升为普通整型，补充符号位（反码）
//     //11111111 11111111 11111111 10000001  //反码
//     //10000000 00000000 00000000 01111110  //原码 -126
//     return 0;
// }


//整型提升
// int main()
// {
//     char a = 0x7F; //0111 1111 //符号位为0
//     if(a==0x7F)
//     {
//         printf("a\n");
//     }
//     printf("%d\n", a);
//     printf("%d\n", 0x7F);

//     char b = 0xBF; //1011 1111 //符号位为1
//     if(b==0xBF)  //用普通整型比较，先提升再进行比较运算，高位补充符号位  0xBF==0x000000BF b=0x111111BF
//     {
//         printf("b\n");
//     }
//     printf("%d\n",b);
//     printf("%d\n",0xBF);
//     return 0;
// }


//参与了运算就会转换成int类型
// int main()
// {
//     char c = 1;
//     printf("%d\n", (int)sizeof(c)); //1
//     printf("%d\n", (int)sizeof(+c));//4
//     printf("%d\n", (int)sizeof(!c));//4
//     printf("%d\n", (int)sizeof(~c));//4
//     printf("%d\n", (int)sizeof(-c));//4
//     return 0;
// }


// //指针
// int main()
// {
//     // int a = 0x07050301;
//     // char *p = (char *)&a;
//     // printf("%d\n", *p++); //1
//     // printf("%d\n", *p++); //3
//     // printf("%d\n", *p++); //5
//     // printf("%d\n", *p++); //7
//     // p -= 4;
//     // printf("\n");
//     // printf("%d\n", *p);     //1
//     // printf("%d\n", *(p+1)); //3
//     // printf("%d\n", *(p+2)); //5
//     // printf("%d\n", *(p+3)); //7

//     int a = 0x0f050301;
//     int i = 0;
//     char s[9] = {0};
//     for (i = 0; i < 8;i++)
//     {
//         int ret = (a >> 4 * i) & (0x0F);
//         s[7 - i] = (ret >= 0 && ret <= 9) ? ret + '0' : ret + '7';
//     }
//     printf("%s\n", s);

//     //改变
//     char *p = (char *)&a;
//     *p = 6;
//     *(p+1) = 6;
//     *(p+2) = 6;
//     *(p+3) = 0xff;

//     for (i = 0; i < 8;i++)
//     {
//         int ret = (a >> 4 * i) & (0x0F);
//         s[7 - i] = (ret >= 0 && ret <= 9) ? ret + '0' : ret + '7';
//     }
//     printf("%s\n", s);

//     return 0;
// }


// int main()
// {
//     int arr[10] = {0};
//     int *p = arr; //数组名-首元素的地址
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         *(p + i) = 66;
//     }

//     for (i = 0; i < 10;i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }


// //野指针
// int * test()
// {
//     int a = 10;    //局部变量，作用域为本函数，执行完函数就释放空间 
//     return &a;
// }
// int main()
// {
//     int *p = test();
//     printf("%d\n", *p);  //指针指向的空间被释放了
//     return 0;
// }

int main()
{
    // int *p;  //没有局部指针变量没有初始化，默认分配随机值
    // *p = 10;    //随机分配的地址
    // printf("%d\n", *p);
    // return 0;

    //避免野指针
    //1、不越界2、初始化3、指向的变量释放后置NULL4、使用前检查有效性
    int *p = NULL;//初始化，没有确定指向什么变量的时候使用NULL初始化
    int a = 10;
    p = &a;  //指向a

    if(p!=NULL)  //使用前检查有效性
    {
        *p = 20;
    }
    return 0;
}