#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include<fcntl.h> 
#include<stdlib.h> 
#include<malloc.h>
#include <sys/wait.h>

// 保存当前的命令行输入
char line[512];
 
// 根据命令行输入等到的命令参数
char *args[128]; //指向line
 
// 命令参数个数
int narg = 0;
int redir = 0;   //判断是否有重定向符号
int gdflag = 0;  //判断是否有管道符号
char *file;  //记录重定向目标文件
char *cmd[2][64] = {}; //管道符号两侧的命令

// 将命令参数拷贝到当前命令中
void copy_args(char* cmd_args[]) 
{
    int i=0;
	int j=0;
	int num=0;
    for (i=0; i < narg; i++,j++) //NULL可以不用拷贝 
	{
        cmd_args[i] = args[i];
		cmd[num][j] = args[i];
		//1、判断命令中是否有输出重定向
		if( (strcmp( cmd_args[i], ">" ) == 0 ) || (strcmp( cmd_args[i], ">>") == 0) ) 
        {
            redir = 1;
			file = args[i+1]; //>后面的命令参数为文件名
            cmd_args[i] = NULL;   //除去命令 > \ >>
        }
		//2、判断命令中是否有管道符号
		else if( strcmp( cmd_args[i],"|" ) == 0 ) 
        {
            gdflag++;
			cmd[num][j] = NULL;   //除去命令 |
			num +=1;
			j = -1;
        }
    }
}
 
// 管道操作函数
void gdprocess()
{
	int p1, p2;
    int fd[2];
	gdflag = 0; //管道符号处理完
	pipe(fd);
	p1 = fork(); // 创建子进程 p1
	
	if (p1 == 0) 
	{
		// p1 对标准输出重定向为管道的写端
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execvp(cmd[0][0],cmd[0]);
		return;
	}
	p2 = fork(); // 创建子进程 p2
	if (p2 == 0) 
	{
		// p2 对标准输入重定向为管道的读端
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execvp(cmd[1][0], cmd[1]);
		return;
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	exit(0);
} 

// 执行 ls 命令
void exec_ls() 
{
    int pid = fork();
    int fd;
	char* cmd_args[64] = {};
    if (pid > 0) 
	{
        waitpid(pid, NULL, 0);
        return;
    }  
    copy_args(cmd_args);
	// printf("%s\n",cmd_args[0]);
	// printf("%s\n",file);
	
    if(redir == 1)//如果命令有重定向
	{	
        fd = open( file,O_RDWR | O_CREAT | O_TRUNC, 0644 );
        dup2( fd,1 );    //指定新文件描述符为1,1为标准输出，0为标准输入
		close(fd);
		redir = 0;
    }
	
	if(gdflag > 0)//如果命令有管道
	{
		gdprocess();
	}
	else
		execv("/bin/ls", cmd_args);
}
 
// 执行 pwd 命令
void exec_pwd() 
{
    char buffer[256];
    getwd(buffer);     //当前路径
    printf("%s\n", buffer);
}
 
// 执行 cd 命令
void exec_cd() 
{
    if (narg != 2) //格式不对
		return;
    chdir(args[1]); 
    exec_pwd();
}

//执行environ 命令
void exec_env()
{
	execlp("env","",NULL);	
}

//echo 在屏幕上显示参数
void exec_echo()
{
	int pid = fork();
	int fd;
	char* cmd_args[64] = {};     
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);    
	if(redir == 1)//如果命令有重定向
	{	
        fd = open( file,O_RDWR | O_CREAT | O_TRUNC, 0644 );
        dup2( fd,1 );    //指定新文件描述符为1,1为标准输出，0为标准输入
		close(fd);
		redir = 0;
    }
	if(gdflag > 0)//如果命令有管道
	{
		gdprocess();
	}
	else
		execv("/bin/echo", cmd_args);
}

//执行help
void exec_help()
{
	int pid = fork();
	if (pid > 0) 
	{
		waitpid(pid, NULL, 0);
		return;
	}  
	system("help");
}

//创建文件
void exec_touch() 
{  
	int pid = fork();
	char* cmd_args[64] = {};     
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);    
	execv("/bin/touch", cmd_args);  
}

//编辑文件
void exec_vim() 
{  
	int pid = fork();
	char* cmd_args[64] = {};     
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);    
	execv("/bin/vim", cmd_args);  
}

//创建文件夹
void exec_mkdir() 
{  
	int pid = fork();   
	char* cmd_args[64] = {};   
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);    
	execv("/bin/mkdir", cmd_args);  
}

//删除文件夹和文件夹
void exec_rm()
{
	int pid = fork();    
	char* cmd_args[64] = {};    
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);    
	execv("/bin/rm", cmd_args); 
}

