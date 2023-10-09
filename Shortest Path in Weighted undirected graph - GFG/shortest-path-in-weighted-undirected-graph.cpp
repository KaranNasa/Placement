//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        
        vector<pair<int,int>> adj[n+1];
        for(auto itr:edges){
            int u=itr[0];
            int v=itr[1];
            int wt=itr[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});   // undirected tha
        }
        distance[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,1}); // distance then node
        
        // basically when the distance is updated then update the parent of that node
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto itr:adj[node]){
                if(distance[itr.first] > dist + itr.second){
                    distance[itr.first]=dist+itr.second;
                    parent[itr.first]=node;
                    pq.push({distance[itr.first],itr.first});
                }
            }
        }
        if(distance[n]==INT_MAX)
            return {-1};
        
        vector<int> ans;
        ans.push_back(n);
        int curr_index=n;
        while(curr_index != parent[curr_index]){
            ans.push_back(parent[curr_index]);
            curr_index=parent[curr_index];
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends