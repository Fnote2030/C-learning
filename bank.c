#include <stdio.h>
// 共3个进程
#define N 3
// M种资源
#define M 2

// 分配数组：进程已经获得的资源
int allocation[][M] = {{5, 4},
					   {2, 3},
					   {2, 2}};

// 需求数组：进程还需要的资源
int need[][M] = {{5, 3}, 
				 {2, 1}, 
				 {7, 3}};

// 系统当前剩余的可用资源
int available[M] = {3, 4};


//某个进程需要的资源小于或者等于可用的资源
int need_lessequal_avail(const int need[], const int cur_avail[])
{
	int i=0;
	for (i = 0; i<M; i++)
	{
		//printf("%d  --  %d\n",need[i],cur_avail[i]);
		if(need[i] <= cur_avail[i])
			;
		else
			return 0;
	}
	return 1;
}
void release_source(int cur_avail[], const int allocation[])
{
	int i=0;
	for(i=0; i<M; i++)
	{
		(cur_avail[i]) += allocation[i];
	}
}


// 查看当前系统是否安全
// 如果安全返回1，否则返回0
int is_safe() {
	int cur_avail[M] = {};
	int done[N] = {};
	int n = 0;
	for (n = 0; n < M; n++)
	{
		cur_avail[n] = available[n];
	}
	int i, j;
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			if ( !done[j] && need_lessequal_avail(need[j], cur_avail) ) 
			{
				done[j] = 1;
				//释放资源
				release_source(cur_avail, allocation[j]);
				printf(" -> %d ", j);
				break;
			}
		}
	}
	
	return done[0] && done[1] && done[2];
}


// 进程i请求r个资源
// 如果分配成功返回1，否则返回0
int request(int i, int r,int num) {
	// 先保存原数据
	int saved_alloc = allocation[i][num];
	int saved_need = need[i][num];
	int saved_avail = available[num];
	if (r > need[i][num] || r > available[num])
		return 0;
	
	// 进行分配
	allocation[i][num] += r;
	need[i][num] -= r;
	available[num] -= r;
	// 如果安全，则返回成功
	if (is_safe())
		return 1;

	// 不能分配，恢复为以前的数据
	allocation[i][num] = saved_alloc;
	need[i][num] = saved_need;
	available[num] = saved_avail;
	return 0;
}

int main() {
	int ok = is_safe();
	if (ok)
		printf(" safe.\n");
	else
		printf(" not safe.\n");

	// 进程2请求3个2号资源 
	ok = request(2, 3, 2);
	if (ok)
		printf(" done.\n");
	else
		printf(" not done.\n");
}
