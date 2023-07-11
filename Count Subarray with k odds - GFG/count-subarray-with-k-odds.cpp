//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        
        int no_odd=0;
        int count=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0)
                no_odd++;
            
            if(no_odd == k)
                count++;
            
            if(m.find(no_odd - k)!=m.end())
                count+=m[no_odd-k];
            
            m[no_odd]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends