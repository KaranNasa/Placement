//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newInterval) {
        // code here
        
         vector<vector<int>> ans;
        // int n=intervals.size();
        // Step-1: intervals with start time < newInterval[0]. Insert them into ans
        int idx=0;
        while(idx < n){
            if(intervals[idx][0] < newInterval[0]){
                ans.push_back(intervals[idx]);
                idx++;
            }
            else
                break;
        }

       
        // Step-2 insert the new interval

        if(ans.size() == 0 || newInterval[0] > ans[ans.size()-1][1])   // case of no merging
            ans.push_back(newInterval);
        else{
            // here we have merging
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],newInterval[1]);
        }



        // step-3 Now insert the remaining elements. It may happen that an overlap exist
        while(idx<n){
            vector<int> last_interval=ans[ans.size()-1];
            if(last_interval[1] >= intervals[idx][0])
            {
                // merging
               ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[idx][1]);
            }
            else{
                ans.push_back(intervals[idx]);
            }
            idx++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends