//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
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
    
    int doctorStrange(int n, int m, vector<vector<int>> & graph)
    {
         //Write your code here
        vector<int> vis(n+1,0);
        int low[n+1],time[n+1];
        vector<int> mark(n+1,0);  // this will tell which are the articulation points
        
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            adj[graph[i][0]].push_back(graph[i][1]);
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,low,time,mark,adj,n);
            }
        }
        
        // vector<int> ans;
        int count_articulation=0;
        for(int i=1;i<mark.size();i++){
            if(mark[i]==1)
                count_articulation++;
                
        }
        return count_articulation;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}
// } Driver Code Ends