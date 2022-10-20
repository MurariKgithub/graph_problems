#include<bits/stdc++.h>
using namespace std;
void dfs(int arr[][4],vector<vector<int>> &vis,int row,int col,int m,int n){
    if(row<0 || col<0 ||row>=m||col>=n||vis[row][col]==1||arr[row][col]==0){
        return;
    }
    vis[row][col] = 1;
    // for(int i =-1;i<=1 ;i++){
    //     for(int j =-1 ;j<=1;j++){
    //         dfs(arr,vis,i+row,col+j,m,n);
    //     }
    // }
    dfs(arr,vis,1+row,col,m,n);
    dfs(arr,vis,row-1,col,m,n);
    dfs(arr,vis,row,col-1,m,n);
    dfs(arr,vis,row,col+1,m,n);
}
int func(int arr[][4],int m,int n){
    vector<vector<int>> vis(m,vector<int>(n,0));
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         vis[i][j] = 0;
    //     }
    // }
    int count =0 ;
    for(int i=0;i<m;i++){
        for(int j= 0;j<n ;j++){
            if(vis[i][j]==0 and arr[i][j]==1){
                count++;
                dfs(arr,vis,i,j,m,n);
            }
        }
    }
    cout<<count;
}
int main(){
    int arr[4][4] = {{0,1,1,0},{0,1,1,0},{0,1,0,1},{1,0,1,0}};
    func(arr,4,4);
}
