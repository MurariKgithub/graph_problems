#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int dfs(vector<int> &vis,vector<pair<int,int>> adjls[],int k,int a,int b,int &node,int &minval,int &ans,int base){
    vis[node] = 1;
    // cout<<node<<" ";
    for(auto it:adjls[node]){
        if(vis[it.first]!=1){
            int sum = base+it.second;
            //cout<<base<<" "<<it.second<<endl;
            cout<<sum<<" "<<k<<endl;
          if(sum>k){
            // cout<<sum<<" "<<k<<endl;
            if(b<=a){
                cout<<it.first<<" "<<it.second<<endl;
                ans+=b;
            }
            else if(a<b && base+minval<k){
                ans+=a;
                // cout<<"\ni am in 2nd: ";
                // cout<<it.first<<" "<<it.second;
            }
         }
         
         dfs(vis,adjls,k,a,b,it.first,minval,ans,base);
        }
    }
    } 
void solve(int n,vector<int> &par,vector<int> &arr,int k,int a,int b){
    vector<pair<int,int>> adjls[14];
    for (int i = 1; i < n; i++)
    {  adjls[par[i]].push_back({i,arr[i]});
    }
    int ans1 = b,ans2=a,base=0;
    vector<int> vis(n,0);
    int minval = *min_element(arr.begin(),arr.end());
    // if(arr[0]>k){
    //     if(a>=b){
    //         ans1+=b;
    //         base = 0;
    //     }
    //     else if(a<b && minval<k){
    //       ans1+=a;
    //       base = minval;
    //     }
    // }
    //cout<<"before func call: "<<ans1<<endl;
    int i=0;
    dfs(vis,adjls,k,a,b,i,base,ans1,base);         
    // if(arr[0]>k)
    //     ans+=b; 
    //cout<<minval<<endl;
    base = *min_element(arr.begin(),arr.end());
    vector<int> vis2(n,0);
    if(minval<k){
    dfs(vis2,adjls,k,a,b,i,base,ans2,base);
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;   
}
int main(){
    vector<int>  par = {-1,0,1,2,1,4,2,3,4,1};
    vector<int> arr ={96,58,83,86,38,98,70,19,18,51};
    int k=16,a=10,b=96;
    solve(10,par,arr,k,a,b);
}