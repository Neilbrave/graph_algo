////ʹ���ڽ������spfa 
////����S[i]=A0+A1+A2+Ai��Ҫʹ��a���ֵ�����С����ÿ��S[i]ҲҪ����С ������ÿ��s����Сֵ����ת��Ϊ��=�����· 
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
//const int maxn =  1000;		//	��ĸ��� 
//const int INF = 0xffffff;  //1111111111111111***************���ø� 
//
//struct arcnode  //�߽��
//{
//    int vertex;     //���ͷ������ڵĶ�����
//    int weight;     //����������ıߵ�Ȩֵ
//    arcnode * next; //ָ����һ���ڽӵ�
//    arcnode() {}
//    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
//    arcnode(int v):vertex(v),next(NULL) {}
//};
//
//struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
//{
//    int vex;    //��ǰ������
//    arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
//}Ver[maxn];
//
//bool vis[maxn];                 //�õ��Ƿ��ڶ�����
//int dis[maxn];                  //��ʼ�㵽ÿ�����̾���
//int n,m;
//int parent[maxn];			  //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����
//
//void Init()  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
//{
//    for(int i = 1; i <= n; i++)
//    {
//        Ver[i].vex = i;
//        Ver[i].firarc = NULL;
//    }
//}
//
//void Insert(int a, int b, int w)  //β�巨��������aΪ��㣬bΪ�յ㣬ȨΪw�ıߣ�Ч�ʲ���ͷ�壬���ǿ���ȥ�ر�
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
//    for (int i = 0; i < n; i++)     //��ʼ��
//	{
//		dis[i] = INF;          //���������INF
//		vis[i] = false;
//		parent[i] =-1; 
//	}
//    dis[st] = 0;
//    vis[st] = true;
//    queue<int>q;
//    q.push(st);
///*****************���涼�Ǻ�Dijkstraһ���ģ�������������ͷ******************/
///**Dijkstra��ÿ����Ȩֵ��С�ıߣ�Ȼ���������������ĵ����dis����
//����ÿn�β���ֻ���ҳ�һ������
//   SPFA������ñ߿����ɳ������ӵĵ�δ��ʹ�ã��ͰѸñ����ӵ��Ǹ��������еȴ�����
//   ����ÿ����һ����Ϳ��԰Ѹõ����б������ӵĵ㣨���Ա��ɳڵģ�����¼Ȼ�����
//*/
//	int num=0;
//    while(!q.empty()) 
//	{
//        int cd = q.front();                //ȡ�����׵ĵ�cd��ʾ��ǰ�� 
//        q.pop();
//        vis[cd] = 0;
// 		arcnode *i; 
//        for(i=Ver[cd].firarc ;i!=NULL;i=i->next) //Ver[cd]��cd�������neighbor�ļ��� 
//		 {
//            int p = i->vertex;        //ȡ�����׵ĵ�
//            int w = i->weight;
//            if(dis[cd]+w < dis[p]) 
//			{       //��������ɳھ͸���dis���飬�˴���Dijkstraһ��
//                dis[p] = dis[cd]+w;        //�ɳڵ�ͬʱ����õ�δ�����ʾͰѸõ��ӽ�����
//                parent[p] = cd;				//���ڻ�ԭ���·���� 
//				if(!vis[p]) {               //��ͬ�ĵط������p��δ��ʹ�ã����������У�Ҳ����p����Ա��ɳڣ�
//				//222222222222222222
//				//****���·��Ҫ��û����������������Ŀ����ȷ���� 
//                    num++;//��Ӵ�������n+1��˵���и��� 
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
//	//printf("�����붥�����ͱ�����\n");
//	scanf("%d", &n);
//	//n=n+1;//ÿ������һ������S0 
//	//printf("insert edge(a,b,w)\n");
//    Init();     
//    
//	for(int i=1;i<=n;i++){
//        scanf("%d", &w[i]);
//        //��������ͼ
//        //433333333333333333333333333333
//        //***���븺�� ,��������� 
//        //Insert(p1, p2, -w);        //�������
//        //Insert(p2, p1, -w);        //���������ͼ����Ҫ�������
//      
//    }
//    
//    //ÿ���ڵ���ΪS��Ҫ��S(n+1)-S(n)>=1; 
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
//    	//4444444444444444444444������� �ĸ���Ϊ�� 
//    	for(int i=1;i<=n;i++)
//			{
//				cout << -(dis[i]-dis[i-1])<<" ";
//			}
//	}
//    
//	else 
//		printf("�����ڴӶ���%d������%d�����·����\n", st, ed);  
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

