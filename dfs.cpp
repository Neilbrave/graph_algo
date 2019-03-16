#define INF 9999
bool visited[maxn];     //��Ƕ����Ƿ񱻿��죬��ʼֵΪfalse
int parent[maxn];       //parent[]��¼ĳ���ĸ��׽�㣬����������ʼ��Ϊ-1
int d[maxn], time, f[maxn]; //ʱ��time��ʼ��Ϊ0��d[]��¼��һ�α�����ʱ��f[]��¼�������ʱ
void dfs(int s)         //��������������ڽӱ�ʵ�֣�����¼ʱ�����Ѱ�����·��
{
    cout << s << " ";
    visited[s] = true;
    time++;
    d[s] = time;
    arcnode * p = Ver[s].firarc;
    while(p != NULL)
    {
        if(!visited[p->vertex])
        {
            parent[p->vertex] = s;
            dfs(p->vertex);
        }
        p = p->next;
    }
    time++;
    f[s] = time;
}
void dfs_travel()       //�������ж��㣬�ҳ�����������������������ɭ��
{
    for(int i = 1; i <= n; i++)     //��ʼ��
    {
        parent[i] = -1;
        visited[i] = false;
    }
    time = 0;
    for(int i = 1; i <= n; i++)     //����
        if(!visited[i])
            dfs(i);
    cout << endl;
}
