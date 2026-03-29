class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==0) return 0;
        int median_median=0;
        vector<int>median;
        if(n<=5) //小於5個就直接排序
        {
            sort( nums.begin() , nums.end()  );
            return nums[n-k];
        }
        sortvec(nums,0,4,median);
        sort(median.begin(),median.end());
        median_median=median[median.size()/2];
        return group(median_median,nums,k);
    }
    void sortvec(vector<int>& nums,int left, int right,vector<int>& median)
    {
        if(right < nums.size()-1)//如果數量大於等於5就繼續遞迴排序
        {
            sortvec(nums,left+5,right+5,median);
        }
        else
        {
            int remain=nums.size() - (left + 5);
            if(nums.size()%5!=0)
            {
                int start=nums.size()-(nums.size()%5);
                sort(nums.begin()+start,nums.end());
                median.push_back(nums[start+(nums.size()%5-1)/2]);
                return;
            }
        }
        if (left + 4 < nums.size()) {
            sort(nums.begin() + left, nums.begin() + left + 5);
            median.push_back(nums[left + 2]);
            return;
        }
    }
    int group(int median_median,vector<int>& nums,int k)
    {
        vector<int>s1; //<median_median
        vector<int>s2; //=median_median
        vector<int>s3; //>median_median
        for(int num :nums)
        {
            if(num<median_median) s1.push_back(num);
            else if(num==median_median) s2.push_back(num);
            else s3.push_back(num);
        }
        if ( k<=s3.size() )return findKthLargest(s3,k);
        else if ( k<=s3.size()+s2.size())return median_median;
        else return findKthLargest(s1, k - s3.size() - s2.size());
    };
};