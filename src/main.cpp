//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

#define SZ(v) ((int)(v).size())

vector <int> tr[100000];
vector <int> rec;
char s[100];
bool visit[100000];

using namespace std;

void dfs(int k, int t)
{
	if(SZ(tr[k]) == 0)	return;
	for(int i = 0; i < SZ(tr[k]); i ++){
		int v = tr[k][i];
		if(!visit[v]){
			if(SZ(tr[k]) == 1)
			{
				sprintf(s, "%d", rec[v]);
				printf("───%s", s);
				dfs(v, t + strlen(s) + 3);
				continue;
			}
			if(!i){
				sprintf(s, "%d", rec[v]);
				printf("─┬─%s", s);
				dfs(v, t + strlen(s) + 3);
			}
			else if (i != SZ(tr[k]) - 1){
				printf("\n");
				for(int j = 0; j < t; j ++)
					printf(" ");
				sprintf(s, "%d", rec[v]);
				printf(" ├─%s", s);
				dfs(v, t + strlen(s) + 3);
			}
			else{
				printf("\n");
				for(int j = 0; j < t; j ++)
					printf(" ");
				sprintf(s, "%d", rec[v]);
				printf(" └─%s", s);
				dfs(v, t + strlen(s) + 3);
			}
		}
	}
}

int main()
{
	int fa, ch;
	cout << "please input the times of fork():\n";
	system("g++ -Wall -o makelist.out makelist.cpp");
	system("./makelist.out");
	freopen("list.txt", "r", stdin);
	rec.clear();
	memset(visit, false, sizeof(visit));
	for(int i = 0; i < 100000; i ++)
		tr[i].clear();
	while(~scanf("%d %d", &fa, &ch))
	{
		int fanum, chnum;
		bool flag = true;
		for(int i = 0; i < SZ(rec); i ++)
			if(rec[i] == fa)
			{
				fanum = i;
				flag = false;
				break;
			}
		if(flag)
		{
			rec.push_back(fa);
			fanum = SZ(rec) - 1;
		}
		if(fa == ch){
			continue;
		}
		flag = true;
		for(int i = 0; i < SZ(rec); i ++)
			if(rec[i] == ch)
			{
				chnum = i;
				flag = false;
				break;
			}
		if(flag)
		{
			rec.push_back(ch);
			chnum = SZ(rec) - 1;
		}
		flag = true;
		for(int i = 0; i < SZ(tr[fanum]); i ++)
			if(tr[fanum][i] == chnum)
			{
				flag = false;
				break;
			}
		if(flag)
			tr[fanum].push_back(chnum);
	}
	visit[0] = true;
	sprintf(s, "%d", rec[0]);
	printf("%s", s);
	dfs(0, strlen(s));
	printf("\n");
	return 0;
}
