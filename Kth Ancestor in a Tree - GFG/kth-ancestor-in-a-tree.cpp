//{ Driver Code Starts
#include <bits/stdc++.h>
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
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

void get_parent(Node *p,unordered_map<Node*,Node*> &parent)
{
    if(p==NULL)
        return;
        
    if(p->left)
        parent[p->left]=p;
    if(p->right)
        parent[p->right]=p;
    
    get_parent(p->left,parent);
    get_parent(p->right,parent);
}

Node *curr=NULL;

void inorder(Node *p,int node)
{
    if(p==NULL)
        return;
    
    // if(p->left)
        inorder(p->left,node);
    
    if(p->data == node){
        curr=p;
        // cout<<curr->data<<endl;
        return;
    }
    // if(p->right)
        inorder(p->right,node);
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    unordered_map<Node*,Node*> parent;
    Node *p=root;
    get_parent(p,parent);
    
    p=root;
    // Node *curr;
    inorder(p,node);
    // cout<<curr->data<<endl;
    // curr store the address of the node with value k
    
    while(k--)
    {
        if(parent.find(curr)!=parent.end()){
            curr=parent[curr];
        }
        else{
            return -1;
        }
    }
    return curr->data;
    
    
}
