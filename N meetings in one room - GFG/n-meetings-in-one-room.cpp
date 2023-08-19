//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        // sort based on end-time
        if(a.second==b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if(n==0)
            return 0;
            
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int end_time=vec[0].second;
        int count=1;
        for(int i=1;i<n;i++){
            if(vec[i].first > end_time){
                count++;
                end_time=vec[i].second;
            }
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends