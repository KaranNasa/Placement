//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool check(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == 1 || grid[i][j]==0)
            return false;
        
        if(grid[i][j] == 2)
            return true;
        
        vis[i][j]=1;
        
        int new_x[4]={1,-1,0,0};
        int new_y[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++){
            int x=i+new_x[k];
            int y=j+new_y[k];
            
            if(check(x,y,n,m,grid,vis))
                return true;
        }
        vis[i][j]=0;    // backtrack
        return false;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    if(check(i,j,n,m,grid,vis))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends