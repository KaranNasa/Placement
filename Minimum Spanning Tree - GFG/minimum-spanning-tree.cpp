//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        // vector<pair<int,int>> adj_list[V];
        // first create the adjacency list
        // for(auto itr:adj){
        //     cout<<itr[0]<<" "itr[1]<<" "<<itr[2]<<endl;
        // }
        
        // first create a min heap for distance and node
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        // create a vis array
        vector<int> vis(V,0);
        
        int MST_sum=0;
        
        while(!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            
            int dist=itr.first;
            int node=itr.second;
            
            if(!vis[node])
            {
                vis[node]=1;
                MST_sum+=dist;
                // now look for adj nodes which are not visited
                for(auto it:adj[node]){
                    if(!vis[it[0]]){
                        pq.push({it[1],it[0]});
                    }
                }
            }
        }
        
        return MST_sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends