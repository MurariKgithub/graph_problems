#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// bfs code
bool DetectCyclewithBFS_algo(vector<int> &vis,vector<int> adj[],int node,int par){
        vis[node] = 1;
        queue<pair<int,int>> q;
        q.push({node,par});
        while(!q.empty()){
            int newnode = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[newnode]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,newnode});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
// dfs code
bool DetectCyclewithDFS_algo(vector<int> &vis,vector<int> adj[],int node,int par){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(DetectCyclewithDFS_algo(vis,adj,it,node)){
                    return true;
                }
            }
            else if(it!=par){
                return true;
            }
        }
        return false;
    }
bool DetectCycle(vector<int> adj[5], int v,int e){
  vector<int> vis(v,0);
  for (int i = 0; i < v; i++)
  { 
    if(!vis[i]){
        int par = -1;
        if(DetectCyclewithDFS_algo(vis,adj,i,par)){
            return true;
        }
    }
  }
  return false;
  
}
int main(){
   int v = 5, e = 5;
   vector<int> adj[5];
   for(int i =0;i< v; i++){
    int u,v;
    cin>>u;
    cin>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   cout<<DetectCycle(adj,v,e);
}