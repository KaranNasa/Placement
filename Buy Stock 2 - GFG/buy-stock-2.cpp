//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        // int n=prices.size();
        vector<long long> ahead(2,0),curr(2,0);

        ahead[0]=ahead[1]=0;

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){

                if(buy){
                    curr[buy]=max(-prices[index]+ahead[0], ahead[1]);
                }
                else{
                    curr[buy]=max(prices[index]+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }

        return ahead[1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends