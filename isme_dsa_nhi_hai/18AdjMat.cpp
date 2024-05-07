#include<bits/stdc++.h>
using namespace std;
int adj[100][100]={0};
void bfs(int v){
    int vis[v]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<v;i++){
            if(adj[node][i]&&!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
void dfs(vector<int>&vis,int node,int v){
    vis[node]=1;
    cout<<node<<" ";
    for(int i=0;i<v;i++){
        if(adj[node][i]&&!vis[i]){
            dfs(vis,i,v);
        }
    }

}
int connectedComponent(int v){
    vector<int>vis(v);
    int count=0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(vis,i,v);
            count++;
        }
    }
    return count;
    
}
int main(){
    int e,v;
    cin>>v>>e;
    
    for(int i=0;i<e;i++){
        int u,v;cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    bfs(v);
    cout<<endl;
    vector<int>vis(v);

    dfs(vis,0,v);
    cout<<endl;
    int connect=connectedComponent(v);
    cout<<endl;
    if(connect==1) cout<<"Graph Connected\n";
    else{
        cout<<"Not Connected\n";
        cout<<connect<<" components\n";
    }
}