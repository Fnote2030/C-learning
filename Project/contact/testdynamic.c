/*
    1、存放1000个好友的信息（名字、电话、性别、住址、年龄）
    2、增加好友的信息
    3、删除指定名字的好友的信息
    4、查找好友的信息
    5、修改好友的信息
    6、打印好友的信息
    7、排序
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<errno.h>
/*
    头文件----------------------------------------------------------
*/
//通讯录好友的信息
#define MAX_NAME 20  //名字长度
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define Capacity 3

//通讯录好友信息的类型
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;

//通讯录的类型
typedef struct Contact 
{
    PeoInfo *data; //通讯录的联系人的信息
    int size;   //当前通讯录的联系人的数量
    int max_size; //当前通讯录的容量
} Contact;

//功能选项
enum Option
{
    EXIT,  //0
    ADD,   //1
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    SAVE
};

/*
    函数定义---------------------------------------------------------
*/
void CheckCapacity(Contact *ps);

//把保存的通讯录信息加载到通讯录中
void LoadContact(Contact *ps)
{
    PeoInfo tmp;  //每次读取的联系人的数据
    FILE *file = fopen("contact.dat", "rb");   //二进制的读
    if((file == NULL))
    {
        printf("loadcontact>>%s\n", strerror(errno));
        return;
    }
    //读取文件
    while (fread(&tmp, sizeof(PeoInfo), 1, file) >= 1) //没有读完，返回实际读取的元素个数
    {
        CheckCapacity(ps);    //检查容量是否够
        ps->data[ps->size] = tmp;  //储存
        ps->size++;  //当前联系人个数加一
    }
    fclose(file);
    file == NULL;
    
}

//初始化
void InitContact(Contact *ps)
{
    ps->data = (PeoInfo *)malloc(Capacity * sizeof(PeoInfo)); //开辟3个容量的通讯录
    if(ps->data == NULL)  //开辟失败
    {
        return;
    }
    ps->max_size = 3;  //当前通讯录容量大小
    ps->size = 0;
    //把保存的通讯录信息加载到通讯录中
    LoadContact(ps);
}

//判断是否增容，不够就增加
void CheckCapacity(Contact *ps)
{
    if(ps->size==ps->max_size)
    {
        PeoInfo *ptr = (PeoInfo *)realloc(ps->data, (ps->max_size + 2) * sizeof(PeoInfo));//不够了增加两个容量
        if(ptr != NULL)  //增容成功
        {
            printf("增容成功!\n");
            ps->data = ptr;  //接管
            ps->max_size += 2; //当前容量增加2
        }
        else
        {
            printf("增容失败！\n");
        }
    }
}

//增加一个信息到通讯录
void AddContact(Contact *ps)
{
    CheckCapacity(ps);
    printf("请输入名字:>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄:>");
    scanf("%d", &(ps->data[ps->size].age));
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址:>");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功！\n");
}
//显示通讯录
void ShowContact(const Contact *ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空!\n");
    }
    else
    {
        int i = 0;
        printf("  %-10s%-6s%-6s%-14s%-20s\n","名字","年龄","性别","电话","地址");
        for (i = 0; i < ps->size; i++)
        {

            printf("  %-10s%-6d%-6s%-14s%-20s\n", ps->data[i].name,
            ps->data[i].age, ps->data[i].sex, ps->data[i].tele, ps->data[i].addr);
        }
    }
}

//找到指定名字的通讯录，返回下标，找不到返回-1
int FindByName(const Contact *ps,char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        if(0 == strcmp(ps->data[i].name, name))
        {
            return i; //找到了，返回下标
        }
    }
    return -1;
}

//删除指定姓名的通讯录
void DelContact(Contact *ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空!\n");
    }
    else
    {
    char name[MAX_NAME];
    printf("请输入要删除的联系人的名字：\n");
    scanf("%s", name);

    //查找指定的人在什么位置
    int pos = FindByName(ps, name); //返回要删除联系人的下标

    if(-1 == pos) //不存在
    {
        printf("要删除的人不存在！\n");
    }
    else  //存在，删除数据
    {
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功!\n");
    }
    }
}
//查找指定人的信息
void SearchContact(const Contact *ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空!\n");
    }
    else
    {
        char name[MAX_NAME];
        printf("请输入你要查找的人的名字:");
        scanf("%s", name);
        int pos = FindByName(ps, name);
        if(-1 == pos) //不存在
        {
            printf("通讯录中没有该联系人！\n");
        }
        else
        {   
            //找到了，打印出来
            printf("  %-10s%-6s%-6s%-14s%-20s\n","名字","年龄","性别","电话","地址");
            printf("  %-10s%-6d%-6s%-14s%-20s\n", ps->data[pos].name,
            ps->data[pos].age, ps->data[pos].sex, ps->data[pos].tele, ps->data[pos].addr);
        }
    }
}
//修改指定联系人的信息
void ModifyContact(Contact *ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空！\n");
    }
    else
    {
        char name[MAX_NAME];
        printf("请输入要修改的人的名字:>");
        scanf("%s", name);
        int pos = FindByName(ps, name); //找到返回下标，没有找到返回-1
        if(-1 == pos)
        {
            printf("要修改的联系人不存在！\n");
        }
        else
        {
            printf("请输入名字:>");
            scanf("%s", ps->data[pos].name);  
            printf("请输入年龄:>");
            scanf("%d", &(ps->data[pos].age)); 
            printf("请输入性别:>");
            scanf("%s", ps->data[pos].sex);  
            printf("请输入电话:>");
            scanf("%s", ps->data[pos].tele);
            printf("请输入地址:>");
            scanf("%s", ps->data[pos].addr);
        }
    }
}
//将通讯录保存到文件中
void SaveContact(Contact *ps)
{
    int i = 0;
    FILE *file = fopen("contact.dat", "wb");
    if(file==NULL)
    {
        //打开失败
        printf("savecontact>>%s\n", strerror(errno)); 
        return;
    }
    //写通讯录的信息到文件中
    for (i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, file);
    }
    fclose(file);
    file == NULL;

}


/*
    test-----------------------------------------------------------------
*/
void menu()
{
    printf("*************************************\n");
    printf("****** 1、增加   2、删除 ************\n");
    printf("****** 3、查找   4、修改 ************\n");
    printf("****** 5、展示   6、排序 ************\n");
    printf("****** 7、存储   0、退出 ************\n");
    printf("*************************************\n");
}
int main()
{
    int input = 0;
    //创建通讯录
    Contact con;//con就是通讯录，里面包含了：通讯录信息,size,当前通讯录容量capacity
    //初始化通讯录
    InitContact(&con);
    //
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input)
        {
            case ADD:
                AddContact(&con);   //增加好友, con.size增加
                break;
            case DEL:
                DelContact(&con); //删除指定姓名的通讯录
                break;
            case SEARCH:         //查找指定人的信息
                SearchContact(&con);
                break;
            case MODIFY:
                ModifyContact(&con); //修改指定联系人
                break;
            case SHOW:
                ShowContact(&con); //输出整个通讯录
                break;
            case SAVE:
                SaveContact(&con);  //将通讯录保存到文件里
                break;
            case SORT:
                printf("该功能未添加！\n");
                break;
            case EXIT:
                SaveContact(&con);  //将通讯录保存到文件里
                free(con.data);  //释放通讯录存储联系人信息的空间
                con.data = NULL;
                printf("退出通讯录！\n");
                break;
            default:
                printf("选择错误！\n");
                break;
        }
    } while(input);
    return 0;
}