//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans;
        vector<int> grp1;
        vector<int> grp2;
        int xor_ans=0;
        for(int i=0;i<nums.size();i++)
        {
            xor_ans=xor_ans ^ nums[i];
        }
        int rsb_mask = (xor_ans & -xor_ans);
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i] & rsb_mask)==0)
                grp2.push_back(nums[i]);
            else
                grp1.push_back(nums[i]);
        }
        
        int val1=0,val2=0;
        for(int i=0;i<grp2.size();i++)
            val2=val2^grp2[i];
        
        for(int i=0;i<grp1.size();i++)
            val1=val1^grp1[i];
        
        if(val1>val2)
        {
            ans.push_back(val2);
            ans.push_back(val1);
            
        }
        else{
            ans.push_back(val1);
            ans.push_back(val2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends