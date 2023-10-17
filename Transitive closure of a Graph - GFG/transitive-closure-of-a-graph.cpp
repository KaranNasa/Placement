//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int index,int N,vector<int> adj[],vector<int> &vis)
    {
        vis[index]=1;
        for(auto itr:adj[index])
        {
            if(!vis[itr])
                dfs(itr,N,adj,vis);
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[N];
        int n=graph.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] == 1)
                {
                    if(i!=j)
                        adj[i].push_back(j);
                }
            }
        }
            
        vector<vector<int>> ans(N,vector<int> (N,0));
        for(int i=0;i<N;i++){
            vector<int> vis(N,0);
            dfs(i,N,adj,vis);
            for(int j=0;j<N;j++){
                if(vis[j]==1)
                    ans[i][j]=1;
            }
            // for(auto itr:vis){
            //     if(itr==1)
            //         ans[i][itr]=1;
            // }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends