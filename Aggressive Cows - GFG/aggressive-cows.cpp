//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool can_place_cows(int n,int max_cows,vector<int> &stalls,int min_distance)
    {
        int curr_cow=1,last_cow_position=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i] - last_cow_position >= min_distance){
                curr_cow++;
                last_cow_position=stalls[i];
            }
            if(curr_cow == max_cows)
                return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        // at first sort the array
        sort(stalls.begin(),stalls.end());
        
        int mini=-1;
        for(auto itr:stalls)
            mini=max(mini,itr);
        
        int s=1,e=mini;
        int ans=-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(can_place_cows(n,k,stalls,mid)){
                ans=mid;
                s=mid+1;    // since we want max distance
            }
            else
                e=mid-1;
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