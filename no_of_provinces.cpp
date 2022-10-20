#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> &vis,unordered_map<int,list<int>> mp1,int node){
   vis[node] = 1;
   for(auto it:mp1[node]){
    if(vis[it]!=1){
        dfs(vis,mp1,it);
    }
   }
}
int func(int arr[][2],int n,int m){
    vector<int> vis(n,0);
    unordered_map<int,list<int>> mp1;
    for (int i = 0; i < m; i++)
    {  mp1[arr[i][0]].push_back(arr[i][1]);
       mp1[arr[i][1]].push_back(arr[i][0]);
    }
    // for(auto i:mp1){
    //     cout<<i.first<<"-> ";
    //     for(auto j:i.second){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    int count =0 ;
    for(int i = 0;i<vis.size();i++){
        if(vis[i]!=1 && mp1.find(i)!=mp1.end()){
            count++;
            dfs(vis,mp1,i);
        }
    }
    return count;
}
int main(){
   int arr[7][2] = {{0,10},{1,2},{1,3},{4,6},{4,5},{4,7},{5,7}};
  cout<<"No of provinces in graph is : ";
  cout<<func(arr,10,7);
}