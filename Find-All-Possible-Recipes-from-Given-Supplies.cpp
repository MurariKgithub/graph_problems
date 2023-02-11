class Solution {

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> ans;
        
        map<string,vector<string>> adjls;
        map<string,int> Indegree;
        
        for(int i=0 ;i<n ;i++){ 
            for(int j =0; j<ingredients[i].size() ;j++){
                adjls[ingredients[i][j]].push_back(recipes[i]);
                Indegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for(auto it:supplies) q.push(it);
        
        while(!q.empty()){
            string node = q.front();
            q.pop();
            for(auto it:adjls[node]){
         
                if(Indegree.find(it)!=Indegree.end() && --Indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
            
        // for(auto it:res) ans.push_back(it);
        // return ans;
        
    }
};
