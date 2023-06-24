//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    void sum_ans(int &sum1,int &sum2,const vector<vector<int>> &matrix,int n,bool check)
    {
        // if check==true then upper diagonal elements
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check and i<=j)
                    sum1+=matrix[i][j];
                
                if(!check and i>=j)
                    sum2+=matrix[i][j];
                
            }
        }
    }
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        vector<int> ans;
        int sum1=0,sum2=0;
        
        sum_ans(sum1,sum2,matrix,n,true);
        
        sum_ans(sum1,sum2,matrix,n,false);
        
        
        ans.push_back(sum1);
        ans.push_back(sum2);
        
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
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends