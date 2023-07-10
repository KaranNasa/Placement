//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int timer=1;
    void dfs(int node,int parent,vector<int> &vis,int low[],int time[],vector<int> &mark,vector<int> adj[],int n)
    {
        vis[node]=1;
        low[node]=time[node]=timer;
        
        timer++;
        
        int child=0;
        
        for(auto itr:adj[node]){
            if(itr==parent)
                continue;
            
            if(!vis[itr]){
                dfs(itr,node,vis,low,time,mark,adj,n);
                // update low of node
                low[node]=min(low[node],low[itr]);
                
                if(low[itr] >= time[node] and parent!=-1)   // if the adj_node cannot reach before curr_dnoe and also if its not the start parent i.e. where the dfs is called then that means it is an articulation point
                {
                    mark[node]=1;
                }
                
                child++;
                
            }
            else{
                low[node]=min(low[node],time[itr]); // at this time if visited then we take the time and not low
            }
        }
        if(child > 1 and parent==-1)    
            mark[node]=1;   // if child > 1 and its the starting point of dfs then its definately an articulation point
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
          
        vector<int> vis(n,0);
        int low[n],time[n];
        vector<int> mark(n,0);  // this will tell which are the articulation points
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,low,time,mark,adj,n);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<mark.size();i++){
            if(mark[i]==1)
                ans.push_back(i);
        }
        if(ans.size()==0)
            return {-1};
        else
            return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends