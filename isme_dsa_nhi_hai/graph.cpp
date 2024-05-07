#include<bits/stdc++.h>
using namespace std;
vector<int>adj[];
void bfs(int src,int vis[]){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        for(auto&it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
        cout<<endl;
    }
}
void dfs(int src,int vis[]){
    vis[src]=1;
    cout<<src<<" ";
    for(auto&it:adj[src]){
        if(!vis[it]){
            dfs(it,vis);
        }
    }
}
int connectedComponent(int v){
    int vis[v]={0};
    int c=0;
    for(int i=0;i<v;i++){
        if(!vis) {dfs(i,vis); c++;}
    }
    return c;
}
void topological(int src,int vis[],stack<int>&s){
    vis[src]=1;
    for(auto&it:adj[src]){
        if(!vis[it]){
            topological(it,vis);
        }
    }
    s.push(src);
}
int main(){
    int v,e;cin>>v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[v];
    bfs(0,vis);
    vis[v]={0};
    dfs(0,vis);
    vis[v]={0};
    stack<int>s;
    topological(0,vis,s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}