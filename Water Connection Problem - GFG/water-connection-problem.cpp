//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(int index,vector<pair<int,int>> adj[],int &min_weight,int &e,vector<int> &vis)
    {
        vis[index]=1;
        for(auto itr:adj[index]){
            if(!vis[itr.first]){
                e=itr.first;  // last_node
                min_weight=min(min_weight,itr.second);
                dfs(itr.first,adj,min_weight,e,vis);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        
        vector<int> vis(n+1,0);
        vector<vector<int>> ans;
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        
        vector<pair<int,int>> adj[n+1];   // adj list
        
        for(int i=0;i<p;i++){
            out[a[i]]=1;
            in[b[i]]=1;
            adj[a[i]].push_back({b[i],d[i]});
        }
        
        for(int i=1;i<=n;i++){
            if(in[i]==0 and out[i]==1 and !vis[i]){
                // start point
                int s=i;
                int e;
                int min_weight=INT_MAX;
                dfs(i,adj,min_weight,e,vis);
                
                ans.push_back({s,e,min_weight});
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends