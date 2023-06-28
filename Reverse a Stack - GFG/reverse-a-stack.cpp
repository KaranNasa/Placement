//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert(stack<int> &St,int insert_elem)
    {
        // Base Case
        if(St.empty())
        {
            St.push(insert_elem);
            return;
        }
        // Hypothesis
        int top_elem=St.top();
        St.pop();
        insert(St,insert_elem);
        
        // Induction
        St.push(top_elem);
    }
    void reverse_stack(stack<int> &St)
    {
        // Base Case
        if(St.size()==1)
            return;
        
        // Hypothesis - reduce the size of the stack
        int top_elem=St.top();
        St.pop();
        reverse_stack(St);
        
        // Induction - top_elem ko wapis insert karna hai
        insert(St,top_elem);
        
    }
    void Reverse(stack<int> &St){
        reverse_stack(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends