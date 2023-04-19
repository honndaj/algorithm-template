#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<utility>
#define N 100005
#define M 200005
using namespace std;

struct Edge{
    int from, to, dist;
    Edge(int u,int v, int w) : from(u), to(v), dist(w) {}
};

vector<Edge> edges;
vector<int> G[N];
int n,m,s;
int d[N];
bool vis[N];

void Dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    for(int  i = 1; i <= n; i++) {
        d[i] = INT_MAX;
        vis[i] = 0;
    }
    d[s] = 0;
    pq.push(pair<int,int>(0, s));
    while(!pq.empty()) {
        pair<int,int> x = pq.top();pq.pop();
        int u = x.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < G[u].size(); i++) {
            Edge e = edges[G[u][i]];
            if(d[e.to] > d[u] + e.dist) {
                d[e.to] = d[u] + e.dist;
                pq.push(pair<int,int>(d[e.to], e.to));
            }
        }
    }
}


int main() {
    // freopen("in.txt", "r", stdin);
    cin>>n>>m>>s;
    for(int i = 1; i <= n; i++) G[i].clear();
    edges.clear();

    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u,v,w));
        G[u].push_back(edges.size()-1);
    }

    Dijkstra();

    for(int i = 1; i <= n; i++) cout<<d[i]<<' ';
    return 0;
}