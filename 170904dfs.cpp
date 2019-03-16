#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
#define maxn 1000
#define INF 0xffff
int n,m;
bool visited[maxn];     //标记顶点是否被考察，初始值为false
int parent[maxn];       //parent[]记录某结点的父亲结点，生成树，初始化为-1
int d[maxn], time, f[maxn]; //时间time初始化为0，d[]记录第一次被发现时，f[]记录结束检查时


struct arcnode
{
	int vertex;
	int weight;
	arcnode *next;
	arcnode(){
	}
	arcnode(int v,int w):vertex(v),weight(w),next(NULL)
	{}
};
struct vernode
{
	int vex;
	 arcnode *firarc;
}ver1[maxn],ver2[maxn];

void init()
{
    for (int i=1;i<=n;i++)
    {
        ver1[i].vex=i;
        ver1[i].firarc=NULL;
        ver2[i].vex=i;
        ver2[i].firarc=NULL;
    }
}

void insert1(int a,int b,int w)
{
    arcnode *q=new arcnode(b,w);
    if (ver1[a].firarc==NULL)
    {
        ver1[a].firarc =q;
    }
    else
    {
        arcnode *p=ver1[a].firarc;
        q->next=p;
        ver1[a].firarc=q;
    }
}
void insert2(int a,int b,int w)
{
    arcnode *q=new arcnode(b,w);
    if (ver2[a].firarc==NULL)
    {
        ver2[a].firarc =q;
    }
    else
    {
        arcnode *p=ver2[a].firarc;
        q->next=p;
        ver2[a].firarc=q;
    }
}
struct node
{
    int id,distanc;
    friend bool operator < (node a,node b)
    {
        return a.distanc>b.distanc;
    }
};


void dfs1(int s)         //深度优先搜索（邻接表实现），记录时间戳，寻找最短路径
{
    //cout << s << " ";
    visited[s] = true;
    time++;
    d[s] = time;
    arcnode * p = ver1[s].firarc;
    while(p != NULL)
    {
        if(!visited[p->vertex])
        {
            parent[p->vertex] = s;
            dfs1(p->vertex);
        }
        p = p->next;
    }
    time++;
    f[s] = time;
}
void dfs2(int s)         //深度优先搜索（邻接表实现），记录时间戳，寻找最短路径
{
    //cout << s << " ";
    visited[s] = true;
    time++;
    d[s] = time;
    arcnode * p = ver2[s].firarc;
    while(p != NULL)
    {
        if(!visited[p->vertex])
        {
            parent[p->vertex] = s;
            dfs2(p->vertex);
        }
        p = p->next;
    }
    time++;
    f[s] = time;
}

void initdfs(){
	for(int i = 1; i <= n; i++)     //初始化
    {
        parent[i] = -1;
        visited[i] = false;
    }
}

void dfs_travel()       //遍历所有顶点，找出所有深度优先生成树，组成森林
{
	bool resi[maxn];
	int cnt =0;
    for(int i = 1; i <= n; i++)     //初始化
    {
        parent[i] = -1;
        visited[i] = false;
    }
    time = 0;
    for(int i = 1; i <= n; i++)     //遍历
    {
    	dfs1(i);
    	int j;
    	for(j = 1; j <= n; j++)
    	{
    	//cout <<visited[j];
		if (visited[j]==1)	
		resi[j]=1;
		}
		initdfs();
		//cout <<endl;
		dfs2(i);
    	for(j = 1; j <= n; j++)
    	{
    	//cout <<visited[j];
		if (visited[j]==1)	
		resi[j]=1;
		}
		initdfs();
		
		for(j = 1; j <= n; j++)
    	{
    	//cout <<visited[j];
		if (resi[j]!=1)	
		break;
		}
		//cout<<endl;
		memset(resi,0,sizeof(resi));
		//cout <<endl;
		if(j==n+1)
		cnt++;
	}
    cout <<cnt<<endl;
}
int main()
{

    int i;
    int p1,p2;
    int res[1000];
    memset(res,0,sizeof(res));
    scanf("%d %d",&n,&m);
    init();
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&p1,&p2);
        insert1(p1,p2,1);
        insert2(p2,p1,1);
    }
    dfs_travel() ;
    return 0;
}

