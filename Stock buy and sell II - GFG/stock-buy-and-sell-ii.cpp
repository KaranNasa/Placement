//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0]=0;
        dp[n][1]=0;
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }
                else{
                    dp[index][buy]=max(prices[index]+dp[index+1][1],dp[index+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends