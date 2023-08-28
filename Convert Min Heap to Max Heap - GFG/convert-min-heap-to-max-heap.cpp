//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void heapify(vector<int> &arr,int i,int n)
    {
        int li=2*i+1,ri=2*i+2;
        int largest=i;
        
        if(li<n and arr[li] > arr[largest])
            largest=li;
        
        if(ri<n and arr[ri] > arr[largest])
            largest=ri;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,largest,n);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n){
        for(int i=(n-2)/2;i>=0;i--)
            heapify(arr,i,n);
            
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends