//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int m, int n) 
    { 
        // Your code goes here
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 'B'){
                    ans[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int new_x[4]={0,0,1,-1};
        int new_y[4]={1,-1,0,0};
        
        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int i=x+new_x[k];
                int j=y+new_y[k];
                
                if(i>=0 and i<m and j>=0 and j<n)
                {
                    if(matrix[i][j] == 'B' || matrix[i][j]=='W')
                        continue;
                    
                    if(ans[i][j] > dist+1){
                         ans[i][j]=min(ans[i][j],dist+1); 
                         q.push({ans[i][j],{i,j}});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 'B')
                    ans[i][j]=0;
                else if(matrix[i][j] == 'W')
                    ans[i][j]=-1;
                else if(matrix[i][j]=='O' and ans[i][j]==INT_MAX)
                    ans[i][j]=-1;
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends