////使用邻接链表的spfa 
////定义S[i]=A0+A1+A2+Ai；要使得a的字典序最小，则每个S[i]也要尽量小 ，即求每个s的最小值，即转化为》=，求最长路 
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <queue>
//#include <vector>
//
//
//using namespace std;
//const int maxn =  1000;		//	点的个数 
//const int INF = 0xffffff;  //1111111111111111***************不用改 
//
//struct arcnode  //边结点
//{
//    int vertex;     //与表头结点相邻的顶点编号
//    int weight;     //连接两顶点的边的权值
//    arcnode * next; //指向下一相邻接点
//    arcnode() {}
//    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
//    arcnode(int v):vertex(v),next(NULL) {}
//};
//
//struct vernode      //顶点结点，为每一条邻接表的表头结点
//{
//    int vex;    //当前定点编号
//    arcnode * firarc;   //与该顶点相连的第一个顶点组成的边
//}Ver[maxn];
//
//bool vis[maxn];                 //该点是否在队列中
//int dis[maxn];                  //初始点到每点的最短距离
//int n,m;
//int parent[maxn];			  //每个顶点的父亲节点，可以用于还原最短路径树
//
//void Init()  //建立图的邻接表需要先初始化，建立顶点结点
//{
//    for(int i = 1; i <= n; i++)
//    {
//        Ver[i].vex = i;
//        Ver[i].firarc = NULL;
//    }
//}
//
//void Insert(int a, int b, int w)  //尾插法，插入以a为起点，b为终点，权为w的边，效率不如头插，但是可以去重边
//{
//    arcnode * q = new arcnode(b, w);
//    if(Ver[a].firarc == NULL)
//        Ver[a].firarc = q;
//    else
//    {
//        arcnode * p = Ver[a].firarc;
//        if(p->vertex == b)
//        {
//            if(p->weight > w)
//                p->weight = w;
//            return ;
//        }
//        while(p->next != NULL)
//        {
//            if(p->next->vertex == b)
//            {
//                if(p->next->weight > w);
//                    p->next->weight = w;
//                return ;
//            }
//            p = p->next;
//        }
//        p->next = q;
//    }
//}
//void printpath(int st,int id){
//    	int i=id;
//    	while(i!=st){
//    		printf("%d->",i);
//    		i=parent[i];
//		}
//    	printf("%d\n",st);
//}
//
//bool spfa(int st) {
//	
//    for (int i = 0; i < n; i++)     //初始化
//	{
//		dis[i] = INF;          //估算距离置INF
//		vis[i] = false;
//		parent[i] =-1; 
//	}
//    dis[st] = 0;
//    vis[st] = true;
//    queue<int>q;
//    q.push(st);
///*****************上面都是和Dijkstra一样的，接下来才是重头******************/
///**Dijkstra：每次找权值最小的边，然后根据这个边所连的点更新dis数组
//所以每n次操作只能找出一个点来
//   SPFA：如果该边可以松弛且连接的点未被使用，就把该边连接的那个点存进队列等待更新
//   所以每经过一个点就可以把该点所有边所连接的点（可以被松弛的）都记录然后更新
//*/
//	int num=0;
//    while(!q.empty()) 
//	{
//        int cd = q.front();                //取出队首的点cd表示当前点 
//        q.pop();
//        vis[cd] = 0;
// 		arcnode *i; 
//        for(i=Ver[cd].firarc ;i!=NULL;i=i->next) //Ver[cd]是cd点的所有neighbor的集合 
//		 {
//            int p = i->vertex;        //取出队首的点
//            int w = i->weight;
//            if(dis[cd]+w < dis[p]) 
//			{       //如果可以松弛就更新dis数组，此处和Dijkstra一样
//                dis[p] = dis[cd]+w;        //松弛的同时如果该点未被访问就把该点扔进队列
//                parent[p] = cd;				//用于还原最短路径树 
//				if(!vis[p]) {               //不同的地方，如果p点未被使用，则将其放入队列（也就是p点可以被松弛）
//				//222222222222222222
//				//****跑最长路就要求没有正环，这是由题目本身确定的 
//                    num++;//入队次数大于n+1则说明有负环 
//                    if(num>n+1)
//                        return false;
//                    q.push(p);
//                    vis[p] = 1;
//                }
//            }
//        }
//    }
//    return true;
//}
// 
// 
//int main() {
//    int p1,p2,w[500];
//	//printf("请输入顶点数和边数：\n");
//	scanf("%d", &n);
//	//n=n+1;//每个数加一。留出S0 
//	//printf("insert edge(a,b,w)\n");
//    Init();     
//    
//	for(int i=1;i<=n;i++){
//        scanf("%d", &w[i]);
//        //构建无向图
//        //433333333333333333333333333333
//        //***插入负边 ,且是有向边 
//        //Insert(p1, p2, -w);        //插入操作
//        //Insert(p2, p1, -w);        //如果是无向图还需要反向插入
//      
//    }
//    
//    //每个节点作为S，要求S(n+1)-S(n)>=1; 
//	for(int i=1;i<=n;i++)
//	{
//		Insert(i-1,i,-1);
//	}
//	
//	
//	Insert(0,2,-2*w[1]);
//	Insert(2,0,2*w[1]+1);
//	Insert(n-2,n,-2*w[n]);
//	Insert(n,n-2,2*w[n]+1);
//	
//	for(int i=2;i<=n;i++)
//	{
//		Insert(i-2,i+1,-3*w[i]);
//		Insert(i+1,i-2,3*w[i]+2);
//	}
//    
//    int st,ed;
//   	st=0;
//   	
//    if (spfa(st))
//	{
//    	//4444444444444444444444输出负边 的负即为正 
//    	for(int i=1;i<=n;i++)
//			{
//				cout << -(dis[i]-dis[i-1])<<" ";
//			}
//	}
//    
//	else 
//		printf("不存在从顶点%d到顶点%d的最短路径。\n", st, ed);  
//    return 0;
//}
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define N 3005
#define inf 0x3f3f3f3f
 
int a[N],s[N];
int tot;
int head[N];
struct node
{
    int w,to,nt;
}g[10000];
 
void add(int u,int v,int w)
{
    g[tot].to=v;
    g[tot].w=w;
    g[tot].nt=head[u];
    head[u]=tot++;
}
 
bool vis[N];
int dis[N];
void spfa(int s,int n)
{
    queue<int>q;
    for(int i=0;i<=n;i++)dis[i]=0;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=g[i].nt)
        {
            int to=g[i].to;
            if(dis[to]<dis[u]+g[i].w)
            {
                dis[to]=dis[u]+g[i].w;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=true;
                }
            }
        }
    }
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]-dis[i-1]<<" ";
    }
    cout<<endl;
}
 
int main()
{
    int n;
    cin>>n;
    s[0]=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    add(0,2,(a[1]*2));
    add(2,0,-(a[1]*2+1));
    add(n-2,n,(a[n]*2));
    add(n,n-2,-(a[n]*2+1));
    for(int i=2;i<=n-1;i++)
    {
        add(i-2,i+1,(a[i]*3));
        add(i+1,i-2,-(a[i]*3+2));
    }
    for(int i=1;i<=n;i++)add(i-1,i,1);
    spfa(0,n);
    return 0;
}

