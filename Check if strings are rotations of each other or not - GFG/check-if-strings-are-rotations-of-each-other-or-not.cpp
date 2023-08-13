//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool check(string s1,string s2)
    {
        int n=s1.length(),m=s2.length();
        for(int i=0;i<n-m;i++){
            string str2=s1.substr(i,m);
            if(str2==s2)
                return true;
        }
        return false;
    }
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length())
            return false;
        
        s1=s1+s1;
        return check(s1,s2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends