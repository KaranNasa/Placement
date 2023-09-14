//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check_cycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto itr:adj[node]){
            if(!vis[itr]){
                if(check_cycle(itr,adj,vis,dfsvis))
                    return true;
            }
            else if(vis[itr] and dfsvis[itr])
                return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0),dfsvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(check_cycle(i,adj,vis,dfsvis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends