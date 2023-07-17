//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int size=q.size();
        vector<int> ans(size);
        
        int i=0,j=1;
        int count_elem_1=0;
        bool iska_bari=true;
        while(!q.empty()){
            int elem=q.front();
            q.pop();
            if(count_elem_1 < (size/2))
            {
                ans[i]=elem;
                i+=2;
                count_elem_1++;
            }
            else
            {
                ans[j]=elem;
                j+=2;
            } 
            // iska_bari=!iska_bari;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends