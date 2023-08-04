//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> lis1(n,1);
	    vector<int> lis2(n,1);
	    
	    // from front
	    for(int index=0;index<n;index++){
	        for(int prev_index=0;prev_index<index;prev_index++){
	            if(nums[index] > nums[prev_index] and lis1[prev_index] + 1 > lis1[index]){
	                lis1[index]=lis1[prev_index] + 1;
	            }
	        }
	    }
	    
	    // for backward array
	    for(int index=n-1;index>=0;index--){
	        for(int prev_index=n-1;prev_index>index;prev_index--){
	            if(nums[index] > nums[prev_index] and lis2[prev_index] + 1 > lis2[index]){
	                lis2[index]=lis2[prev_index] + 1;
	            }
	        }
	    }
	    
	    // combine the 2 and then get the max from them
	    int max1=-1;
	    for(int i=0;i<n;i++){
	        max1=max(max1,lis1[i] + lis2[i] - 1);
	    }
	    
	    return max1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends