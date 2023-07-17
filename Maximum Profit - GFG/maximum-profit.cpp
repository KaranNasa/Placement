//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int n, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(K+1,0)));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=K;k++){
                    if(buy){
                        dp[index][buy][k]=max(-A[index]+dp[index+1][0][k],dp[index+1][1][k]);
                    }
                    else{
                        dp[index][buy][k]=max(A[index]+dp[index+1][1][k-1],dp[index+1][0][k]);
                    }
                }
            }
        }
        
        return dp[0][1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends