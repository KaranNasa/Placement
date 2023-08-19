//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        // value/weight should be high
        double val1=(double)a.first/(double)a.second;
        double val2=(double)b.first/(double)b.second;
    
        return val1 > val2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
            vec.push_back({arr[i].value,arr[i].weight});
        
        sort(vec.begin(),vec.end(),comp);
        
        double profit=0;
        int i=0;
        while(W>0 and i<n){
            if(vec[i].second <= W){
                profit+=vec[i].first;
                W-=vec[i].second;
            }
            else{
                if(W!=0){
                    double value_weight=(double)(vec[i].first)/(double)(vec[i].second);
                    profit+=(value_weight * W);
                    W=0;
                }
            }
            i++;
        }
        
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends