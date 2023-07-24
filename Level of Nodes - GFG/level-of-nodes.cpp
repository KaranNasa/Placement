//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    
	    // something like a bfs traveesal
	    
	    vector<int> vis(V,0);
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    
	    while(!q.empty()){
	        auto itr=q.front();
	        q.pop();
	        
	        int curr_level=itr.first;
	        int node=itr.second;
	        
	        if(node==X) // found the node
	            return curr_level;
	        vis[node]=1;
	        
	        for(auto itr:adj[node]){
	            if(!vis[itr]){
	                q.push({curr_level+1,itr});
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends