//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    vector<int> freq(26,0);
		    vector<char> order;
		    
		    int n=A.length();
		    for(int i=0;i<n;i++){
		        
		        if(freq[A[i]-'a']==0){
		            order.push_back(A[i]);
		        }
		        freq[A[i]-'a']++;
		        
		        bool appear_once=false;
		        for(int j=0;j<order.size();j++){
		            if(freq[order[j]-'a']==1){
		                ans+=order[j];
		                appear_once=true;
		                break;
		            }
		        }
		        if(!appear_once)
		            ans+="#";
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends