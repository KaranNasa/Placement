//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        
        dfs(i-1,j,n,m,grid);
        dfs(i+1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i,j+1,n,m,grid);
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        // do boundary traversal
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==(n-1) || j==(m-1))
                {
                    if(grid[i][j] == 1){
                        dfs(i,j,n,m,grid);
                    }
                }
            }
        }
        
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends