//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,int m,int n,vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        if(i<0 or i>=m or j<0 or j>=n or vis[i][j] or grid[i][j]=='0')
            return;
        
        vis[i][j]=1;
        int ax[8]={-1,-1,-1,0,0,1,1,1};
        int ay[8]={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++)
        {
            int x=i+ax[k];
            int y=j+ay[k];
            dfs(x,y,m,n,vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        int no_of_islands=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                no_of_islands++;
                dfs(i,j,row,col,vis,grid);
                }
            }
        }
        return no_of_islands;
    }
};
    
    

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends