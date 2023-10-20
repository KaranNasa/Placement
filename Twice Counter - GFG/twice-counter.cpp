//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
           unordered_map<string,int> m;
           int count=0;
           for(int i=0;i<n;i++){
               if(m[list[i]]!=-1)
                m[list[i]]++;
               
               if(m[list[i]]==2)
                    count++;
               else if(m[list[i]]>2){
                    count--;
                    m[list[i]]=-1;
               }
           }
           return count;
        }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends