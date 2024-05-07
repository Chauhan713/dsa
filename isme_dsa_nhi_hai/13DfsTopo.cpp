#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    cout<<node<<" "; 
    for(auto&it:adj[node]){
        if(!vis[it]) dfs(it,adj,vis);
    }
}
void topological(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node]=1;
    for(auto&it:adj[node]){
        if(!vis[it]) topological(it,adj,vis,s);
    }
    s.push(node);
}
int main(){
    int n,m;cin>>n>>m;
    vector<int>vis(n+1),bfs;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topological(i,adj,vis,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}