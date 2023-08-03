//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert_into_stack(stack<int> &st,int elem)
    {
        if(st.empty()){
            st.push(elem);
            return;
        }
        
        int top_elem=st.top();
        st.pop();
        insert_into_stack(st,elem);
        
        st.push(top_elem);
    }
    void solve(stack<int> &st)
    {
        if(st.empty())
            return;
        
        int elem=st.top();
        st.pop();
        
        solve(st);
        
        insert_into_stack(st,elem);
    }
    void Reverse(stack<int> &St){
        solve(St);
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