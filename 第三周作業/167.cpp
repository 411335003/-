class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto start=numbers.begin();　//指向vecter第一個
        auto last=numbers.end()-1;  //指向vector最後一個
        vector<int>ans; //存答案的索引號
        while(start<last) 
        {
            int sum=*start+*last; //值相加
            if(sum>target)last--; //sum>target->左移
            else if(sum<target) start++; //sum<target->右移
            else //sum=target
            { //找索引號
                ans.push_back(distance(numbers.begin(), start)+1); 
                ans.push_back(distance(numbers.begin(),last)+1);
                return ans;
            } 
        }
        return {};
    }
};