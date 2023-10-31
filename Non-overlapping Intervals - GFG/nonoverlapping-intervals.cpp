//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        
        sort(intervals.begin(),intervals.end(),comp);
        
        int count=0,end_time=intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= end_time)
                end_time=intervals[i][1];
            else
                count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends