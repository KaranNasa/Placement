//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        unordered_map<int,int> m;
        int i=0,j=0,count=0;
        int max1=INT_MIN;
        while(j<N)
        {
            m[fruits[j]]++;
            count++;
            if(m.size()<=2)
            {
                max1=max(max1,count);
                j++;
            }
            else{
                while(m.size()>2)
                {
                    m[fruits[i]]--;
                    count--;
                    if(m[fruits[i]]==0)
                        m.erase(fruits[i]);
                    
                    i++;
                }
                j++;
            }
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
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends