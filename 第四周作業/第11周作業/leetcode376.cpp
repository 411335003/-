class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();  
        int front = 0;
        int curr= 0;
        int count = 1; 
        for (int i = 0; i < nums.size() - 1; i++) {
            curr = nums[i + 1] - nums[i];
            if ((front <= 0 && curr > 0) || (front >= 0 && curr < 0)) {
                count++;
                front = curr; 
            }
        }
        return count;
    }
};