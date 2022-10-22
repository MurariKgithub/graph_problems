#include<bits/stdc++.h>
using namespace std;
int bfs(int arr[][4],int m,int n){
    int countfreash = 0,cont=0;
    int vis[5][4];
    queue<pair<pair<int,int>,int>> q;
    cout<<" Print in visit"<<endl;
    for (int i = 0; i < m; i++)
    { for (int j = 0; j < n; j++)
        {   if(arr[i][j] == 2){
                vis[i][j] = 2;
                q.push({{i,j},0});
                cout<<i<<" "<<j<<endl;
            }
            else{
                vis[i][j] = 0;
            }
            if(arr[i][j] == 1){
                countfreash++;
            }
        }
    }
    
    cout<<" Print in bfs"<<endl;
    int delrow[] = {0,-1,0,1};
    int delcol[] = {-1,0,1,0};
    int row,col,ncol,nrow,t,tm =0;
    while (!q.empty())
      { row = q.front().first.first;
        col = q.front().first.second;
        t = q.front().second;
        cout<<row<<" "<<col<<endl;
        tm = max(t,tm);
        q.pop();
        for (int i = 0; i < 4; i++)
         {   nrow = row+delrow[i];
             ncol = col+delcol[i];
             if(nrow>=0 && ncol>=0 && nrow< m && ncol<n && 
             vis[nrow][ncol]==0 && arr[nrow][ncol]==1){
             vis[nrow][ncol] = 2;
             q.push({{nrow,ncol},t+1});
             
             cont++;
            }
         }
      }
      cout<<" Print visited arr"<<endl;
      for (int i = 0; i < m; i++)
      { for (int j = 0; j < n; j++)
       {   cout<<vis[i][j]<<" ";
       }
           cout<<endl;
      }
      if(countfreash!=cont){
        cout<<-1<<" "<<countfreash<<cont;
      }
     else{
        cout<<tm;
     }
}

int main(){
    int arr[5][4] = {{1,1,2,0},
                     {0,0,0,1},
                     {2,1,1,1},
                     {0,1,0,1},
                     {0,1,2,0}};
    cout<<"hello murari";
    bfs(arr,5,4);
}