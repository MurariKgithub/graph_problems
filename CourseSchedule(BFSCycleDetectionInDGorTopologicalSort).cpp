class Solution {
public:
    bool canFinish(int no, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjls(no);
        vector<int> Indegree(no,0);
        for(auto it:prerequisites){ 
            adjls[it[0]].push_back(it[1]);
            Indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0 ;i<no ;i++){
            if(!Indegree[i]) q.push(i);
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it:adjls[node]){
                if(--Indegree[it]==0) q.push(it);
            }
        }
        return (cnt==no)?true:false;
        
    }
};
