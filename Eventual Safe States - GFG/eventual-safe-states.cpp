//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool cycle(int node,int V,vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,vector<bool> &cycle_nodes)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto itr:adj[node])
        {
            if(!vis[itr])
            {
                if(cycle(itr,V,adj,vis,dfsvis,cycle_nodes))
                    return cycle_nodes[node]=true;
            }
            else if(vis[itr] and dfsvis[itr])
                return cycle_nodes[node]=true;
        }
        dfsvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        
        vector<bool> cycle_nodes(V,false); 
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cycle(i,V,adj,vis,dfsvis,cycle_nodes);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(cycle_nodes[i]==false)
                ans.push_back(i);
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends