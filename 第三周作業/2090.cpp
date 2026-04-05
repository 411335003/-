class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
       long long windowSize=(long long)k*2+1;
        int n = nums.size();
        long long windowSum=0;
        vector<int> ans(n,-1);
        if(nums.size()==0)return {};
        if (n < windowSize) return ans;
        for (int i = 0; i < windowSize;i++) 
        {
            windowSum += nums[i];
        }
        ans[k] = windowSum / windowSize;
        for (int i = windowSize; i < n; ++i)
        {
            windowSum += nums[i] - nums[i - windowSize];
            ans[i - k] = windowSum / windowSize;
        }
        return ans;
    }
};