//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        unordered_map<char,int> m;
        int n=str.length();
        
        for(int i=0;i<n;i++)
        {
            if(str[i]>='A' and str[i]<='Z')
            {
                char ch=tolower(str[i]);
                m[ch]++;
            }
            else if(str[i]>='a' and str[i]<='z')
                m[str[i]]++;
        }
        if(m.size()==26)
            return true;
        else
            return false;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends