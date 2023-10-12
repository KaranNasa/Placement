//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insert_position(stack<int> &s,int elem)
{
    if(s.empty() || elem > s.top()){
        s.push(elem);
        return;
    }
    int top_elem=s.top();
    s.pop();
    insert_position(s,elem);
    s.push(top_elem);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
    return;
   
   int elem=s.top();
   s.pop();
   sort();
   insert_position(s,elem);
}