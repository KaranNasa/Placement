//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &matrix)
    {
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]==0)
            return;
        
        matrix[i][j]=0;
        dfs(i-1,j,n,m,matrix);
        dfs(i+1,j,n,m,matrix);
        dfs(i,j-1,n,m,matrix);
        dfs(i,j+1,n,m,matrix);
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(matrix[i][j]==1)
                        vec.push_back({i,j});
                }
            }
        }
        
        for(auto itr:vec){
            int i=itr.first;
            int j=itr.second;
            
            dfs(i,j,n,m,matrix);
        }
        
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(matrix[i][j] == 1){
                    count++;
                    dfs(i,j,n,m,matrix);
                }
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends