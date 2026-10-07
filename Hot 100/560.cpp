#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

 

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        unordered_map<int,int> hp;
        hp[0]=1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(hp.count(sum-k)) res+=hp[sum-k];
            if(!hp.count(sum)) hp[sum]=1;
            else hp[sum]+=1;
        }
        return res;
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    vector<int> nums1={1,1,1};
    int k1=2;
    cout << "示例1：" << sol.subarraySum(nums1,k1) << endl;

    //case 2
    vector<int> nums2={1,2,3};
    int k2=3;
    cout << "示例2：" << sol.subarraySum(nums2,k2) << endl;

    return 0;
}