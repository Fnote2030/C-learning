#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 6
#define COL 6

//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col;j++)
        {
            board[i][j] = ' ';
        }
    }
}

//打印棋盘
void DispalyBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row;i++)
    {
        for (j = 0; j < col;j++)  //打印数据行
        {
            if(0==j)
            {
                printf("|");
            }
            printf(" %c |",board[i][j]);
        }
        printf("\n");  //整行输出完，换行
        if(i<row-1)  //打印分割行
        {
            for (j = 0; j < col;j++)
            {
                if(0==j)
                {
                    printf("|");
                }
                printf("---|");
            }
            printf("\n"); //整行输出完，换行
        }
    }
}


//玩家下棋
void PlayerMove(char board[ROW][COL],char board2[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    printf("玩家走！\n");
    printf("请输入要下的坐标（空格分开）：>");
    while(1)
    {
        scanf("%d %d",&x,&y);
        if(x>=1&&x<=ROW  &&y>=1&&y<=COL)  //输入坐标合法
        {
            if(board[x-1][y-1]==' ')
            {
                board[x - 1][y - 1] = 'X';
                board2[x - 1][y - 1] = 'X';
                break;
            }
            else
            {
                printf("该坐标被占用，请重新输入!\n");
            }
        }
        else
        {
            printf("输入的坐标不合法,请重新输入!\n");
        }
    }

}


//电脑下棋   //随机的下棋，玩家很容易赢  board1电脑 board2玩家
void ComputerMove(char board[ROW][COL],char board1[ROW][COL],char board2[ROW][COL],int row,int col)
{
    int pow = 0;  //权分
    int maxpow = 0; //目前最大权分
    int w = 0;
    int l = 0;
    int x = 0; //落子位置
    int y = 0; //落子位置
    for (w = 0; w < row;w++)
    {
        for (l = 0; l < col;l++)   //计算每一个位置的权分
        {
            int i = 0;
            int j = 0;
            int k = 0;
            if(board[w][l]!=' ')//电脑准备落子的位置非空，跳过本次循环
            {
                continue;
            }

            board1[w][l] ='O';
            board2[w][l] ='O';   //该位置为空，假设电脑落子在该位置
            //所有行的情况
            for (i = 0; i < row;i++)
            {
                for (j = 1; j < col-1;j++)//一行的情况
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i][j - 1] - ' ' + 1) * (board1[i][j + 1] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i][j - 1] == 'X') || (board2[i][j + 1] == 'X')));
                    pow += (board2[i][j] - ' ' + 1) * (board2[i][j - 1] - ' ' + 1) * (board2[i][j + 1] - ' ' + 1) *
                           (((board1[i][j] == 'O') ^ (board1[i][j - 1] == 'O') ^ (board1[i][j + 1] == 'O')));
                }
            }                                                                       
            //所有竖的情况
            for (j = 0; j < col;j++)
            {
                for (i = 1; i < row-1;i++)//一列的情况
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i-1][j] - ' ' + 1) * (board1[i+1][j] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i-1][j] == 'X') || (board2[i+1][j] == 'X')));
                    pow += (board2[i][j] - ' ' + 1) * (board2[i-1][j] - ' ' + 1) * (board2[i+1][j] - ' ' + 1) *
                           (((board1[i][j] == 'O') ^ (board1[i-1][j] == 'O') ^ (board1[i+1][j] == 'O')));
                }
            }
            //左上到右下方向的情况
            for (k = 1; k < row-1;k++) //左下部分
            {
                for (i = k, j = 1; i < row-1 && j < col-1;i++,j++)
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i - 1][j - 1] - ' ' + 1) * (board1[i + 1][j + 1] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i - 1][j - 1] == 'X') || (board2[i + 1][j + 1] == 'X')));
                     pow += (board2[i][j] - ' ' + 1) * (board2[i - 1][j - 1] - ' ' + 1) * (board2[i + 1][j + 1] - ' ' + 1) *
                            (((board1[i][j] == 'O') ^ (board1[i - 1][j - 1] == 'O') ^ (board1[i + 1][j + 1] == 'O')));
                }
            }
            for (k = 2; k < col-1;k++) //右上部分
            {
                for (i = 1, j = k; i < row-1 && j < col-1;i++,j++)
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i - 1][j - 1] - ' ' + 1) * (board1[i + 1][j + 1] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i - 1][j - 1] == 'X') || (board2[i + 1][j + 1] == 'X')));
                    pow += (board2[i][j] - ' ' + 1) * (board2[i - 1][j - 1] - ' ' + 1) * (board2[i + 1][j + 1] - ' ' + 1) *
                           (((board1[i][j] == 'O') ^ (board1[i - 1][j - 1] == 'O') ^ (board1[i + 1][j + 1] == 'O')));
                }
            }
            //左下到右上方向的情况
            for (k = row - 2; k > 0; k--) //左上部分
            {
                for (i = k, j = 1; i > 0 && j < col-1;i--,j++)
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i - 1][j + 1] - ' ' + 1) * (board1[i + 1][j - 1] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i - 1][j + 1] == 'X') || (board2[i + 1][j - 1] == 'X')));
                    pow += (board2[i][j] - ' ' + 1) * (board2[i - 1][j + 1] - ' ' + 1) * (board2[i + 1][j - 1] - ' ' + 1) *
                           (((board1[i][j] == 'O') ^ (board1[i - 1][j + 1] == 'O') ^ (board1[i + 1][j - 1] == 'O')));
                }
            }
            for (k = 2; k < col-1;k++) //右下部分
            {
                for (i = row-2, j = k; i > 0 && j < col-1;i--,j++)
                {
                    pow += (board1[i][j] - ' ' + 1) * (board1[i - 1][j + 1] - ' ' + 1) * (board1[i + 1][j - 1] - ' ' + 1) *
                           (!((board2[i][j] == 'X') || (board2[i - 1][j + 1] == 'X') || (board2[i + 1][j - 1] == 'X')));
                    pow += (board2[i][j] - ' ' + 1) * (board2[i - 1][j + 1] - ' ' + 1) * (board2[i + 1][j - 1] - ' ' + 1) *
                           (((board1[i][j] == 'O') ^ (board1[i - 1][j + 1] == 'O') ^ (board1[i + 1][j - 1] == 'O')));
                }
            }
            printf("pow[%d][%d]=%d\n",w,l,pow);
            if (pow > maxpow) //将最大权分的位置存储起来
            {
                x = w;
                y = l;
                maxpow = pow;
                
            }
            board1[w][l] =' ';
            board2[w][l] =' ';   //假设电脑落子的位置重置为空
            pow = 0;  //置零
        }
    }
    printf("电脑下！\n");
    board[x][y] = 'O';  //落子
    board1[x][y] = 'O'; //电脑棋盘记录落子
}



