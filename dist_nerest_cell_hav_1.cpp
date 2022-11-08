#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<vector<int>>nearest(vector<vector<int>>grid)
{   int n = grid.size();
	int m = grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i = 0;i<n ;i++){
	        for(int j= 0;j<m ;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j] =1;
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }

	    int delrow[] = {-1,0,1,0};
	    int delcol[] = {0,+1,0,-1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int t = q.front().second;
	        q.pop();
	        dist[row][col] = t;
	        for(int i =0 ;i<4 ;i++){
	            int nrow = row+delrow[i];
	            int ncol = col+delcol[i];
	            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]!=1){
	                q.push({{nrow,ncol},t+1});
	               // cout<<nrow<<" "<<ncol<<endl;
	                vis[nrow][ncol] =1;
	            }
	        }
	    }
	    return dist;
	    // Code here
}
int main(){
    vector<vector<int>> mat = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    int m = mat.size(),n=mat[0].size();
    // taking input for the mat
    // for (int i = 0; i < n; i++)
    // {   for (int j = 0; j < m; j++)
    //        cin>>mat[i][j];  
    // }
    vector<vector<int>> ans = nearest(mat);
    for(int i =0;i<m ;i++){
        for(int j = 0; j<n ;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}