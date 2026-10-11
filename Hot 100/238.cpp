#include<iostream>
#include<vector>

// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

// 示例 1:

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
// 示例 2:

// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        if(nums.size()==0) return {};
        std::vector<int> v(nums.size()-1,1);
        v.push_back(1);
        for(int i=0;i<nums.size()-1;i++){
            v[i+1]=v[i]*nums[i];
        }
        int num=1;
        for(int i=nums.size()-1;i>=0;i--){
            v[i]*=num;
            num*=nums[i];
        }
        return v;
    }
};


int main(int argc,char ** argv){
    Solution sol;

    //case 1
    std::vector<int> nums1={1,2,3,4};
    std::vector<int> res1=sol.productExceptSelf(nums1);
    std::cout << "示例1：[";
    for(int i=0;i<res1.size()-1;i++){
        std::cout << res1[i] << ",";
    }
    std::cout << res1.back() << "]" << std::endl;

    //case 2
    std::vector<int> nums2={-1,1,0,-3,3};
    std::vector<int> res2=sol.productExceptSelf(nums2);
    std::cout << "示例2：[";
    for(int i=0;i<res2.size()-1;i++){
        std::cout << res2[i] << ",";
    }
    std::cout << res2.back() << "]" << std::endl;
}