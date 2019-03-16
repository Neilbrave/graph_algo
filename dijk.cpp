//ʹ���ڽӾ����dijk 
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define maxn 110        //��󶥵����
#define INF 0xffffff    //Ȩֵ����
int w[maxn][maxn];      //�ڽӾ��󣬴洢Ȩֵ����ʾ��i��j �ı�Ȩֵ 
int n;                  //�������
int parent[maxn];           //ÿ������ĸ��׽ڵ㣬�������ڻ�ԭ���·����

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
        //�ɳڲ���
        for(int v = 0; v < n; v++) //�������������ڵĶ��㣬�����ɳڲ��������¹�����룬ѹ����С�
        {
            if(v != u && !visited[v] && d[v].distanc > d[u].distanc+w[u][v])
            {
                d[v].distanc = d[u].distanc+w[u][v];
                parent[v] = u;//��¼���·���� 
                q.push(d[v]);
            }
        }
    }
}

int main()
{
    int m, a, b, c, st, ed;
    printf("�����붥�����ͱ�����\n");
    scanf("%d%d", &n, &m);
    printf("��������Լ�Ȩֵ��a, b, c)\n");
    
    for(int i = 0; i < n; i++)     //�ڽӾ���洢ǰ��Ҫ��ʼ��
        for(int j = i; j < n; j++)
            w[i][j] = w[j][i] = INF;
            
    while(m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(w[a][b] > c)//������INF 
            w[a][b]= w[b][a] = c;
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
