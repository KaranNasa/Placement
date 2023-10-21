//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int get_flowers(int K,vector<int> &bloomDay,int curr_time,int M)
    {
        int curr_bouquet=0,curr_flower=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= curr_time){
                curr_flower++;
                if(curr_flower==K){
                    curr_bouquet++;
                    curr_flower=0;
                    if(curr_bouquet == M)
                        break;
                }
            }
            else{
                curr_flower=0;
            }
        }
        return curr_bouquet;
    }
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      int n=bloomDay.size();
      int mini=INT_MAX,maxi=INT_MIN;
      for(auto itr:bloomDay){
          mini=min(mini,itr);
          maxi=max(maxi,itr);
      }
      
      int s=mini,e=maxi;
      int ans=-1;
      while(s<=e){
          int mid=s+(e-s)/2;
          int flowers_made=get_flowers(K,bloomDay,mid,M);
        //   cout<<mid<<" "<<flowers_made<<endl;
          if(flowers_made == M){
              ans=mid;
              e=mid-1;
          }
          else
            s=mid+1;
          
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends