#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,int>> adjls[],vector<int> &vis
,int node,int &e,int &minval){
    vis[node] = 1;
    for(auto it:adjls[node]){
        if(vis[it.first]!=1){
        e = it.first;
        minval = min(minval,it.second);
        dfs(adjls,vis,it.first,e,minval);
     }
   }
}
vector<vector<int>> components(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<pair<int,int>> adjlist[n+1];
    vector<int>in(n+1,0);
    vector<int>out(n+1,0);
    for(auto it:edges){
        in[it[1]]=1;
        out[it[0]]=1;
        adjlist[it[0]].push_back({it[1],it[2]});
    }
    vector<int>vis(n+1,0);
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i] && out[i]==1 && in[i]!=1){
           int s=i;
            int e;
            int val=1e9+7;
            dfs(adjlist,vis,i,e,val);
            ans.push_back({s,e,val});
        }
    }
   // cout<<cnt<<endl;
    return ans;
}
int main(){
    vector<vector<int>> arr = {{1,2,5},
                               {2,3,1},
                               {3,4,8},
                               {5,6,10},
                               {6,8,9},
                               {7,9,15}};
    vector<vector<int>> ans = components(9,3,arr);
    for(auto it:ans){
        cout<<it[0]<<"->"<<it[1]<<" with minimal wgt of: "<<it[2]<<endl;
    }
}