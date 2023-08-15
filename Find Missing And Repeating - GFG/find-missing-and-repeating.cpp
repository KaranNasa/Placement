//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        int xor_ans=0;
        for(int i=1;i<=n;i++)
            xor_ans^=i;
        
        for(int i=0;i<n;i++)
            xor_ans^=arr[i];
        
        int rsb_mask=(xor_ans & -xor_ans);
        
        int val1=0,val2=0;
        for(int i=0;i<n;i++){
            if((arr[i] & rsb_mask)!=0)
                val1^=arr[i];
            else
                val2^=arr[i];
        }
        for(int i=1;i<=n;i++){
            if((i & rsb_mask)!=0)
                val1^=i;
            else
                val2^=i;
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == val1)
                count++;
        }
        if(count==2){
            return {val1,val2};
        }
        else
            return {val2,val1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends