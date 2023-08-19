//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies,candies+n);
        int min_val=0,total_candies=0;
        for(int i=0;i<n;i++){
            min_val+=candies[i];
            total_candies++;
            total_candies+=k;
            
            if(total_candies >= n)
                break;
        }
        
        int max_val=0;
        total_candies=0;
        for(int i=n-1;i>=0;i--){
            max_val+=candies[i];
            total_candies++;
            total_candies+=k;
            
            if(total_candies >= n)
                break;
        }
        
        return {min_val,max_val};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends