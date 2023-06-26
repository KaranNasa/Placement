//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool check_value(vector<int> v,int m,int x)
    {
        int s=0,e=m-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(v[mid]==x)
                return true;
            else if(v[mid]>x)
                e=mid-1;
            else
                s=mid+1;
        }
        return false;
    }
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        
        for(int i=0;i<n;i++){
            if(check_value(matrix[i],m,x))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends