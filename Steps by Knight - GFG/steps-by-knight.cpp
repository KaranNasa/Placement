//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    KnightPos[0]=KnightPos[0]-1;
	    KnightPos[1]=KnightPos[1]-1;
	    
	    TargetPos[0]=TargetPos[0]-1;
	    TargetPos[1]=TargetPos[1]-1;
	    
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    
	    // perform BFS
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    
	    int count=0;
	    
	    int new_x[8]={-2,-2,-1,1,2,2,1,-1};
	    int new_y[8]={-1,1,2,2,1,-1,-2,-2};
	    
	    
	    while(!q.empty()){
	        int size=q.size();
	        while(size--){
    	        int x=q.front().first;
    	        int y=q.front().second;
    	        
    	        q.pop();
    	        
    	        if(x==TargetPos[0] and y==TargetPos[1])
    	            return count;
    	           
    	       for(int k=0;k<8;k++){
    	           int val_x=x+new_x[k];
    	           int val_y=y+new_y[k];
    	           
    	           if(val_x >= 0 and val_x < N and val_y>=0 and val_y < N){
    	               if(!vis[val_x][val_y]){
    	                   vis[val_x][val_y]=1;
    	                   q.push({val_x,val_y});
    	               }
    	           }
    	       }
	        }
	        count++;
	    }
	    
	    return -1;  // not possible
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends