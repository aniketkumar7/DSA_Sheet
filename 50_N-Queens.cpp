// Question: N-Queens
// Question link: https://leetcode.com/problems/n-queens/

// Problem Statement:
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

// Solution Approach:
// We will use backtracking to solve this problem. We will place the queens one by one in different columns and check if the current position is safe or not. If the position is safe, we will place the queen and move to the next column. If the position is not safe, we will backtrack and try the next position in the current column. We will keep doing this until we have placed all the queens on the board.

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n){
    // check if there is a queen in the same column
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // check if there is a queen in the upper left diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // check if there is a queen in the upper right diagonal
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<string> &board, int row, vector<vector<string>> &res, int n){
    if(row >= n){
        res.push_back(board);
        return;
    }

    for(int col=0; col<n; col++){
        if(isSafe(board, row, col, n)){
            board[row][col] = 'Q';
            solveNQueens(board, row+1, res, n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin>>n;

    if(n<=3){
        cout<<"Not possible"<<endl;
        return 0;
    }
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    solveNQueens(board, 0, res, n);

    cout << "All distinct solutions to the n-queens puzzle: " << endl;
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}