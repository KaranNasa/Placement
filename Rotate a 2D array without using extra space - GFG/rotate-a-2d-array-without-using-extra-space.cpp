//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	    
	    // take tranpose of a matrix and then swap the first and last row and so onn until we reach the middle row
	    
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(arr[i][j],arr[j][i]);
        }	    
        
        int i=0,j=n-1;
        while(i<=j){
            for(int k=0;k<n;k++)
                swap(arr[i][k],arr[j][k]);
            
            i++;
            j--;
        }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends