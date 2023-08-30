//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    bool check(int num)
    {
        vector<int> check(10,0);
        int c=num;
        while(c!=NULL){
            int last=c%10;
            c=c/10;
            if(check[last]==1)
                return false;
            else
                check[last]=1;
        }
        
        return true;
    }
    vector<int> uniqueNumbers(int L,int R)
    {
        // Write Your Code here
        vector<int> ans;
        for(int i=L;i<=R;i++){
            if(check(i))
                ans.push_back(i);
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
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends