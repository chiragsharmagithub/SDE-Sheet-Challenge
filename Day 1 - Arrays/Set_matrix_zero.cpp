// Question link 
// https://leetcode.com/problems/set-matrix-zeroes/


// Problem statement(brief): 
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Cpp code:

// Chirag
// TC: O(N * M)
// SC: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int numRows = matrix.size();
        int numColumns = matrix[0].size();
        int isFirstColumnZero = 1; // This variable isFirstColumnZero = 0, means that there is a cell in first column whose value is zero
        
        for(int i=0; i<numRows; i++) {
            if(matrix[i][0] == 0) {
                isFirstColumnZero = 0;
            }
            
            // We are traversing from j = 1, because we will take care of the first column later
            
            for(int j=1; j<numColumns; j++) {
                // Setting the first cell of row (i) and column (j) to be zero
                // If there is a zero in that particular row , and column. That is if matrix[i][j] == 0
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
     // Now we will set the value of matrix cells to zero if the first 
    // cell in row or column is zero (except for first column and first row)
    // Will set the cell values of first row and first column later.
        for(int i=1; i<numRows; i++) {
            for(int j=1; j<numColumns; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Check if there is any cell whose value is zero in first row
    // If yes, then set all the cell of first row to be zero
        if(matrix[0][0] == 0) {
            for(int j=0; j<numColumns; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Check if there is any cell whose value is zero in first cell
    // If yes, then set all the cells of first column to be zero
        if(isFirstColumnZero == 0) {
            for(int i=0; i<numRows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};