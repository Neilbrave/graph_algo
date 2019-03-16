#define INF 9999
bool visited[maxn];         //标记顶点是否被考察，初始置为false
int d[maxn], parent[maxn];  //d[]记录最短路径长度，parent[]记录某结点的父亲结点，生成树
void bfs(int s)             //广度优先搜索，邻接表输入（详见“一、图的表示”）
{
    for(int i = 1; i <= n; i++) //初始化
    {
        d[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    visited[s] = true;
    d[s] = 0;
    queue<int> q;        //用STL队列实现 ，#include <queue>
    q.push(s);           //压入队列
    while(!q.empty())
    {
        int u = q.front();          //取队头元素
        arcnode * p = Ver[u].firarc;
        while(p != NULL)        //遍历相邻顶点
        {
            if(!visited[p->vertex])
            {
                q.push(p->vertex);  //压入队列
                parent[p->vertex] = u;  //指向父亲
                d[p->vertex] = d[u]+1;  //路径长+1
                visited[p->vertex] = true;   //置为已被考察
            }
            p = p->next;
        }
        q.pop();        //出队列
    }
}
void PrintPath(int s, int v)    //打印从s到v的最短路径，需先调用bfs(s)
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
