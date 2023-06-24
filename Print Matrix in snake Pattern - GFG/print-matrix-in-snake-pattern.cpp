//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    void solve(int row,vector<vector<int>> &matrix,vector<int> &ans,bool &check,int n)
    {
        
        if(check)
        {
            for(int j=0;j<n;j++){
                ans.push_back(matrix[row][j]);
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
                ans.push_back(matrix[row][j]);
        }
        
            
    }
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        vector<int> ans;
        
        int n=matrix.size();
        
        bool check=true;    // if true => left -> right
                            // if false => right -> left
        int i=0;
        while(1)
        {
            if(i>=n)
                break;
            solve(i,matrix,ans,check,n);
            check=!check;            
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends