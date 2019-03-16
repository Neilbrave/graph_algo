#define INF 9999
bool visited[maxn];         //��Ƕ����Ƿ񱻿��죬��ʼ��Ϊfalse
int d[maxn], parent[maxn];  //d[]��¼���·�����ȣ�parent[]��¼ĳ���ĸ��׽�㣬������
void bfs(int s)             //��������������ڽӱ����루�����һ��ͼ�ı�ʾ����
{
    for(int i = 1; i <= n; i++) //��ʼ��
    {
        d[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    visited[s] = true;
    d[s] = 0;
    queue<int> q;        //��STL����ʵ�� ��#include <queue>
    q.push(s);           //ѹ�����
    while(!q.empty())
    {
        int u = q.front();          //ȡ��ͷԪ��
        arcnode * p = Ver[u].firarc;
        while(p != NULL)        //�������ڶ���
        {
            if(!visited[p->vertex])
            {
                q.push(p->vertex);  //ѹ�����
                parent[p->vertex] = u;  //ָ����
                d[p->vertex] = d[u]+1;  //·����+1
                visited[p->vertex] = true;   //��Ϊ�ѱ�����
            }
            p = p->next;
        }
        q.pop();        //������
    }
}
void PrintPath(int s, int v)    //��ӡ��s��v�����·�������ȵ���bfs(s)
{
    if(v == s)
        cout << s << endl;
    else if(parent[v] == -1)
        return;
    else
    {
        PrintPath(s,parent[v]);
        cout << v << endl;
    }
}
