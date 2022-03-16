#include <stdio.h>
// ��3������
#define N 3
// M����Դ
#define M 2

// �������飺�����Ѿ���õ���Դ
int allocation[][M] = {{5, 4},
					   {2, 3},
					   {2, 2}};

// �������飺���̻���Ҫ����Դ
int need[][M] = {{5, 3}, 
				 {2, 1}, 
				 {7, 3}};

// ϵͳ��ǰʣ��Ŀ�����Դ
int available[M] = {3, 4};


//ĳ��������Ҫ����ԴС�ڻ��ߵ��ڿ��õ���Դ
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


// �鿴��ǰϵͳ�Ƿ�ȫ
// �����ȫ����1�����򷵻�0
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
				//�ͷ���Դ
				release_source(cur_avail, allocation[j]);
				printf(" -> %d ", j);
				break;
			}
		}
	}
	
	return done[0] && done[1] && done[2];
}


// ����i����r����Դ
// �������ɹ�����1�����򷵻�0
int request(int i, int r,int num) {
	// �ȱ���ԭ����
	int saved_alloc = allocation[i][num];
	int saved_need = need[i][num];
	int saved_avail = available[num];
	if (r > need[i][num] || r > available[num])
		return 0;
	
	// ���з���
	allocation[i][num] += r;
	need[i][num] -= r;
	available[num] -= r;
	// �����ȫ���򷵻سɹ�
	if (is_safe())
		return 1;

	// ���ܷ��䣬�ָ�Ϊ��ǰ������
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

	// ����2����3��2����Դ 
	ok = request(2, 3, 2);
	if (ok)
		printf(" done.\n");
	else
		printf(" not done.\n");
}
