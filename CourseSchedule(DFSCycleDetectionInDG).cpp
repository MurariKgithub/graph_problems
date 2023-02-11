class Solution {
public:
    bool isloop(vector<vector<int>> &adjls,int node,vector<int> &path,vector<int>& vis){
        for(auto it:adjls[node]){
            if(!vis[it]){
                vis[it]=1;
                path[it] =1;
                if(isloop(adjls,it,path,vis)) return true;
            }
            if(path[it]) return true;
        }
        path[node] = 0;
        return false;
    }
    bool canFinish(int no, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjls(no);
        for(auto it:prerequisites) adjls[it[0]].push_back(it[1]);
        vector<int> path(no,0),vis(no,0);
        for(int i=0 ;i<no ;i++){
            if(!vis[i] && isloop(adjls,i,path,vis)) return false;
        }
        return true;
    }
};
