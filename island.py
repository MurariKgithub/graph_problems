def dfs(arr,vis,i,j,m,n):
    if(i<0 or j<0 or i>m-1 or j>n-1 or arr[i][j]==0 or vis[i][j]==1):
        return 
    vis[i][j] = 1
    dfs(arr,vis,i+1,j,m,n)
    dfs(arr,vis,i-1,j,m,n)
    dfs(arr,vis,i,j+1,m,n)
    dfs(arr,vis,i,j-1,m,n)
def func(arr,m,n):
    vis = [[0]*n for _ in range(m)]
    count = 0
    for i in range(m):
        for j in range(n):
            if(arr[i][j]==1 and vis[i][j]==0):
                print(i,j)
                count+=1
                dfs(arr,vis,i,j,m,n)
    print(count)
arr = [[0,1,1,0],[0,1,1,0],[0,1,0,1],[1,0,1,0]]
func(arr,4,4)
