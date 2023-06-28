//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void remove(stack<int> &s,int mid_elem)
    {
        // Base case
        if(mid_elem==0)
        {
            s.pop();
            return;
        }
        // Hypothesis
        int top_elem=s.top();
        s.pop();
        remove(s,mid_elem-1);
        
        // induction
        s.push(top_elem);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int mid_elem=ceil((sizeOfStack+1)/2);
        remove(s,s.size()-mid_elem);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends