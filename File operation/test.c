#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
            《打开文件》
    FILE *fopen(const char *filename,const char * mode);
    filename  --文件名字
    mode --打开的模式
    int fgetc();  //返回值为EOF的时候，表示文件读取结束
*/

int main()
{
    //打开文件
    FILE *file = fopen("test.txt", "w"); //w可写，新建一个文件  //r可读，不存在打开失败
    if (file == NULL)
    {
        printf("%s\n", strerror(errno));
    }

    //写文件
    fputc('b', file);
    fputc('i', file);
    fputc('t', file);

    // //读文件
    // printf("%c", fgetc(file));
    // printf("%c", fgetc(file));
    // printf("%c", fgetc(file));

    //关闭文件
    fclose(file);
    file = NULL;
    return 0;
}

/*
                《二》
    size_t fwrite(const void *buffer,size_t size,size_t count,FILE *stream);
    size_t fread(const void *buffer,size_t size,size_t count,FILE *stream);
    size_t --元素大小  单位字节
    count --元素个数
    buffer --  要写入的内容原来存放的位置  或者  读取到的内容要存放的位置
    stream --  写入的位置  或者  读取的位置
    //返回值为真实读取到的元素的个数
*/

// typedef struct S
// {
//     char name[20];
//     int age;
//     double score;
// } S;
// //以二进制的形式写入文件
// int main()
// {
//     S s = {"张三", 20, 78.4};
//     FILE *file = fopen("test.txt", "wb"); //以二进制的形式写入文件
//     if(file==NULL)
//     {
//         return 0;
//     }
//     //写文件
//     fwrite(&s, sizeof(S), 1, file);
//     //关闭文件
//     fclose(file);
//     file = NULL;
//     return 0;
// }

// //以二进制的形式读取文件
// int main()
// {
//     S s = {0};
//     FILE *file = fopen("test.txt", "rb");
//     if(file==NULL)
//     {
//         return 0;
//     }
//     //写文件
//     fread(&s, sizeof(S), 1, file);
//     printf("%s %d %lf\n", s.name, s.age, s.score);
//     //关闭文件
//     fclose(file);
//     file = NULL;
//     return 0;
// }

/*
            《三》
    char *fgets(char *string,int n,FILE *stream);读取一行数据
    string -- 读取到的字符存放的位置
    n   ---   读取的字符数量
    stream -- 从哪个流读取
    //
    char *fputs(char *string,FILE *stream);
    string -- 要存的字符串
    stream -- 存放到哪个流
    //
    stdout -- 标准输出设备 （屏幕）
    stdin --  标准输入设备 （键盘）
*/

// int main()
// {
//     char buf[1024] = {"张三\n来了！"};
//     FILE *pf = fopen("test.txt", "w"); //以文本形式写入
//     if(pf==NULL)
//     {
//         return 0;
//     }
//     //写入文件
//     fputs(buf,pf);
//     //关闭
//     fclose(pf);
//     pf == NULL;
//     return 0;
// }
// int main()
// {
//     char buf[1024] = {0};
//     FILE *pf = fopen("test.txt", "r"); //以文本形式读取
//     if(pf==NULL)
//     {
//         return 0;
//     }
//     //读取文件
//     fgets(buf, 1024, pf);
//     printf("%s", buf);
//     fgets(buf, 1024, pf);
//     printf("%s\n", buf);
//     //关闭
//     fclose(pf);
//     pf == NULL;
//     return 0;
// }

/*
                《四》
    int fprintf(FILE *stream,const char *format[,argument]...); //和printf对标
    int printf(const char *format[,argument]...);
    //将format里面的数据输入到stream流里面

    int fscanf(FILE *stream,const char *format[,argument]...); //和scanf对标
    int pscanf(const char *format[,argument]...);
    //将stream流里面的数据以相应的格式输出到format
*/

// int main()
// {
//     char buf[1024] = {"你好啊!"};
//     int num = 10;
//     FILE *pf = fopen("test.txt", "w"); //以文本形式写入
//     if(pf==NULL)
//     {
//         return 0;
//     }
//     //写入文件
//     fprintf(pf,"%d:%s",num,buf); //输出到pf
//     //关闭
//     fclose(pf);
//     pf == NULL;
//     return 0;
// }

// int main()
// {
//     char buf[1024] = {0};
//     int num = 0;
//     FILE *pf = fopen("test.txt", "r"); //以文本形式读取
//     if(pf==NULL)
//     {
//         return 0;
//     }
//     //读取文件
//     fscanf(pf,"%d%s",&num,buf);
//     printf("%d%s\n",num,buf);
//     //关闭
//     fclose(pf);
//     pf == NULL;
//     return 0;
// }

/*
        《五》
    int sprintf(const char *buffer,const char *format[,argument]...); //和printf对标
    int printf(const char *format[,argument]...);
    //将format里面的数据输入到buffer字符串里面(转换成字符形式)

    int sscanf(const char *buffer,const char *format[,argument]...); //和scanf对标
    int pscanf(const char *format[,argument]...);
    //将buffer字符串里面的数据以相应的格式输出到format
*/

// int main()
// {
//     int a = 97;
//     int b = 0;
//     char s[10] = {0};
//     sprintf(s, "%d", a);  //格式化为字符类型，存储到s中
//     printf("%c\n", s[0]);
//     printf("%c\n", s[1]);
//     printf("%s\n", s);

//     sscanf(s, "%d", &b);  //从s字符串获得数据以int存储
//     printf("%d\n", b);
//     return 0;
// }
