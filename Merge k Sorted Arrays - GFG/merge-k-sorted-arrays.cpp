//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class compare{
    public:
        bool operator()(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
            return a.second.second > b.second.second;
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        int n=arr.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        for(int i=0;i<K;i++){
            pq.push({i,{0,arr[i][0]}});
        }
        
        vector<int> ans;
        while(!pq.empty()){
            int vec_no=pq.top().first;
            int elem_no=pq.top().second.first;
            int elem=pq.top().second.second;
            // cout<<vec_no<<" "<<elem_no<<" "<<elem<<endl;
            pq.pop();
            
            ans.push_back(elem);
            
            if(elem_no+1<arr.size()){
                // cout<<arr[vec_no][elem_no+1]<<endl;
                pq.push({vec_no,{elem_no+1,arr[vec_no][elem_no+1]}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends