#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
void bfs(int node,vector<int> adjls[],vector<int> &vis,vector<int> &ans){
    vis[node] =1 ;
    queue<int> pq;
    pq.push(node);
    while(!pq.empty()){
        int adj = pq.front();
        pq.pop();
        for(auto it:adjls[adj]){
            if(!vis[it]){
               pq.push(it);
               vis[it] = 1;
               ans.push_back(it);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{    vector<int> vis(vertex,0),ans;
     vector<int> adjls[5];
     for(auto it:edges){
        adjls[it.first].push_back(it.second);
        adjls[it.second].push_back(it.first);
     }
     for(int i = 0;i<vertex ;i++){
         if(!vis[i]){
            ans.push_back(i);
            bfs(i,adjls,vis,ans);
         }
     }
    for(auto it:ans){
        cout<<"Hello";
        cout<<it<<" ";
    }
}
int main(){
   int v = 9, e = 10;
   vector<pair<int,int>> edges = {{0,8},{1,6},{1,7},{1,8},{5,8},{6,0},{7,3},{7,4},{8,7},{2,5}};
   BFS(v,edges);
}