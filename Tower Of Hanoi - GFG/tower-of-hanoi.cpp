//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long count=0;
    void TOH(int N,int src,int dst ,int aux)
    {
        if(N==0)
            return;
        
        TOH(N-1,src,aux,dst);
        cout<<"move disk "<<N<<" from rod "<<src<<" to rod "<<dst<<endl;
        count++;
        TOH(N-1,aux,dst,src);
    }
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        TOH(N,from,to,aux);
        return count;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends