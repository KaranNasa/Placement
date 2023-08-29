//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node *prev=NULL,*curr=head;
        while(curr!=NULL){
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL)
            return head;
        
        Node *new_head=reverse(head);
        
        stack<int> s;
        Node *dummy=new Node(-1);
        dummy->next=new_head;
        
        Node *ptr=dummy;
        
        Node *p=new_head;
        
        ptr->next=p;
        ptr=ptr->next;
        s.push(p->data);
        
        p=p->next;
        
        while(p!=NULL){
            if(p->data < s.top())
            {
                // nothing
            }
            else{
                while(!s.empty() and p->data >= s.top())
                    s.pop();
                
                if(s.empty()){
                    ptr->next=p;
                    ptr=ptr->next;
                }
                s.push(p->data);
                
            }
            p=p->next;
            // s.push(p->data);
        }
        
        ptr->next=NULL;
        return reverse(dummy->next);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends