//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int row,int col,int board[N][N],int c)
    {
        for(int i=0;i<9;i++)
        {
            //Checking for row
            if(board[row][i]==c)
                return false;
            
            //Checking for col
            if(board[i][col]==c)
                return false;
            
            //Checking for 3x3 box
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(int board[N][N])
    {
        //At first we try to find the empty cell
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]==0)
                {
                    //Found an empty cell. Now we try to fill it with number from 1-9. Remember we need to fill it                       // with char
                    for(int ch=1;ch<=9;ch++)
                    {
                        if(isSafe(i,j,board,ch))
                        {
                            board[i][j]=ch;
                            if(solve(board)==true)    //This is for next recursion
                                return true;
                            
                            else
                                board[i][j]=0;    // If next recursion return false then we need to replace this                                                       // cell with some other number
                        }
                    }
                    return false;   //If we are not able to place any number 
                }
            }
        }
        return true;    //The function will return true only when all the number are being placed in cells.
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
         bool ans=solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends