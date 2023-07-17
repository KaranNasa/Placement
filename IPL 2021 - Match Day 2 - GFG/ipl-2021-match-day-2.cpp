//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
        vector<int> ans;
        deque<int> q;
        int i=0,j=0;
        while(j<n){
            if(q.empty())
                q.push_back(arr[j]);
            else{
                while(!q.empty() and arr[j] > q.back())
                    q.pop_back();
                
                q.push_back(arr[j]);
            }
            if(j-i+1<k)
                j++;
            else if((j-i+1)==k){
                ans.push_back(q.front());
                if(arr[i]==q.front())
                    q.pop_front();
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends