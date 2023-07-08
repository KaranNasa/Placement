//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    class DisjointSet
    {
        public:
            vector<int> par,sizeL;
            DisjointSet(int n)
            {
                par.resize(n);
                sizeL.resize(n);
                for(int i=0;i<n;i++){
                    par[i]=i;
                    sizeL[i]=1;
                }
            }
            
            int findPar(int u)
            {
                if(u==par[u]) 
                    return u;
                
                return par[u]=findPar(par[u]);
            }
            
            void unionBysize(int u,int v)
            {
                int ulpu=findPar(u);
                int ulpv=findPar(v);
                
                if(ulpu==ulpv) 
                    return;
                    
                if(sizeL[ulpu]<sizeL[ulpv])
                {
                    sizeL[ulpv]+=sizeL[ulpu];
                    par[ulpu]=par[ulpv];
                }
                else
                {
                    sizeL[ulpu]+=sizeL[ulpv];
                    par[ulpv]=par[ulpu];
                }
            }
    };
	
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    DisjointSet ds(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int u=i;
                int v=it;
                if(ds.findPar(u)==ds.findPar(v) && u<v) 
                    return 1;
                else
                {
                    ds.unionBysize(u,v);
                }
            }
        }
        return 0;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends