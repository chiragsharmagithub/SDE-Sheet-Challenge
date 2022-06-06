// Question link
// https://leetcode.com/problems/maximum-subarray/


/*
Logic: 

Here, we are having 2 variable, first is currentSubarray which will have the 
current best sum of an subarray at any point while traversing.
Second variable is maxSubarray which will have the maximun sun of all the subarrays.
MaxSubarray is having the best (max) of current subarray and itself.

While traversing, we will check if the sum of current subarray's sum (currentSubarray + num) is greater or the current element
Whosoever is greater, we will have currentSubarray = max(xurrentSubarray + num, num)

then will have the best (max) of current sum of subarray (or currentSubarray) and previous best sum (maxSubarray)
maxSubarray = max(maxSubarray, currentSubarray) 
*/


// DP Kadane's Algo
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarray = nums[0];
        int currentSubarray = nums[0];
        int numsSize = nums.size();
        
        for(int i = 1; i < numsSize ; i++) {
            int num = nums[i];
            currentSubarray = max(currentSubarray + num, num);
            maxSubarray = max(currentSubarray, maxSubarray);
        }
        return maxSubarray;
    }
};