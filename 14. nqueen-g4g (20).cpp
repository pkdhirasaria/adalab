#include <iostream>

using namespace std;

int flag=0;

void DisplayBoard(int **board,int N)
{
    flag++;
    cout<<"\nSolution of N Queen's problem:\n";
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int CheckSafeBox(int **board,int N,int row,int col)
{
    //check for left row
    for(int j=0;j<col;++j)
        if(board[row][j]==1)
         return 0;

    //check upper left diagonal
    for(int i=row,j=col;i>=0&&j>=0;--i,--j)
        if(board[i][j]==1)
            return 0;

    //check lower left diagonal
    for(int i=row,j=col; i<N && j>=0;++i,--j)
        if(board[i][j]==1)
            return 0;

    return 1;
}

int SolNQueen(int **board,int col,int N)
{

    //base case to check if all queens are placed successfully
    if(col>=N)
        DisplayBoard(board,N);

    for(int i=0;i<N;++i)
    {
        //check if the board[i][col] is safe place to place the queen
        if(CheckSafeBox(board,N,i,col))
        {
            //place the queen
            board[i][col]=1;
            if(SolNQueen(board,col+1,N))
                return 1;

            //if all queen are not placed
            board[i][col]=0;
        }
    }

    return 0;
}

int main()
{
    int N;
    char ch;
    do
    {
    cout<<"Enter the no. Queens :";
    cin>>N;
    int **board=new int*[N];
    for(int i=0;i<N;i++)
        board[i]=new int[N];
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            board[i][j]=0;
    SolNQueen(board,0,N);

    if(!flag)
        cout<<"Solution does not exits";
    else
        cout<<"No. of solution available : "<<flag;


    flag=0;

    cout<<"\nDo you want to continue (Y/N): ";
    cin>>ch;
    }while(ch=='y'||ch=='Y');


    return 0;
}