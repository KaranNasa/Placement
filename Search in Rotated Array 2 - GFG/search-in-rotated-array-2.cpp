//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
        // Code here
        
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e)
        {
            int mid = s + (e-s) / 2;
            if (nums[mid] == target)
                return true;
			
            if((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
            {
                s++;
                e--;
            }
			else if(nums[s] <= nums[mid])
            {
				 if((nums[s] <= target) && (nums[mid] > target))
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {
                if((nums[mid] < target) && (nums[e]>= target))
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends