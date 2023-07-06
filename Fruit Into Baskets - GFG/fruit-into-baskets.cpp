//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        // its basically like i want only 2 types of fruit
        
        unordered_map<int,int> m;
        int i=0,j=0;
        int length_window=0;
        
        // only single fruit is there
        bool single_fruit=true;
        
        while(j<N){
            m[fruits[j]]++;
            if(m.size()<2)
                j++;
            else if(m.size()==2){
                single_fruit=false;
                length_window=max(length_window,j-i+1);
                j++;
            }
            else{
                // m.size() > 3
                // length_window=max(length_window,j-i);
                while(m.size()>2){
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0)
                        m.erase(fruits[i]);
                    
                    i++;
                }
                length_window=max(length_window,j-i+1);
                j++;
            }
        }
        if(single_fruit)
            return N;
        return length_window;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends