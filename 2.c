#include<stdio.h>


//创建结构体类型
struct People
{
    char name[20];
    char sex[2];   //中文占两个字节
    int age;
};

int main()
{
    struct People p1 = {"张三","男",25};//利用结构体类型创建该类型的变量
    struct People* pa = &p1;   //struct People类型的指针变量

    // printf("名字：%s\n性别：%s\n年龄：%d\n",p1.name,p1.sex,p1.age);
    // printf("名字：%s\n性别：%s\n年龄：%d\n",(*pa).name,(*pa).sex,(*pa).age);   //*解引用操作符
    // printf("名字：%s\n性别：%s\n年龄：%d\n",pa->name,pa->sex,pa->age);
    //相同的输出结果
    //.   结构体变量.成员
    //->  结构体指针->成员


    //中文的编码
    char z[2] = "中";
    printf("%s\n",z);
    printf("%d  %d\n",z[0],z[1]);  //-42 -48     (-42=214-256)  (-48=208-256)
    char s[2] = {0xD6, 0xD0};   //0xd6 0xd0  214 208
    printf("%s\n",s);

    char val[2];
    val[1] = 54992;          //0xd6d0 =214*256+208
    val[0] = 54992 >> 8;
    printf("%s\n", val);

    // GBK采用双字节表示，总体编码范围为8140-FEFE，首字节在81-FE 之间，尾字节在40-FE 之间，
    // 剔除 xx7F一条线。总计126*190=23940 个码位，共收入21886个汉字和图形符号，
    // 其中汉字（包括部首和构件）21003 个，图形符号883 个。
    // P-Windows3.2和苹果OS以GB2312为基本汉字编码， 
    // Windows 95/98则以GBK为基本汉字编码。

    char a = 'a';
    printf("%c的ASCII码为%d\n",a,a);
    return 0;
}