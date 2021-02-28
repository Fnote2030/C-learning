#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<ctype.h>
//使用相关字符串操作函数需要注意！！！！！
//1、源字符串和目标字符串必须以'\0'结束
//2、要将源字符串中的'\0'拷贝到目标空降
//3、目标空间必须足够大，以确保能存放源字符串
//4、目标空间必须可变
//5、学会模拟实现
  


          
/*              《一》
    strlen()
    函数的功能--------------------------
    自定义函数，模拟strlen()函数的实现
*/

// int main()
// {   
//     //strlen返回的是无符号数，3-6==-3 ，-3的无符号int类型是一个大于0的数字
//     if(strlen("abc")-strlen("abcdef")>0)
//     {
//         printf("haha\n");
//     }
//     else
//     {
//         printf("heh\n");
//     }
//     return 0;
// }

// //递归实现字符串长度的计算  不创建临时变量
// int my_strlen(char *s)
// {
//     if ('\0'== *s)
//     {
//         return 0;
//     }
//     else
//     {
//         return my_strlen(++s) + 1;
//     }
// }
// int main()
// {
//     char arr[] = "afsadgsa";
//     int ret = my_strlen(arr);
//     printf("%d\n", ret);
//     return 0;
// }



          
/*              《二》
    strcpy()
    函数的功能--------------------------
    自定义函数，模拟strcpy()函数的实现
*/

// char *my_strcpy(char *dest,const char *src)
// {
//     char *srcs = dest;
//     assert(src != NULL);
//     assert(dest != NULL);
//     //拷贝src指向的字符串到dest指向的空降，包含'\0'
//     while ((*dest++ = *src++))  
//     {
//         ;
//     }
//     return srcs;  //返回目的数组首地址
// }
// int main()
// {
//     char arr1[] = "abcdefgh";
//     char arr2[] = "hello";
//     printf("%s\n", my_strcpy(arr1, arr2));
//     return 0;
// }



           
/*              《三》
    strcat()
    函数的功能--------------------------
    自定义函数，模拟strcat()函数的实现
*/

// int main()
// {
//     //char arr1[] = "hello";  //空间大小为6，不能再往后面添加数据 ，越界访问
//     char arr1[20] = "hello";  
//     char arr2[] = "world";
//     strcat(arr1, arr2);  //返回值为arr1首元素地址
//     printf("%s\n", arr1);
//     return 0;
// }

// //模拟实现strcat()函数的功能
// char *my_strcat(char *dest,const char *src)
// {
//     char *dests = dest;
//     assert(dest != NULL);
//     assert(src != NULL);
//     //定位到目标字符串的'\0'
//     while (*dest != '\0')
//     {
//         dest++;
//     }
//     //拷贝
//     while((*dest++=*src++))
//     {
//         ;
//     }
//     return dests;
// }
// int main()
// {
//     char arr1[30] = "hello";
//     char arr2[] = "world";
//     printf("%s\n", my_strcat(arr1, arr2));
//     return 0;
// }



          
/*               《四》
    strcmp(char *src1, char *src2)
    函数的功能--------------------------
    比较src1和src2首个不同元素的ascii值的大小
    大于返回1  (>0)，小于返回-1  (<0)，
    全部等于则返回0
    自定义函数，模拟strcmp()函数的实现
*/
// int main()
// {
//     char *str1 = "abcdef";
//     char *str2 = "afaf";
//     int ret = strcmp(str1, str2);
//     if(ret<0)  //不要写成ret==-1
//     {
//         printf("str1<str2\n");
//     }
//     return 0;
// }

