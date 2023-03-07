// Approch 1: using DP 
// DP fails 
// O(n*MaxJump)  
class Solution {
public:
    bool func(string s,int mini ,int maxi,int indx,vector<int> &dp){
        if(s.size()-1==indx) return !(s[indx]-'0');
        if(dp[indx]!=-1) return dp[indx];
        int l = indx+mini;
        int n =s.size();
        int r = min(indx+maxi,n-1);
        bool flag=false;
        for(int j=l ;j<=r ;j++){
            if(s[j]=='0') flag|=func(s,mini,maxi,j,dp);
        }
        return dp[indx] = flag;
    }
    bool canReach(string s, int mini, int maxi) {
        int n =s.size();
        vector<bool> dp(n,0);
        // return func(s,minJump,maxJump,0,dp);
        dp[n-1] = !(s[n-1]-'0');
        for(int indx = n-2 ;indx>=0 ;indx--){
            int l = indx+mini;
            int n =s.size();
            int r = min(indx+maxi,n-1);
            bool flag=false;
            for(int j=l ;j<=r ;j++){
                if(s[j]=='0') flag|=dp[j];
            }
            dp[indx] = flag;
        }
        return dp[0];
    }
};
// Simple BFS
// TC = O(n),S.C =O(n)
class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        int fartest = 0;
        queue<int> q;
        q.push(0);
        int n =s.size();
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // cout<<node<<endl;
            if(node==n-1) return !(s[node]-'0');
            int n1=node+mini,n2=node+maxi;
            int l = max(n1,fartest+1);
            int r = min(n2,(n-1));
            // cout<<l<<" "<<r<<" "<<n2<<" "<<n-1<<endl;
            for(int i=l ;i<=r ;i++){
                fartest = max(fartest,i);
                if(s[i]=='0'){
                    q.push(i);
                }
            }
        }
        return false;
    }
};
