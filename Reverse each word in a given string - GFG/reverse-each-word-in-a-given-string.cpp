//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverse_string(stack<char> &st)
    {
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    string reverseWords (string s)
    {
        //code here.
        string ans="";
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                // reverse the content of stack
                string curr_ans=reverse_string(st);
                ans+=curr_ans;
                ans+='.';
            }
            else{
                st.push(s[i]);
            }
        }
        if(!st.empty())
        {
            string curr_ans=reverse_string(st);
            ans+=curr_ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends