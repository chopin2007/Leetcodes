#include<iostream>
#include<vector>
#include<algorithm>

// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

 

// 示例 1:

// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]
// 示例 2:

// 输入：nums = [-1,-100,3,99], k = 2
// 输出：[3,99,-1,-100]
// 解释: 
// 向右轮转 1 步: [99,-1,-100,3]
// 向右轮转 2 步: [3,99,-1,-100]
 

// 提示：

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

//O
class Solution1 {
public:
    void rotate(std::vector<int>& nums, int k) {
        while(k%nums.size()>nums.size()) k=k%nums.size();
        std::vector<int> rest;
        for(int i=0;i<k;i++){
            for(int j=nums.size()-1;j>0;j--){
                int temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
        }
    }
};

//反转数组
class Solution2 {
public:
    void reverse(std::vector<int>& nums,int begin,int end){
        while(begin<end){
            std::swap(nums[begin++],nums[end--]);
        }
    }
    void rotate(std::vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,k,nums.size()-1);
        reverse(nums,0,k-1);
    }
};

int main(int argc,char ** argv){
    Solution2 sol2;

    //case 1
    std::vector<int> nums2_1={1,2,3,4,5,6,7};
    int k2_1=3;
    sol2.rotate(nums2_1,k2_1);
    std::cout << "示例1：[";
    for(int i=0;i<nums2_1.size()-1;i++){
        std::cout << nums2_1[i] << ",";
    }
    std::cout << nums2_1.back() << "]" << std::endl;

    //case 2
    std::vector<int> nums2_2={-1,-100,3,99};
    int k2_2=-2;
    sol2.rotate(nums2_2,k2_2);
    std::cout << "示例2：[";
    for(int i=0;i<nums2_2.size()-1;i++){
        std::cout << nums2_2[i] << ",";
    }
    std::cout << nums2_2.back() << "]" << std::endl;
}