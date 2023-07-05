//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        set<int> s;
        unordered_map<char,int> m;
        int n=str.length();
        for(int i=0;i<n;i++){
           s.insert(str[i]);
        }
        
        int unique_characters=s.size();
        // m.clear();
        
        int length_win=str.length();
        
        int i=0,j=0;
        
        while(j<n){
            m[str[j]]++;
            if(m.size()==unique_characters){
                while(m[str[i]]>1){
                    m[str[i]]--;
                    i++;
                }
                
                length_win=min(length_win,j-i+1);
            }
            j++;
        }
        
        return length_win;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends