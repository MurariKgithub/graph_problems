#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adjls[],vector<int> &ans,int node,int end,vector<vector<int>> &res){
    if(node==end){
        ans.push_back(end);
        res.push_back(ans);
        // for(auto it:ans) cout<<it<<",";
        // cout<<end<<endl;
        ans.pop_back();
        return;
    }
    for(auto it:adjls[node]){
        ans.push_back(node);
        dfs(adjls,ans,it,end,res);
        ans.pop_back();
    }
}
void find_all_paths(vector<vector<int>> &graph){
    // cout<<"hello"<<endl;
    int n =graph.size();
    vector<int> adjls[n],ans;
    vector<vector<int>> res;
    for(int i =0 ;i<graph.size() ;i++){
        for(auto it:graph[i]){
            adjls[i].push_back(it);
        }
    }
    dfs(adjls,ans,0,n-1,res);
    for(int i =0 ;i<res.size() ;i++){
        for(auto it:res[i]) cout<<it<<",";
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> graph ={{4,3,1},{3,2,4},{3},{4},{}};
    find_all_paths(graph);
}