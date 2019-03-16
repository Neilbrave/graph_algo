//ʹ���ڽӾ����dijk 
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define maxn 110        //��󶥵����
#define INF 0xffffff    //Ȩֵ���� 
int n;                  //�������
int parent[maxn];           //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����

struct arcnode  //�߽��
{
    int vertex;     //���ͷ������ڵĶ�����
    int weight = 0;     //����������ıߵ�Ȩֵ
    arcnode * next; //ָ����һ���ڽӵ�
    arcnode() {}
    arcnode(int v,int w):vertex(v),weight(w),next(NULL) {}
};

struct vernode      //�����㣬Ϊÿһ���ڽӱ�ı�ͷ���
{
    int vex;    //��ǰ������
    arcnode * firarc;   //��ö��������ĵ�һ��������ɵı�
}Ver[maxn];

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

struct node             //����ڵ㣬����id�͵�Դ����Ĺ�����룬���ȶ�����Ҫ������
{
    int id, distanc;     //Դ����id�͹������
    friend bool operator<(node a, node b)   //��Ҫʵ����С�ѣ����������У������Ҫ������������ض������ȼ�����СΪ��
    {
        return a.distanc > b.distanc;
    }
};

void printpath(int st,int id){
    	int i=id;
    	while(i!=st){
    		printf("%d->",i);
    		i=parent[i];
		}	
    	printf("%d\n",st);
}

priority_queue<node> q;     //���ȶ��У���С�ѣ�ʵ��Dijkstra����Ҫ���ݽṹ����stlʵ��
bool visited[maxn];         //�����ж϶����Ƿ��Ѿ������·�����У�����˵�Ƿ����ҵ����·��
node d[maxn];               //Դ�㵽ÿ�����������룬�����ΪԴ�㵽���ж�������·��

void Dijkstra(int s)        //Dijkstra�㷨������Դ����
{
    for(int i = 0; i < n; i++)     //��ʼ��
    {
        d[i].id = i;
        d[i].distanc = INF;          //���������INF
        parent[i] = -1;             //ÿ�����㶼�޸��׽ڵ�
        visited[i] = false;         
    }
    d[s].distanc = 0;                //Դ�㵽Դ�����·ȨֵΪ0
    q.push(d[s]);                   //ѹ������У����ȼ��Ӹߵ��� 
    while(!q.empty())               //�㷨�ĺ��ģ����п�˵������˲���
    {
        node cd = q.top();          //ȡ��С������붥�㣨���ȼ���ߵĵ㣩 
        q.pop();					//�Ƚ��ȳ���ɾ�����ȼ���ߵĵ� 
        int u = cd.id;
        if(visited[u])
            continue;
        visited[u] = true;
        arcnode * p = Ver[u].firarc;
        //�ɳڲ���
        for(p = Ver[u].firarc; p!=NULL; p=p->next) //�������������ڵĶ��㣬�����ɳڲ��������¹�����룬ѹ����С�
        {
        	int v=p->vertex;
            if(!visited[v] && d[v].distanc > d[u].distanc+p->weight)
            {
                d[v].distanc = d[u].distanc+p->weight;
                parent[v] = u;//��¼���·���� 
                q.push(d[v]);
            }
        }
    }
}

int main()
{
    int m, st, ed; 
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
    
    printf("�����������յ㣺\n");
   // while(ed!=998){
    	scanf("%d%d", &st, &ed);
    	Dijkstra(st);//һ�ε��þͿ��Եõ����е㵽st�ľ��� 
    
    if(d[ed].distanc != INF){
    	printf("���·��ȨֵΪ��%d\n", d[ed].distanc);
    	printpath(st,ed);
	}
        
    else
        printf("�����ڴӶ���%d������%d�����·����\n", st, ed);
	//}
   
    return 0;
}
