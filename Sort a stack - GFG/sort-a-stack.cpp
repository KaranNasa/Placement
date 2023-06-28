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
void insert(stack<int> &s,int top_elem)
{
    // Base-Case
    if(s.size()==0 || s.top()<=top_elem)
    {
        s.push(top_elem);
        return;
    }
    // Hypothesis
    int elem=s.top();
    s.pop();
    insert(s,top_elem);
    
    //Induction - pop element usse wapis stack mai daal do
    
    // joo yahaan pop out hue honge woh basically woh element honge joo top_elem se bade hai
    
    s.push(elem);
}
void sort1(stack<int> &s)
{
    // Base-Case
    if(s.size()==1)
        return;
    
    //Hypothesis
    int top_elem=s.top();
    s.pop();
    sort1(s);
    
    // Induction - insert the pop element back into the stack into the currect position
    insert(s,top_elem);
    
}
void SortedStack :: sort()
{
   //Your code here
   sort1(s);
   
}