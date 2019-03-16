//ʹ���ڽ������spfa 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;
const int maxn =  1000;		//	��ĸ��� 
const int INF = 0xffffff;  //�����

struct arcnode  //�߽��
{
    int vertex;     //���ͷ������ڵĶ�����
    int weight = 0;     //����������ıߵ�Ȩֵ
    arcnode * next; //ָ����һ���ڽӵ�
    arcnode() {}
    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
    arcnode(int v):vertex(v),next(NULL) {}
};

struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
{
    int vex;    //��ǰ������
    arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
}Ver[maxn];

bool vis[maxn];                 //�õ��Ƿ��ڶ�����
int dis[maxn];                  //��ʼ�㵽ÿ�����̾���
int n,m;
int parent[maxn];			  //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����

void Init()  //����ͼ���ڽӱ���Ҫ�ȳ�ʼ��������������
{
    for(int i = 1; i <= n; i++)
    {
        Ver[i].vex = i;
        Ver[i].firarc = NULL;
    }
}

void Insert(int a, int b, int w)   //ͷ�巨��Ч�ʸ��ߣ�������ȥ�ر�
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
	
    for (int i = 0; i < n; i++)     //��ʼ��
	{
		dis[i] = INF;          //���������INF
		vis[i] = false;
		parent[i] =-1; 
	}
    dis[st] = 0;
    vis[st] = true;
    queue<int>q;
    q.push(st);
/*****************���涼�Ǻ�Dijkstraһ���ģ�������������ͷ******************/
/**Dijkstra��ÿ����Ȩֵ��С�ıߣ�Ȼ���������������ĵ����dis����
����ÿn�β���ֻ���ҳ�һ������
   SPFA������ñ߿����ɳ������ӵĵ�δ��ʹ�ã��ͰѸñ����ӵ��Ǹ��������еȴ�����
   ����ÿ����һ����Ϳ��԰Ѹõ����б������ӵĵ㣨���Ա��ɳڵģ�����¼Ȼ�����
*/
	int num=0;
    while(!q.empty()) 
	{
        int cd = q.front();                //ȡ�����׵ĵ�cd��ʾ��ǰ�� 
        q.pop();
        vis[cd] = 0;
 		arcnode *i; 
        for(i=Ver[cd].firarc ;i!=NULL;i=i->next) //Ver[cd]��cd�������neighbor�ļ��� 
		 {
            int p = i->vertex;        //ȡ�����׵ĵ�
            int w = i->weight;
            if(dis[cd]+w < dis[p]) 
			{       //��������ɳھ͸���dis���飬�˴���Dijkstraһ��
                dis[p] = dis[cd]+w;        //�ɳڵ�ͬʱ����õ�δ�����ʾͰѸõ��ӽ�����
                parent[p] = cd;				//���ڻ�ԭ���·���� 
				if(!vis[p]) {               //��ͬ�ĵط������p��δ��ʹ�ã����������У�Ҳ����p����Ա��ɳڣ�
                    num++;//��Ӵ�������n+1��˵���и��� 
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
	printf("�����붥�����ͱ�����\n");
	scanf("%d%d", &n, &m);
	printf("��������Լ�Ȩֵ��a, b, c)\n");
    Init(); 
	for(int i=0;i<m;i++){
        scanf("%d%d%d", &p1, &p2, &w);
        //��������ͼ
        Insert(p1, p2, w);        //�������
        Insert(p2, p1, w);        //���������ͼ����Ҫ�������
      
    }
    int st,ed;
    printf("�����������յ㣺\n");
    scanf("%d%d", &st, &ed);
    if (spfa(st)){
    	cout << dis[ed] <<endl;
    	printpath(st,ed);
	}
    
	else 
		printf("�����ڴӶ���%d������%d�����·����\n", st, ed);  
    return 0;
}

