#define INF 9999
bool visited[maxn];     //标记顶点是否被考察，初始值为false
int parent[maxn];       //parent[]记录某结点的父亲结点，生成树，初始化为-1
int d[maxn], time, f[maxn]; //时间time初始化为0，d[]记录第一次被发现时，f[]记录结束检查时
void dfs(int s)         //深度优先搜索（邻接表实现），记录时间戳，寻找最短路径
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
void dfs_travel()       //遍历所有顶点，找出所有深度优先生成树，组成森林
{
    for(int i = 1; i <= n; i++)     //初始化
    {
        parent[i] = -1;
        visited[i] = false;
    }
    time = 0;
    for(int i = 1; i <= n; i++)     //遍历
        if(!visited[i])
            dfs(i);
    cout << endl;
}
