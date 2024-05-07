#include<bits/stdc++.h>
using namespace std;
vector<int>adj[];
void topological(int node,vector<int>&vis,stack<int>&s){
    vis[node]=1;
    for(auto&it:adj[node]){
        if(!vis[it]) topological(it,vis,s);
    }
    s.push(node);
}
void bfs(int source,int v){
    vector<int>vis(v);
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        for(auto&it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    vector<int>vis(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topological(i,vis,s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
}