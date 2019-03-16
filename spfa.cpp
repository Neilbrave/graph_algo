//使用邻接链表的spfa 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;
const int maxn =  1000;		//	点的个数 
const int INF = 0xffffff;  //无穷大

struct arcnode  //边结点
{
    int vertex;     //与表头结点相邻的顶点编号
    int weight = 0;     //连接两顶点的边的权值
    arcnode * next; //指向下一相邻接点
    arcnode() {}
    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
    arcnode(int v):vertex(v),next(NULL) {}
};

struct vernode      //顶点结点，为每一条邻接表的表头结点
{
    int vex;    //当前定点编号
    arcnode * firarc;   //与该顶点相连的第一个顶点组成的边
}Ver[maxn];

bool vis[maxn];                 //该点是否在队列中
int dis[maxn];                  //初始点到每点的最短距离
int n,m;
int parent[maxn];			  //每个顶点的父亲节点，可以用于还原最短路径树

void Init()  //建立图的邻接表需要先初始化，建立顶点结点
{
    for(int i = 1; i <= n; i++)
    {
        Ver[i].vex = i;
        Ver[i].firarc = NULL;
    }
}

void Insert(int a, int b, int w)   //头插法，效率更高，但不能去重边
{
    arcnode * q = new arcnode(b, w);
    if(Ver[a].firarc == NULL)
        Ver[a].firarc = q;
    else
    {
        arcnode * p = Ver[a].firarc;
        q->next = p;
        Ver[a].firarc = q;
    }
}

void printpath(int st,int id){
    	int i=id;
    	while(i!=st){
    		printf("%d->",i);
    		i=parent[i];
		}
    	printf("%d\n",st);
}

bool spfa(int st) {
	
    for (int i = 0; i < n; i++)     //初始化
	{
		dis[i] = INF;          //估算距离置INF
		vis[i] = false;
		parent[i] =-1; 
	}
    dis[st] = 0;
    vis[st] = true;
    queue<int>q;
    q.push(st);
/*****************上面都是和Dijkstra一样的，接下来才是重头******************/
/**Dijkstra：每次找权值最小的边，然后根据这个边所连的点更新dis数组
所以每n次操作只能找出一个点来
   SPFA：如果该边可以松弛且连接的点未被使用，就把该边连接的那个点存进队列等待更新
   所以每经过一个点就可以把该点所有边所连接的点（可以被松弛的）都记录然后更新
*/
	int num=0;
    while(!q.empty()) 
	{
        int cd = q.front();                //取出队首的点cd表示当前点 
        q.pop();
        vis[cd] = 0;
 		arcnode *i; 
        for(i=Ver[cd].firarc ;i!=NULL;i=i->next) //Ver[cd]是cd点的所有neighbor的集合 
		 {
            int p = i->vertex;        //取出队首的点
            int w = i->weight;
            if(dis[cd]+w < dis[p]) 
			{       //如果可以松弛就更新dis数组，此处和Dijkstra一样
                dis[p] = dis[cd]+w;        //松弛的同时如果该点未被访问就把该点扔进队列
                parent[p] = cd;				//用于还原最短路径树 
				if(!vis[p]) {               //不同的地方，如果p点未被使用，则将其放入队列（也就是p点可以被松弛）
                    num++;//入队次数大于n+1则说明有负环 
                    if(num>n+1)
                        return false;
                    q.push(p);
                    vis[p] = 1;
                }
            }
        }
    }
    return true;
}
 
 
int main() {
    int p1,p2,w;
	printf("请输入顶点数和边数：\n");
	scanf("%d%d", &n, &m);
	printf("请输入边以及权值（a, b, c)\n");
    Init(); 
	for(int i=0;i<m;i++){
        scanf("%d%d%d", &p1, &p2, &w);
        //构建无向图
        Insert(p1, p2, w);        //插入操作
        Insert(p2, p1, w);        //如果是无向图还需要反向插入
      
    }
    int st,ed;
    printf("请输入起点和终点：\n");
    scanf("%d%d", &st, &ed);
    if (spfa(st)){
    	cout << dis[ed] <<endl;
    	printpath(st,ed);
	}
    
	else 
		printf("不存在从顶点%d到顶点%d的最短路径。\n", st, ed);  
    return 0;
}