// //模拟实现
// int my_strcmp(const char *str1,const char *str2)
// {
//     assert(str1 != NULL);
//     assert(str2 != NULL);
//     while(*str1++ == *str2++)
//     {
//         if(*(str1-1) == '\0')
//         {
//             return 0;
//         }
//     }
//     if (*--str1 > *--str2)
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }
// int main()
// {
//     char *s1 = "abc";
//     char *s2 = "abcd";
//     int ret = my_strcmp(s1, s2);
//     printf("ret=%d\n", ret);
//     return 0;
// }



           
/*               《五》
    strncpy(char *dest,const char * src,int count)
    函数的功能--------------------------
    拷贝count个字符,要拷贝的源字符串长度（包括了'\0'）不够的时候，剩下的长度补充'\0'
    自定义函数，模拟strncpy()函数的实现
*/

// //注意！！！！！
// int main()
// {
//     char s1[10] = "abcdefg";
//     char s2[] = "jfg";
//     strncpy(s1, s2, 6);
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         printf("%c", s1[i]); //jfg   g   要拷贝的源字符串长度不够的时候，剩下的长度补充'\0'
//     }
//     return 0;
// }

// //模拟实现
// char *my_strncpy(char *dest,const char * src,int count)
// {
//     char *dests=dest;
//     while((count && *src!='\0'))//拷贝字符串 ，不包括'\0'
//     {
//         count--;
//         *dest++ = *src++;
//     }
//     if(count)
//     {
//         while(count--)  //源字符串长度不够，用'\0'补够长度
//         {
//             *dest++ = '\0';
//         }
//     }
//     return dests;
// }
// int main()
// {
//     char s1[10] = "abcdefg";
//     char s2[] = "jfg";
//     my_strncpy(s1, s2, 2);
//     int i = 0;
//     for (i = 0; i < 10;i++)
//     {
//         printf("%c", s1[i]); //jfg   g   要拷贝的源字符串长度不够的时候，剩下的长度补充'\0'
//     }
//     return 0;
// }



           
/*               《六》
    strncat(char *dest,const char * src,int count)
    函数的功能--------------------------
    拷贝count个字符+'\0'，当要追加的长度大于源字符串长度的时候，只追加整个字符串+'\0'
    自定义函数，模拟strncat()函数的实现
*/

// int main()
// {
//     char s1[30] = "hello\0xxxxxxxxxxxxx";
//     char s2[] = "world";
//     strncat(s1, s2, 8);
//     int i = 0;
//     for (i = 0; i < 30;i++)
//     {
//         printf("%c", s1[i]);  //输出  helloworld xxxxxxxx
//     }
//     return 0;
// }

// //模拟实现
// char *my_strncat(char *dest,const char *src,int count)
// {
//     char *dests;
//     //定位到末尾
//     while(*dest++)
//     {
//         ;
//     }
//     dest--;
//     //
//     while(count--)
//     {    
//         if (!(*dest++ = *src++))//源字符串拷贝完,包括'\0'
//         {
//             return dests;
//         }
//     }
//     *dest = '\0';  //追加完count个字符，添加'\0'
//     return dests;
// }
// int main()
// {
//     char s1[30] = "hello\0xxxxxxxxxxxxx";
//     char s2[] = "world";
//     my_strncat(s1, s2, 8);
//     int i = 0;
//     for (i = 0; i < 30;i++)
//     {
//         printf("%c", s1[i]);  //输出  helloworld xxxxxxxx
//     }
//     return 0;
// }




           
/*                 《七》
    strncmp(char *dest,const char * src,int count)
    函数的功能--------------------------
    比较字符串的前count个字符
    自定义函数，模拟strncmy()函数的实现
*/

// //模拟实现
// int my_strncmp(const char *dest,const char *src,int count)
// {
//     while(count-- && *dest && *src)
//     {
//         if (*dest++ != *src++)//逐个字符比较，不相同时返回
//         {
//             if(*--dest > *--src)
//             {
//                 return 1;
//             }
//             else
//             {
//                 return -1;
//             }
//         }
//     }
//     //比完count个字符，全部相同
//     return 0;
// }
// int main()
// {
//     const char *p1 = "abcdef\0d";
//     const char *p2 = "abcdef\0f";
//     int count = 10;
//     int ret = my_strncmp(p1, p2, count);
//     printf("%d\n", ret);
//     return 0;
// }



           
/*                《八》
    strstr(const char *src1,const char *src2)
    函数的功能--------------------------
    比较字符串的前count个字符
    自定义函数，模拟strstr()函数的实现
*/

