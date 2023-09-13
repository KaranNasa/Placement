//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    class node{
        public:
            int i,j,dist;
            node(int x,int y,int z)
            {
                i=x;
                j=y;
                dist=z;
            }
    };
    
    bool check(int x,int y,vector<vector<int>> &vis,int n)
    {
        if(x<0 || x>=n || y<0 || y>=n || vis[x][y])
            return false;
        else
            return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    
	    int new_x[8]={-2,-2,-1,1,2,2,1,-1};
	    int new_y[8]={-1,1,2,2,1,-1,-2,-2};
	    queue<node*> q;
	    vector<vector<int>> vis(N,vector<int>(N,0));
	    
	    // making it 0-based indexing
	    KnightPos[0]=KnightPos[0]-1;
	    KnightPos[1]=KnightPos[1]-1;
	    TargetPos[0]=TargetPos[0]-1;
	    TargetPos[1]=TargetPos[1]-1;
	    
	    
	    node *new_node=new node(KnightPos[0],KnightPos[1],0);
	    q.push(new_node);
	    vis[KnightPos[0]][KnightPos[1]]=1;
	   // vis[KnightPos[0]][KnightPos[1]]=1;
	    
	    while(!q.empty()){
	       // int size=q.size();
	       // while(size--){
    	        int x=q.front()->i;
    	        int y=q.front()->j;
    	        int distance=q.front()->dist;
    	       // vis[x][y]=1;
    	        q.pop();
    	        
    	        if(x==TargetPos[0] and y==TargetPos[1])
    	            return distance;
    	       
    	        for(int k=0;k<8;k++){
    	            int val_x=x+new_x[k];
    	            int val_y=y+new_y[k];
    	            
    	            if(check(val_x,val_y,vis,N)){
    	                node *new_node_add=new node(val_x,val_y,distance+1);
    	                vis[val_x][val_y]=1;
    	                q.push(new_node_add);
    	            }
    	       // }
	        }
	    }
	    return -1;  // if we cannot reach
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