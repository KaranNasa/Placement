//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(int x,int y,int n,int m,vector<vector<int>> A)
    {
        if(x<0 || x>=n or y<0 || y>=m or A[x][y]==2 || A[x][y]==0)
            return false;
        else
            return true;
    }
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        // code here
        
        if(A[0][0]==0 || A[X][Y]==0)
            return -1;
            
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        A[0][0]=2;
        
        while(!q.empty()){
            int dist=q.front().first;
            int value_x=q.front().second.first;
            int value_y=q.front().second.second;
            
            q.pop();
            
            if(value_x==X and value_y==Y){
                return dist;
            }
            
            int x_val[4]={0,0,1,-1};
            int y_val[4]={1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int new_x=value_x + x_val[i];
                int new_y=value_y + y_val[i];
                
                if(check(new_x,new_y,n,m,A)){
                    A[new_x][new_y]=2;
                    
                    q.push({dist+1,{new_x,new_y}});    
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends