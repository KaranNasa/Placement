//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    class disjointset{
        public:
            vector<int> parent,size;
            disjointset(int n)
            {
                parent.resize(n+1);
                size.resize(n+1);
                for(int i=0;i<=n;i++){
                    parent[i]=i;
                    size[i]=1;
                }
            }
            
            int findparent(int node)
            {
                if(node==parent[node])
                    return node;
                else
                    return parent[node]=findparent(parent[node]);
            }
            
            void unionbysize(int u,int v)
            {
                int p_u=findparent(u);
                int p_v=findparent(v);
                
                if(p_u == p_v)
                    return;
                
                if(size[p_u] > size[p_v]){
                    parent[p_v]=p_u;
                    size[p_u]+=size[p_v];
                }
                else{
                    parent[p_u]=p_v;
                    size[p_v]+=size[p_u];
                }
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
        // 1 create a map to map the email to the particular node index
        int n=accounts.size();
        unordered_map<string,int> mapMailNode;
        // sort(accounts.begin(),accounts.end());
        
        disjointset ds(n);
        
        for(int i=0;i<n;i++){
            // mail start from 1 index
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
                    ds.unionbysize(mapMailNode[mail],i);
                }
            }
        }
        
        // 2 Now we need to merge the mail that belong to the same list
        vector<string> mergeMail[n];
        for(auto itr:mapMailNode){
            string mail=itr.first;
            int node=itr.second;
            
            int parent_node=ds.findparent(node);
            
            mergeMail[parent_node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)
                continue;
            
            sort(mergeMail[i].begin(),mergeMail[i].end());
            
            vector<string> curr_ans;
            curr_ans.push_back(accounts[i][0]);
            
            for(auto itr:mergeMail[i]){
                curr_ans.push_back(itr);
            }
            ans.push_back(curr_ans);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends