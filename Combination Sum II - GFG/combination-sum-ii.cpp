//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int index,int n,int curr_sum,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &curr_ans,int &target)
    {
        if(curr_sum == target){
            ans.push_back(curr_ans);
            return;
        }
        
        if(curr_sum > target || index==n)
            return;
        
        if(curr_sum + candidates[index] <= target){
            curr_ans.push_back(candidates[index]);
            solve(index+1,n,curr_sum+candidates[index],candidates,ans,curr_ans,target);
            curr_ans.pop_back();
        }
        
        // not pick
        while(index+1<n and candidates[index] == candidates[index+1])
            index++;
        
        solve(index+1,n,curr_sum,candidates,ans,curr_ans,target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        
        sort(candidates.begin(),candidates.end());
        int curr_sum=0,n=candidates.size();
        vector<vector<int>> ans;
        vector<int> curr_ans;
        solve(0,n,curr_sum,candidates,ans,curr_ans,target);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends