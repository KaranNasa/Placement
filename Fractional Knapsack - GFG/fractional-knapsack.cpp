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
        double val1=(double)a.first/(double)a.second;
        double val2=(double)b.first/(double)b.second;
        
        return val1>val2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(p.begin(),p.end(),comp);
        
        double cost=0;
        for(int i=0;i<n;i++)
        {
            if(W>=p[i].second)
            {
                cost+=p[i].first;
                W-=p[i].second;
            }
            else{
                double weight_1_unit=(double)p[i].first/(double)p[i].second;
                cost+=(weight_1_unit)*W;
                break;
            }
        }
        return cost;
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