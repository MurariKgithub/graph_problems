#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int n = grid.size();   //no of row's
        int m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>> p;
        p.push({i,j});
        int delrow[] = {-1,+1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!p.empty()){
            int row = p.front().first;
            int col = p.front().second;
            p.pop();
            for(int i =0 ;i<4 ;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow<n && ncol<m && ncol>=0 && nrow>=0 && 
                   grid[nrow][ncol] == 'O' && vis[nrow][ncol]==0){
                       vis[nrow][ncol] = 1;
                       p.push({nrow,ncol});
                   }
            }
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        // 1st row and last row
        for(int i = 0 ;i<m ;i++){
            if(vis[0][i]==0 && grid[0][i]=='O')   bfs(0,i,vis,grid);
            if(vis[n-1][i]==0 && grid[n-1][i]=='O') bfs(n-1,i,vis,grid);
        }
        // first col and last col 
        for(int i = 0; i<n ;i++){
            if(vis[i][0]==0 && grid[i][0] == 'O')   bfs(i,0,vis,grid);
            if(vis[i][m-1]==0 && grid[i][m-1]=='O') bfs(i,m-1,vis,grid);
        }
        for(int i = 0 ;i<n ;i++){
            for(int j =0 ;j<m ;j++){
                if(vis[i][j]==0 && grid[i][j]=='O'){
                    grid[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
        for(int i = 0;i<n ;i++){
            for(int j =0 ;j<m ;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
};
int main(){
    vector<vector<char>> grid = {{'X','X','X' ,'X','X'},{'O' ,'X' ,'X' ,'X','O'},
                                 {'O', 'X', 'X','O','X'},{'X','X','X','O','O'}};
    fill(grid.size(),grid[0].size(),grid);
}