// int main()
// {
//     char *p1 = "abcdefpkp";
//     char *p2 = "def";
//     char *ret = strstr(p1, p2); //存在子串返回第一个子串的地址，不存在返回空指针
//     if(ret==NULL)
//     {
//         printf("不存在子串\n");
//     }
//     else
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }

// //模拟实现
// char *my_strstr(const char *str1, const char *str2)
// {
//     assert(str1 != NULL);
//     assert(str2 != NULL);
//     const char *s1 = str1;
//     const char *s2 = str2;
//     const char *start = str1;
//     if(*str2=='\0')
//     {
//         return (char *)str1;
//     }
//     while(*start) //一次向后移动一个字符，直到字符串遍历结束
//     {
//         s1 = start;//这次开始的位置
//         s2 = str2;//从首部开始
//         while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//         {
//             s1++;
//             s2++;
//         }
//         if (*s2 == '\0') //匹配str2
//         {
//             return (char *)start;
//         }
//         if(*s1 == '\0') //遍历到末尾，仍然没有匹配
//         {
//             return NULL;
//         }
//         start++;
//     }
//     return NULL;
// }
// int main()
// {
//     char *p1 = "abcdefghj";
//     char *p2 = "def";
//     char *ret = my_strstr(p1, p2); //存在子串返回第一个子串的地址，不存在返回空指针
//     if(ret==NULL)
//     {
//         printf("不存在子串\n");
//     }
//     else
//     {
//         printf("%s\n", ret);
//     }
//     return 0;
// }




           
/*             《九》
    char *strtok(char *src,const char *sep)
    函数的功能-------------------------- （切割字符串）
    sep用作分隔符的字符集合
    src要被分割的字符串起始位置
    1、src不为NULL，找到第一个标记并保存该位置，并返回标记前面一段字符串的起始地址
    2、src为NULL，在同一个字符串中被保存的位置开始，查找下一个标记
*/

int main()
{
    char arr[] = "1221412@qq.com";
    char *p = ".@";  //不分先后顺序
    // char *ret = NULL;
    // for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
    // {
    //     printf("%s ", ret);
    // }
    char *ret = strtok(arr, p);
    while(ret!=NULL)
    {
        printf("%s ", ret);
        ret = strtok(NULL, p);
    }
    return 0;
}





/*             《十》
    char *strerror(int errnum)
    函数的功能-------------------------- 返回错误码所对应的的错误信息

*/

// int main()
// {
//     //错误码  错误信息
//     // 0----No error
//     // 1----Operation not permitted
//     // 2----No such file or directory
//     // 3----No such process
//     // 4----Interrupted function call
//     // 5----Input/output error
//     // 6----No such device or address
//     // 7----Arg list too long
//     // 8----Exec format error
//     // 9----Bad file descriptor
//     //errno 是一个全局的的错误码的变量
//     //当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到，errno中
//     char *str = NULL;
//     int i = 0;
//     for (i = 0; i <= 42;i++)  //43个错误码
//     {
//         str = strerror(i);
//         printf("%d----%s\n", i, str);
//     }
//     return 0;
// }

// int main()
// {
//     FILE* pf = fopen("test.txt", "r");
//     if(pf==NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         printf("打开文件成功！");
//     }
//     return 0;
// }



/*             《十一》
    列举字符判断库函数
    自定义函数，模拟strstr()函数的实现
*/

// int main()
// {
//     char arr[] = "i'm A StudeNt.";
//     int i = 0;
//     while(arr[i])
//     {
//         if(islower(arr[i])) //判断是否为小写
//         {
//             arr[i] = toupper(arr[i]); //转大写 -32
//             //arr[i] -= 32;
//         }
//         i++;
//     }
//     printf("%s\n", arr);
//     return 0;
// }