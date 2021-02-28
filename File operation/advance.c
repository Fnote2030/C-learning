#include<stdio.h>
#include<stdlib.h>

/*
        《文件的随机读取》
    int fseek(FILE *stream,long offset,int origin);
    调整文件文件指针的位置，
    offset -- 偏移量
    origin -- 文件指针的当前位置 
        1、SEEK_END  文件末尾的位置        2
        2、SEEK_CUR  文件的指针的当前位置   1
        3、SEEK_SET  文件的起始位置        0
*/

// int main()
// {
//     char s[128] = {0};
//     FILE *file = fopen("test.txt", "rb");
//     if(file==NULL)
//     {
//         return 0;
//     }
//     //1、定位文件指针
//     fseek(file, -10, SEEK_END);  //文件指针在 文件的起始位置向后两个位置处
//     //2、读取文件
//     fgets(s,12,file); //读取12字节的文件数据
//     printf("%s\n", s);

//     //关闭
//     fclose(file);
//     file == NULL;
//     return 0;
// }


/*
        《返回文件指针的偏移量》
    long int ftell(FILE *stream)
    //返回文件指针距离起始位置的偏移量
*/
// int main()
// {
//     FILE *file = fopen("test.txt", "r+");
//     if(file==NULL)
//     {
//         return 0;
//     }
//     fseek(file, 3, SEEK_SET);
//     printf("%d\n", (int)ftell(file));  //文件指针的偏移量 --相对文件起始位置
//
//     fclose(file);
//     file=NULL;
//     return 0;
// }



// /*
//         《让文件指针返回文件的起始位置》
//     void rewinf(FILE *stream)
// */
// int main()
// {
//     FILE *file = fopen("test.txt", "r+");
//     if(file==NULL)
//     {
//         return 0;
//     }
//     int ch = fgetc(file);
//     printf("%c\n", ch);
//     rewind(file);   //文件指针回到起始位置
//     ch = fgetc(file);
//     printf("%c\n", ch);

//     fclose(file);
//     file = NULL;
//     return 0;
// }




/*
        《文件读取结束状态的判断》
    
*/
int main()
{
    FILE *file = fopen("test.txt", "rb");
    if(file==NULL)
    {
        perror("open test.txt");
        return 0;
    }
    int ch = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    if(feof(file))
    {
        printf("文件读取完成！\n");
    }
    else if(ferror(file))
    {
        perror("文件读取失败");
    }
    fclose(file);
    file = NULL;
    return 0;
}







