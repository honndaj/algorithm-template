#include <iostream>
#include <vector>
#include <algorithm>
#define N 5005
#define M 200005
using namespace std;

struct Edge {
    int from, to ,dist;
    Edge(int u, int v,int w) : from(u), to(v), dist(w) {}
};

int n,m,fa[N];
vector<Edge> edges;

bool cmp(Edge a, Edge b) {
    return a.dist<b.dist;
}

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

int Kruskal() {
    int ret = 0,count = 0;;
    for(int i = 0; i < m; i++) {
        int x= edges[i].from, y = edges[i].to;
        if(find(x) != find(y)) {
            unite(x,y);
            ret += edges[i].dist;
            count ++;
        }
    }
    return count == n-1 ? ret : 0;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u,v,w));
    }
    for(int i = 0; i < n; i++) {
        fa[i] = i;
    }
    sort(edges.begin(), edges.end(), cmp);
    int ret = Kruskal();
    cout<<ret;
    return 0;
}