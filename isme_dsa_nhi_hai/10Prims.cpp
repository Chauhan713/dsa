#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[100];
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));

    }
    int vis[n]={0};
    int key[n];
    int parent[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=0;
    int ans=0;
    for(int i=0;i<n-1;i++){
        int mini=INT_MAX,u;
        for(int j=0;j<n;j++){
            if(!vis[j]&&key[j]<mini){
                mini=key[j];
                u=j;
            }
        }
        vis[u]=1;
        for(auto&it: adj[u]){
            int v=it.first;
            int wt=it.second;
            if(!vis[v]&&wt<key[v]){
                parent[v]=u;
                key[v]=wt;
            }
        }
    }
    for(int i=0;i<n;i++) ans+=key[i];
    cout<<ans<<endl;
     for (int i = 0; i < n; i++)
    {
        cout << "(" << parent[i] << " - " << i << ")"
             << " " << endl;
    }
}