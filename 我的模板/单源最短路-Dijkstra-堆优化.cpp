#include <bits/stdc++.h>
typedef std::pair<int,int> PII;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

struct Link {
    // V:连接点，Dis:边权
    int V, Dis;
    Link(int _V = 0, int _Dis = 0): V(_V), Dis(_Dis) {}
};

// N:定点数，E:边数
int N, E;
// 松弛更新数组
int Dis[maxn];
// 邻接表
std::vector<Link> Adj[maxn];

// 建图加边，U、V:顶点,Weight:权值
void AddEdge(int U, int V, int Weight) {
    Adj[U].push_back(Link {V, Weight});
    // 无向图反向建边
    Adj[V].push_back(Link {U, Weight});
}

// Dijkstra堆优化算法
int Dijkstra(int Start, int End) {
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > Que;
    memset(Dis, INF, sizeof(Dis));
    Dis[Start] = 0;
    Que.push(std::make_pair(0, Start));
    while (!Que.empty()) {
        PII Keep = Que.top();
        Que.pop();
        int V = Keep.second;
        if (Dis[V] < Keep.first) {
            continue;
        }
        // 找到最短路
        if (Keep.second == End) {
            break;
        }
        for (int i = 0; i <int(Adj[V].size()); ++i) {
            Link Temp = Adj[V][i];
            if (Dis[Temp.V] > Dis[V] + Temp.Dis) {
                Dis[Temp.V] = Dis[V] + Temp.Dis;
                Que.push(std::make_pair(Dis[Temp.V], Temp.V));
            }
        }
    }
    // 未找到最短路
    return -1;
}
