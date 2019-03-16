#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
#define maxn 1000
#define INF 0xffff
    int n,m;
int parent[maxn];

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

priority_queue<node> q;
bool visited[maxn];
node d[maxn];

void dij1(int s){
    for(int i=1;i<=n;i++)
    {
        d[i].id=i;
        d[i].distanc=INF;
        parent[i]=-1;
        visited[i]=false;
    }
    d[s].distanc =0;
    q.push(d[s]);
    while(!q.empty())
    {
        node cd =q.top();
        q.pop();
        int u=cd.id;
        if(visited[u])
        continue;
        visited[u]=true;
        arcnode *p =ver1[u].firarc;
        for(p=ver1[u].firarc;p!=NULL;p=p->next)
        {
            int v=p->vertex;
            if(!visited[v]&&d[v].distanc>d[u].distanc+p->weight)
            {
                d[v].distanc=d[u].distanc+p->weight;
                parent[v]=u;
                q.push(d[v]);
            }
        }
    }
}
void dij2(int s){
    for(int i=1;i<=n;i++)
    {
        d[i].id=i;
        d[i].distanc=INF;
        parent[i]=-1;
        visited[i]=false;
    }
    d[s].distanc =0;
    q.push(d[s]);
    while(!q.empty())
    {
        node cd =q.top();
        q.pop();
        int u=cd.id;
        if(visited[u])
        continue;
        visited[u]=true;
        arcnode *p =ver2[u].firarc;
        for(p=ver2[u].firarc;p!=NULL;p=p->next)
        {
            int v=p->vertex;
            if(!visited[v]&&d[v].distanc>d[u].distanc+p->weight)
            {
                d[v].distanc=d[u].distanc+p->weight;
                parent[v]=u;
                q.push(d[v]);
            }
        }
    }
}
	bool resi[maxn];
bool test(int i){
    int j=0;
    for(j=1;j<=n;j++)
    {
        if(d[j].distanc!=INF)
        	resi[j]=1;
    }
    return 1;
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
    int cnt=0;
     for(i=1;i<=n;i++)
    {
    	int flag1,flag2;
        dij1(i);
        test(i);
        
        dij2(i);
        test(i);
		int j;
        for(j = 1; j <= n; j++)
    	{
    	//cout <<visited[j];
		if (resi[j]!=1)	
		break;
		}
		//cout<<endl;
		memset(resi,0,sizeof(resi));
        	if(j==n+1)
		cnt++;
    }

    
    
    printf("%d",cnt);
    return 0;
}

