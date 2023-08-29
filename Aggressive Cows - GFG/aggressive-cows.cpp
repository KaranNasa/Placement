//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool place_cows(int n,vector<int> &stalls,int max_cows,int min_distance)
    {
        // at first, the first cow will always be placed at 0th index
        int curr_count_cow=1,last_cow_postion=stalls[0];
        
        for(int i=1;i<n;i++){
            if(stalls[i] - last_cow_postion >= min_distance){
                curr_count_cow++;
                last_cow_postion=stalls[i];
            }
            
            if(curr_count_cow == max_cows)
                return true;
        }
        
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        
        int maxi=-1;
        for(auto itr:stalls)
            maxi=max(maxi,itr);
        
        int s=1,e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;  // mid will define the minimum distance between any 2 consecutive cows
            
            if(place_cows(n,stalls,k,mid)){
                ans=mid;
                s=mid+1;    // since we want max hence
            }
            else{
                e=mid-1;
            }
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