//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size(),m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            
            int diff=itr.first;
            int row=itr.second.first;
            int col=itr.second.second;
            
            if(row==n-1 and col==m-1)
                return diff;
            
            int x[]={1,-1,0,0};
            int y[]={0,0,1,-1};
            
            for(int i=0;i<4;i++){
                int newr=row+x[i];
                int newc=col+y[i];
                
                if(newr>=0 and newr<n and newc>=0 and newc<m){
                    int max_effort=max(diff,abs(heights[newr][newc] - heights[row][col]));
                    
                    if(max_effort < dist[newr][newc]){
                        dist[newr][newc]=max_effort;
                        pq.push({max_effort,{newr,newc}});
                    }
                }
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends