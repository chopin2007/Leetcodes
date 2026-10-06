#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

 

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        else if(s.size()==1) return 1;
        unordered_map<char,int> hp;
        int p=0;
        int maxlen=1;
        hp[s[p]]=0;
        for(int i=1;i<s.size();i++){
            if(hp.count(s[i]) && hp[s[i]]>=p){
                p=hp[s[i]]+1;
            }
            hp[s[i]]=i;
            maxlen=max(maxlen,i-p+1);
        }
        return maxlen;
    }
};


int main(int argc,char ** argv){
    Solution sol;

    //case 1
    string s1="abcabcbb";
    cout << "示例1：" << sol.lengthOfLongestSubstring(s1) << endl;

    //case 2
    string s2="bbbbb";
    cout << "示例2：" << sol.lengthOfLongestSubstring(s2) << endl;

    //case 3
    string s3="pwwkew";
    cout << "示例3：" << sol.lengthOfLongestSubstring(s3) << endl;
}