//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse_list(struct node *curr_head)
    {
        struct node *prev=NULL,*curr=curr_head;
        while(curr!=NULL)
        {
            struct node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(k==1)
        {
            return head;
        }
        int count=0;
        struct node *p=head;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        
        struct node *dummy=new node(-1);
        struct node *curr_dummy=dummy;
        
        while(head!=NULL)
        {
            p=head;
            int curr_count=k;
            curr_count--;
            struct node *q=head;
            while(curr_count)
            {
                if(p->next==NULL)
                    break;
                    
                curr_count--;
                p=p->next;
            }
            head=p->next;
            p->next=NULL;   // remove if not needed
            struct node *reverse_list_1=reverse_list(q);
            
            curr_dummy->next=reverse_list_1;
            while(curr_dummy->next!=NULL)
                curr_dummy=curr_dummy->next;
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends