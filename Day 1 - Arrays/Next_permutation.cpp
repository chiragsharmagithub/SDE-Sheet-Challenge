// Question link
// https://leetcode.com/problems/next-permutation/

// TC: O(N)
// SC: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        
        // Decrement i, till we get a lesser digit then the preceeding one
        // 47568, 4 is less than 7
        while(i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        if(i >=0 ) {
            int j=nums.size() - 1;
            // finding the element just greater than ith element (that is 4 in the above example)
            while(nums[j] <= nums[i]) {
                j--;
            }
            // element 4 and 5 are swapped
            swap(nums, i, j);
        }
        // reverse the array after the swapped elemnt (that is swap elements 5, starting with 7)
        reverse(nums, i+1);
    }
    
    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while(i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};