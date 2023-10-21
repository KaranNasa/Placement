//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int n,int k,vector<int> &stalls,int mini_distance)
    {
        int curr_cow_position=stalls[0],cows_placed=1;
        for(int i=1;i<n;i++){
            if(stalls[i] - curr_cow_position >= mini_distance){
                cows_placed++;
                curr_cow_position=stalls[i];
                if(cows_placed==k)
                    break;
            }
        }
        return cows_placed;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        // int mini=INT_MAX,maxi=INT_MIN;
        // for(auto itr:stalls){
        //     mini=min(mini,itr);
        //     maxi=max(maxi,itr);
        // }
        
        int s=1,e=stalls[n-1]-stalls[0];
        int ans=-1;
        while(s<=e){
            int mini_distance=s+(e-s)/2;
            
            int placed_cows=solve(n,k,stalls,mini_distance);
            if(placed_cows == k){
                ans=mini_distance;
                s=mini_distance+1;
            }
            else
                e=mini_distance-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends