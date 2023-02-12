typedef long long ll;
class Solution {
ll fule=0;
private:
    long long TotalFuleTakes(int node,int parent,vector<vector<int>>& adjls,int seats){
        ll passinger= 0;
        
        for(auto child:adjls[node]){
            if(child!=parent){
                int p = TotalFuleTakes(child,node,adjls,seats);
                passinger +=p;
                fule+= ceil((double)p/seats);
                // cout<<node<<" "<<(passinger/seats)<<endl;
                // if(p%seats) fule += p/seats+1;
                // else fule += p/seats;
            }
        }
        return passinger+1;
    }    
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adjls(n+1);
        for(auto it:roads){
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        TotalFuleTakes(0,-1,adjls,seats);
        return fule;
    }
};
