#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define ROW 9
#define COL 9   //规格
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10  //地雷的数量

//打印菜单
void mune()
{
    printf("******** 扫雷游戏 *********\n");
    printf("*********1、开始 **********\n");
    printf("*********0、退出 **********\n");
    printf("***************************\n");
    printf("请选择:>");
}


//初始化数组的函数
void InitBoard(char board[ROWS][COLS],int row,int col,char s)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row;i++)
    {
        for (j = 0; j < col;j++)
        {
            board[i][j] = s;
        }
    }
}
//打印数组
void DisplayBoard(char board[ROWS][COLS],int row,int col )
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row - 1;i++)
    {
        printf(" %d  ",i);  //竖号
    }
    printf("\n");

    for (i = 1; i < row-1; i++)
    {
        printf(" %d ",i); //行号
        for (j = 1; j < col-1; j++) //打印数据行
        {
            if (1 == j)
            {
                printf("|");
            }
            printf(" %c |", board[i][j]);
        }
        printf("\n");    //整行输出完，换行
        if (i < row - 2) //打印分割行
        {
            for (j = 1; j < col-1; j++)
            {
                if (1 == j)
                {
                    printf("   |");
                }
                printf("---|");
            }
            printf("\n"); //整行输出完，换行
        }
    }
    printf("\n");
}

//布置地雷
void SetMine(char board[ROWS][COLS],int row,int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand() % (row - 2) + 1;
        int y = rand() % (col - 2) + 1;
        if(board[x][y]==' ')
        {
            board[x][y] = 'X';//布置地雷
            count--;
        }
    }
}

//该位置周围地雷的数量（row,col）
int get_mine_count(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x = 0;
    int y = 0;
    int win = 0; //本次排除不是地雷的数量
    int count = 0;
    for (x = row - 1; x <= row + 1;x++)
    {
        for (y = col - 1; y <= col + 1;y++)  
        {
            //是地雷 
            if(mine[x][y]=='X' && !(x==row && y==col) /*&& x,y>0 && x<ROWS-1 && y<COLS-1*/)
            {
                win += (mine[x][y] - ' ');    //'X'-' '== 88-32  ==56
            }
        }  
    }
    if(win/56 > 0)//周围有地雷，该位置不能向外展开
    {
        show[row][col] = win / 56 + '0';  //周围的地雷数量 字符型
        return 1;           //没有展开只排除一个
    }
    else
    {
        show[row][col] = ' ';    //周围没有地雷的位置都输出 ' ' 
    }

    //向外展开  周围没有地雷                    
    for (x = row - 1; x <= row + 1;x++)
    {
        for (y = col - 1; y <= col + 1;y++)  
        {
            //不是上一次遍历的入口，在范围内, 没有排查过，不是自身
            if(show[x][y]=='*' && !(x==row && y==col) && mine[x][y]!='O' && x>0 && y>0 && x<ROWS-1 && y<COLS-1)
            {
                mine[x][y] = 'O'; //上一个遍历入口
                count += get_mine_count(mine,show,x,y);  //存储周围
                mine[x][y] = ' '; //关闭入口
            }
        }  
    }
    return count+1;  //排除自己的位置加上展开的位置
}

//扫雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while(win<(row-2)*(col-2)-EASY_COUNT)
    { 
        printf("请输入要排查地雷的坐标：>");
        scanf("%d%d",&x,&y);
        if(x>=1 && x<row-1 && y>=1 && y<col-1 && show[x][y]=='*') //范围内，没有排过
        {
            //合法
            //1、踩雷
            if(mine[x][y]=='X')
            {
                printf("很遗憾，你被炸死了!\n");
                printf("所有地雷的位置\n");
                DisplayBoard(mine,row,col);
                break;
            }
            else //2、不是地雷 mine[x][y]=='0'
            {
                int num = get_mine_count(mine,show,x,y);  //返回此次排除的数量
                system("cls");  //清屏
                //mune();
                //DisplayBoard(mine,row,col);  
                DisplayBoard(show,row,col);  //排一次地雷打印一次
                win+=num;  //总共排查的的数量
                printf("在%d个位置中一共有%d个雷，现在排除了%d个不是雷的位置！\n",(row-2)*(col-2),EASY_COUNT,win);
            }
        }
        else
        {
            printf("输入的坐标非法，请重新输入!\n");
        }
    }
    if(win==(row-2)*(col-2)-EASY_COUNT)
    {
        printf("恭喜你，排雷成功！\n");
    }
}


//开始游戏
void game()
{
    char mine[ROWS][COLS] = {0};//存储地雷的位置信息
    char show[ROWS][COLS] = {0}; //存储反映地雷的位置的信息
    InitBoard(mine,ROWS,COLS,' ');
    InitBoard(show,ROWS,COLS,'*');//初始化
    //布置地雷
    SetMine(mine,ROWS,COLS);
    //DisplayBoard(mine,ROWS,COLS);
    //打印
    DisplayBoard(show,ROWS,COLS);
    //扫雷
    FindMine(mine,show,ROWS,COLS);
}



int main()
{
    int input = 0;
    system("cls");
    srand((unsigned int)time(NULL));
    do
    {
        mune();
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                system("cls");

                game();
                break;
            case 0:
                printf("退出游戏!\n");
                break;
            default:
                printf("输入错误请重新输入!\n");
                break;
        }
    } 
    while (input);
    return 0;
}