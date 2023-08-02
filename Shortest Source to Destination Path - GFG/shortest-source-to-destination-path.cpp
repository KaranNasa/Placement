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
        if(x<0 || x>=n || y<0 || y>=m || A[x][y]==0)
            return false;
        else
            return true;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        vector<vector<int>> dis(N,vector<int>(M,INT_MAX));
        
        dis[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int curr_distance=0;
        
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int curr_dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
            if(x==X and y==Y)
                return curr_dist;
            
            pq.pop();
            
            int i_value[4]={0,0,1,-1};
            int j_value[4]={1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int new_x=x+i_value[i];
                int new_y=y+j_value[i];
                
                if(check(new_x,new_y,N,M,A)){
                    if(dis[new_x][new_y] > curr_dist + 1){
                         dis[new_x][new_y]=curr_dist+1;
                         pq.push({curr_dist+1,{new_x,new_y}});     
                    }
                   
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