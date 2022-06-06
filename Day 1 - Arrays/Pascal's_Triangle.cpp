// Question link
// https://leetcode.com/problems/pascals-triangle/

// Logic:

/*

In each row, the first and last element will be 1
Other elements, are the sum of previous row's (j)th and (j-1)th elements
Basically, Fundation of DP, we use previous values to evaluate current element's values

result[i][j] = result[i-1][j-1] + result[i-1][j];

*/

// Chirag
// TC: O(N^2)
// SC: O(1)

// where N = numRows
// While O(numRows^2)O(numRows)2
//  ) space is used to store the output, the input and output generally do not count towards the space complexity. 


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int i=0; i<numRows; i++) {
            vector<int> tempArr;
            for(int j=0; j<=i; j++) {
                if(j == 0) {
                    tempArr.push_back(1);
                }
                else if(j == i) {
                    tempArr.push_back(1);
                }
                // This will contain all the elements other than starting and ending element of each row
                else {
                    int sum = result[i-1][j-1] + result[i-1][j];
                    tempArr.push_back(sum);
                }
            }
            result.push_back(tempArr);
        }
        return result;
    }
};


// second code

// TC: O(N^2)
// SC: O(N^2)

// where N = numRows

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++) {
            result[i].resize(i + 1);
            // first and last element of row should be 1.
            result[i][0] = result[i][i] = 1;
  
            // Foundation of DP: Use previously stored results to evaluate the current.
            for (int j = 1; j < i; j++)
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        return result;
    }
};