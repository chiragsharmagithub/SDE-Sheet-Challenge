// Question link
// https://leetcode.com/problems/sort-colors/

/*
Logic,

If the current element (start with 0th index) is == 0, then swap with the start (supposed to be zeroth element)
and increment both start and current indices.
and if the current element is == 2, then swap with the nums[end] element, and decrement end.

else current element == 1, simply increment the current variable.
*/

// TC: O(N)
// SC: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsSize = nums.size();        
        int start = 0, current = 0, end = numsSize-1;
        
        while(current <= end) {
            if(nums[current] == 0) {
                swap(nums[start], nums[current]);
                start++;
                current++;
            }
            else if(nums[current] == 2) {
                swap(nums[current], nums[end]);
                end--;
            }
            else {
                current++;
            }
        }
    }
};