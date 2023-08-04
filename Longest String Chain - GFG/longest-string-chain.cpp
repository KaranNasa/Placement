//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comp(string &s1,string &s2)
    {
        return s1.length() < s2.length();
    }
    bool check_string(string &s1,string &s2)
    {
        if(s1.length() != s2.length() + 1)
            return false;
        
        int first=0,second=0;
        while(first < s1.length()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;    // probable the new inserted 1 character
            }
        }
        
        if(first==s1.length() and second==s2.length())
            return true;
        else
            return false;
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        
        sort(words.begin(),words.end(),comp);
        
        vector<int> lis(n,1);
        
        int max1=INT_MIN;
        for(int index=0;index<n;index++){
            for(int prev_index=0;prev_index<index;prev_index++){
                if(check_string(words[index],words[prev_index]) and 1+lis[prev_index] > lis[index] ){
                    lis[index]=lis[prev_index]+1;
                }
            }
            
            max1=max(max1,lis[index]);
        }
        
        return max1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends