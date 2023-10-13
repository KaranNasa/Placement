//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
long long treePathsSum(Node *root);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		
        cout<<treePathsSum(root);
   		cout<<endl;
  }
  return 0;
}

// } Driver Code Ends


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
long long convert_sum(vector<int> path)
{
    // for(auto itr:path)
    //     cout<<itr<<" ";
    // cout<<endl;
    int n=path.size()-1;
    long long res=0;
    for(auto itr:path){
        res+=(itr*pow(10,n));
        n--;
    }
    return res;
}
void solve(Node *root,vector<int> path,long long &sum)
{
    if(root==NULL)
        return;
     path.push_back(root->data);
    if(root->left==NULL and root->right==NULL){
        // path.push_back(root->data);
        sum+=convert_sum(path);
        return;
    }
    
    // path.push_back(root->data);
    solve(root->left,path,sum);
    solve(root->right,path,sum);
    path.pop_back();
}
long long treePathsSum(Node *root)
{
    //Your code here
    long long sum=0;
    if(root==NULL)
        return sum;
    if(root->left==NULL and root->right==NULL)
        return root->data;
    
    vector<int> path;
    solve(root,path,sum);
    return sum;
}
