//Daa-5
// Title :- Design n-Queens matrix having first Queen placed. 
//Use backtracking to place remaining Queens to generate the final n-queen‘s matrix.

//......python............

global N
N = 4

def printSolution(board):
    for i in range(N):
        for j in range(N):
            print (board[i][j], end = " ")
        print()

def isSafe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i,j in zip(range(row, -1, -1),range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i,j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    return True

def solveNQUtil(board, col):
    if col >= N:
        return True

    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            if solveNQUtil(board, col+1) == True:
                return True
            board[i][col] = 0
    return False

def solveNQ():
    board = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    if solveNQUtil(board, 0) == False:
        print("Solution does not exist")
        return False
    printSolution(board)
    return True

solveNQ()



//....................c++........................
#include <bits/stdc++.h> 
#define N 4
using namespace std;

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j]){
                cout << "1 "; 
            }
            else{ 
                cout<<". ";
            }
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col){
    int i, j;
    for (i = 0; i < col; i++){ 
        if (board[row][i]){ 
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j]){
            return false;
        }
    }
    for (i = row, j = col; j >= 0 && i < N; i++, j--){
        if (board[i][j]){
            return false; 
        }
    }
    return true;
}
    
bool solveNQUtil(int board[N][N], int col){
    if (col >= N){ 
        return true;
    }
    for (int i = 0; i < N; i++) { 
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1)) {
                return true;
            }
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ(){
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
                        
    if (solveNQUtil(board, 0) == false) { 
        cout << "Solution does not exist"; 
        return false;
    }
    printSolution(board); 
    return true;
}

int main(){
    solveNQ(); return 0;
}

