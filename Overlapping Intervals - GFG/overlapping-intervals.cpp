//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>> mergedIntervals;
         if(intervals.size()==0)
            return mergedIntervals;
            
         sort(intervals.begin(),intervals.end());
         vector<int> curr_interval=intervals[0];
         
         for(int i=1;i<intervals.size();i++){
             if(intervals[i][0] <= curr_interval[1]){
                 curr_interval[1]=max(curr_interval[1],intervals[i][1]);
             }
             else{
                 mergedIntervals.push_back(curr_interval);
                 curr_interval=intervals[i];
             }
         }
         
         // place the last interval as well
         mergedIntervals.push_back(curr_interval);
         return mergedIntervals;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends