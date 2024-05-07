#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>>adj[N];
const int N=1e5+10;
int parent[N];
int size[N];
void make(int v){
    parent[v]=v;
    size[v]=1;
}
int find(int v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}
int unionn(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < V; i++)
    {
        make(i);
    }

    int total_cost = 0;
    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) == find(v))
            continue;
        unionn(u, v);
        total_cost += wt;
        cout << u << " " << v << endl;
    }
    cout << total_cost << endl;
    

}
