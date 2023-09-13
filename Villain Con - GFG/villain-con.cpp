//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        vector<int> adj[N+1];
        vector<int> indegree(N+1,0);
        
        for(int i=0;i<M;i++){
            adj[mat[i][1]].push_back(mat[i][0]);
            indegree[mat[i][0]]++;
        }
        
        int count=0;
        queue<int> q;
        for(int i=1;i<N+1;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            count++;
            while(size--){
                int node=q.front();
                q.pop();
                for(auto itr:adj[node]){
                    indegree[itr]--;
                    if(indegree[itr] == 0)
                        q.push(itr);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends