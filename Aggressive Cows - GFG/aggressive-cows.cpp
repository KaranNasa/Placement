//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool place_cows(vector<int> &stalls,int n,int k,int min_distance)
    {
        int count_cow=1,prev_cow_stall=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i] - prev_cow_stall >= min_distance){
                count_cow++;
                prev_cow_stall=stalls[i];
            }
            
            if(count_cow==k)
                return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int ans=-1;
        int s=1,e=stalls[n-1];
        while(s<=e){
            int mid=s+(e-s)/2;
            bool check=place_cows(stalls,n,k,mid);
            
            // cout<<mid<<" "<<check<<endl;
            if(check){
                ans=mid;
                s=mid+1;
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