//判断棋盘满了没有 返回1满了，返回0没满
int IsFull(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row;i++)
    {
        for (j = 0; j < col;j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;//没满
            }
        }
    }
    return 1;//满了
}

//判断胜负 返回X玩家赢；返回O电脑赢了；返回Q平局；返回C继续
char IsWin(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    int k = 0;
    //判断行
    for (i = 0; i < row;i++)
    {
        for (j = 1; j < col-1;j++)//一行的情况
        {
            if(board[i][j]==board[i][j-1] && board[i][j]==board[i][j+1] && board[i][j]!=' ')
            {
                return board[i][j];
            }
        }
    }
    //判断竖
    for (i = 0; i < col;i++)
    {
        for (j = 1; j < row-1;j++)//一列的情况
        {
            if(board[j][i]==board[j-1][i] && board[j][i]==board[j+1][i] && board[j][i]!=' ')
            {
                return board[j][i];
            }
        }
    }
    //判断左上到右下方向的
    for (k = 1; k < row-1;k++) //左下部分
    {
        for (i = k, j = 1; i < row-1 && j < col-1;i++,j++)
        {
            if(board[i][j]==board[i-1][j-1] && board[i][j]==board[i+1][j+1] && board[i][j]!=' ')
            {
                return board[i][j];
            }
        }
    }
    for (k = 2; k < col-1;k++) //右上部分
    {
        for (i = 1, j = k; i < row-1 && j < col-1;i++,j++)
        {
            if(board[i][j]==board[i-1][j-1] && board[i][j]==board[i+1][j+1] && board[i][j]!=' ')
            {
                return board[i][j];
            }
        }
    }
    //判断左下到右上方向的
    for (k = row - 2; k > 0; k--) //左上部分
    {
        for (i = k, j = 1; i > 0 && j < col-1;i--,j++)
        {
            if(board[i][j]==board[i-1][j+1] && board[i][j]==board[i+1][j-1] && board[i][j]!=' ')
            {
                return board[i][j];
            }
        }
    }
    for (k = 2; k < col-1;k++) //右下部分
    {
        for (i = row-2, j = k; i > 0 && j < col-1;i--,j++)
        {
            if(board[i][j]==board[i-1][j+1] && board[i][j]==board[i+1][j-1] && board[i][j]!=' ')
            {
                return board[i][j];
            }
        }
    }
    //如果棋盘下满
    if(1==IsFull(board,ROW,COL))
    {
        return 'Q'; //棋盘满了
    }
    return 'C';
}


//开始游戏
void game()
{
    char board[ROW][COL] = {0};
    char board1[ROW][COL] = {0};  //电脑的棋子
    char board2[ROW][COL] = {0};  //玩家的棋子
    char ret = 0;
    InitBoard(board, ROW, COL);  //初始化
    InitBoard(board1, ROW, COL);  //初始化
    InitBoard(board2, ROW, COL);  //初始化
    DispalyBoard(board,ROW,COL); //打印
    while(1)
    {
        //电脑下棋
        ComputerMove(board,board1,board2,ROW,COL);
        DispalyBoard(board,ROW,COL);
        //判断电脑是否赢了
        ret = IsWin(board, ROW, COL);
        if(ret!='C')  
        {
            break; //不是继续，跳出循环
        }

        //玩家下棋
        PlayerMove(board,board2,ROW,COL);
        DispalyBoard(board,ROW,COL);
        //判断用户是否赢了
        ret = IsWin(board, ROW, COL);  //四种情况1、玩家赢2、电脑赢3、平局4、继续
        if(ret!='C')
        {
            break; //不是继续，跳出循环
        }
    }//endwhile

    if('X'==ret)
    {
        printf("玩家赢！\n");
    }
    else if('O'==ret)
    {
        printf("电脑赢！\n");
    }
    else //返回'Q'
    {
        printf("平局！");
    }
}


void menu()
{
    printf("***********三子棋***********\n");
    printf("***** 1、开始  0、退出 *****\n");
    printf("****************************\n");
}

int main()
{
    int input = 0;
    srand((unsigned char)time(NULL));
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                break;
        }
    } 
    while (input);
    return 0;
}