//显示文档内容
void exec_cat()
{
	int pid = fork();   
	char* cmd_args[64] = {};  
	int fd;
	if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
	}   
	copy_args(cmd_args);  
	
    if(redir == 1)//如果命令有重定向
	{	
        fd = open( file,O_RDWR | O_CREAT | O_TRUNC, 0644 );
		if (fd == -1) 
			return;
        dup2( fd,1 );    //指定新文件描述符为1,1为标准输出，0为标准输入
		close(fd);
		redir = 0;
    }
	if(gdflag > 0)//如果命令有管道
	{
		gdprocess();
	}
	else
		execv("/bin/cat", cmd_args); 
}

//复制
void exec_copy()
{
    int pid = fork();  
	char* cmd_args[64] = {};    
    if (pid > 0) 
	{       
		waitpid(pid, NULL, 0);       
		return;
    }   
	copy_args(cmd_args);    
	execv("/bin/cp", cmd_args); 
}

//移动
void exec_move()
{
    int pid = fork();    
	char* cmd_args[64] = {};   
    if (pid > 0) {       
		waitpid(pid, NULL, 0);       
		return;
    }   
	copy_args(cmd_args);    
	execv("/bin/mv", cmd_args); 
}

//查找
void exec_grep()
{
    int pid = fork();  
	int fd;	
	char* cmd_args[64] = {};   
    if (pid > 0) {       
		waitpid(pid, NULL, 0);       
		return;
    }   
	copy_args(cmd_args); 
    if(redir == 1)//如果命令有重定向
	{	
        fd = open( file,O_RDWR | O_CREAT | O_TRUNC, 0644 );
        dup2( fd,1 );    //指定新文件描述符为1,1为标准输出，0为标准输入
		close(fd);
		redir = 0;
    }
	if(gdflag > 0)//如果命令有管道
	{
		gdprocess();
	}
	else
		execv("/bin/grep", cmd_args);	
}

//显示提示内容
void show() 
{
	char *username;         //用户名
	char hostname[256] = {};//主机名
	char curpath[256] = {}; //当前路径
	char prompt = '$';
	//获取用户名
	username = getpwuid(getuid())->pw_name;
	//获取主机名
	gethostname(hostname, sizeof(hostname));
	//获取当前路径
	getcwd(curpath, 256);
	
	// \033[32m 绿色字体 \033[32;1m 高亮
	// \033[31m 红色字体
	// \033[34m 蓝色字体
	// \033[0m 关闭所有属性
	printf("\n");
	printf("\033[32m%s@%s:~\033[34;1m%s\033[0m\n%c ",username, hostname, curpath, prompt);
}

//主函数
int main() 
{    
    show();
    while (gets(line)) 
	{
		narg = 0; //命令参数个数  
		args[0] = strtok(line," ");//字符串分隔函数，将每个命令分隔
		//只按下回车
		if(args[0] == NULL)
		{
			show();
			continue;
		}
		while(args[narg] != NULL)//最后一个数组指针为NULL
		{ 
			narg++; 
			args[narg] = strtok(NULL," "); //传参数NULL，函数保留的指针为起始位
		} 
		
        if (strcmp(args[0], "quit") == 0) 
		{
            break;
        } 
		else if (strcmp(args[0], "ls") == 0) 
		{
            exec_ls();
        } 
		else if (strcmp(args[0], "pwd") == 0) 
		{
            exec_pwd();
        } 
		else if (strcmp(args[0], "cd") == 0) 
		{
            exec_cd();
        } 
		else if(strcmp(args[0], "env")==0)
		{
			exec_env();
		}
		else if(strcmp(args[0], "echo")==0)
		{
			exec_echo();
		}
		else if(strcmp(args[0], "help")==0)
		{
			exec_help();
		}
		else if(strcmp(args[0], "mkdir")==0)
		{
		    exec_mkdir();	
		}
		else if(strcmp(args[0], "touch")==0)
		{
			exec_touch();
		}
		else if(strcmp(args[0], "vim")==0)
		{
		    exec_vim();
		}
		else if(strcmp(args[0], "cp")==0)
		{
		    exec_copy();
		}
		else if(strcmp(args[0], "mv")==0)
		{
		    exec_move();
		}
		else if(strcmp(args[0], "rm")==0)
		{
		    exec_rm();
		}
		else if(strcmp(args[0], "cat")==0)
		{
		    exec_cat();
		}
		else if(strcmp(args[0], "grep")==0)
		{
			exec_grep();
		}
		else 
		{
			printf("command not found\n");
		}
		show();
	}//endwhile
    return 0;
}