//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    void solve(vector<int> &person,int n,int k,int index,int &ans)
    {
        if(person.size()==1){
            ans=person[0];
            return;
        }
        
        index=(index+k)%person.size();
        
        person.erase(person.begin() + index);
        
        solve(person,n,k,index,ans);
    }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> person(n);
       for(int i=0;i<n;i++)
        person[i]=i+1;
    
       int index=0,ans=-1;
       k--;
       solve(person,n,k,index,ans);
       
       return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends