#include<iostream>
#include<vector>

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:

// 输入: nums = [0]
// 输出: [0]

class Solution1 {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[count++]=nums[i];
            }
        }
        for(int i=count;i<n;i++){
            nums[i]=0;
        }
    }
};

int main(int argc,char ** argv){
    Solution1 sol1;

    //case 1
    std::vector<int> nums1_1={0,1,0,3,12};
    sol1.moveZeroes(nums1_1);
    std::cout << "示例1：[";
    for(int i=0;i<nums1_1.size()-1;i++){
        std::cout << nums1_1[i] << ",";
    }
    std::cout << nums1_1.back() << "]" << std::endl;

    //case 2
    std::vector<int> nums1_2={0};
    sol1.moveZeroes(nums1_2);
    std::cout << "示例2：[";
    for(int i=0;i<nums1_2.size()-1;i++){
        std::cout << nums1_2[i] << ",";
    }
    std::cout << nums1_2.back() << "]" << std::endl;
}