//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            
            // first count the number of dot. It should be 3 for a valid ip address
            int n=s.length(),count=0;
            for(int i=0;i<n;i++){
                if(s[i]=='.')
                    count++;
            }
            if(count != 3)
                return 0;
            
            unordered_set<string> st;
            for(int i=0;i<256;i++)
                st.insert(to_string(i));
                
            int counter=0;
            string temp="";
            
            for(int i=0;i<n;i++){
                if(s[i] != '.')
                    temp+=s[i];
                else{
                    if(st.find(temp)!=st.end())
                        counter++;
                    
                    temp="";
                }
            }
            
            if(st.find(temp)!=st.end())
                        counter++;
                        
            if(counter==4)
                return 1;
            else
                return 0;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends