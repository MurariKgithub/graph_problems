class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n,0);
        
        vector<vector<int>>adjls(n);
        for(auto it:edges){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
            deg[it[1]]++;
            deg[it[0]]++;
        }
        vector<int> ans;
       
        if(n==1) return vector<int>(1,0);
        queue<int> q;
        for(int i=0 ;i<n ;i++){
            if(deg[i]==1) q.push(i);
        } 
        int no= n;
        while(no>2){
            int size = q.size();
            no-=size;
            for(int i=0 ;i<size ;i++){
                int node = q.front();
                q.pop();
                for(auto it:adjls[node]){
                    deg[it]--;
                    if(deg[it]==1) q.push(it);
                }
            }
        }
        while(!q.empty()) ans.push_back(q.front()),q.pop();
        return ans;
    }
};
