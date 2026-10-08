#include<iostream>
#include<vector>

// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组是数组中的一个连续部分。

 

// 示例 1：

// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

// 示例 2：

// 输入：nums = [1]
// 输出：1

// 示例 3：

// 输入：nums = [5,4,-1,7,8]
// 输出：23

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int pre=nums[0];
        int maxsum=pre;
        for(int i=1;i<nums.size();i++){
            pre=std::max(pre+nums[i],nums[i]);
            maxsum=std::max(pre,maxsum);
        }
        return maxsum;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    std::vector<int> nums1={-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "示例1：" << sol.maxSubArray(nums1) << std::endl;

    //case 2
    std::vector<int> nums2={1};
    std::cout << "示例2：" << sol.maxSubArray(nums2) << std::endl;

    //case 3
    std::vector<int> nums3={5,4,-1,7,8};
    std::cout << "示例3：" << sol.maxSubArray(nums3) << std::endl;
}