//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here  
            vector<int> distance(n,0);
            vector<int> indegree(n+1,0);
            vector<int> adj[n+1];
            
            for(int i=0;i<m;i++){
                indegree[edges[i][1]]++;
                adj[edges[i][0]].push_back(edges[i][1]);
            }
            
            queue<pair<int,int>> q;
            for(int i=1;i<n+1;i++){
                if(indegree[i]==0)
                    q.push({i,1});
            }
            
            while(!q.empty())
            {
                auto itr=q.front();
                q.pop();
                
                int node=itr.first;
                int dist=itr.second;
                distance[node-1]=dist;
                
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push({it,dist+1});
                    }
                }
            }
            
            return distance;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends