//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size(),m=matrix[0].size();
        int count_val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int count_zero=0;
                    int new_x[]={-1,-1,-1,0,0,1,1,1};
                    int new_y[]={-1,0,1,-1,1,-1,0,1};
                    for(int k=0;k<8;k++){
                        int newr=i+new_x[k];
                        int newc=j+new_y[k];
                        
                        if(newr>=0 and newr<n and newc>=0 and newc<m){
                            if(matrix[newr][newc]==0)
                                count_zero++;
                        }
                    }
                    
                    if(count_zero!=0 and count_zero%2==0)
                        count_val++;
                }
            }
        }
        
        return count_val;
        
        // TC: O(8*n*m)
        // SC: O(1)
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends