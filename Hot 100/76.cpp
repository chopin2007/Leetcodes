#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

// 给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

// 测试用例保证答案唯一。

 

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
// 解释：整个字符串 s 是最小覆盖子串。
// 示例 3:

// 输入: s = "a", t = "aa"
// 输出: ""
// 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
// 因此没有符合条件的子字符串，返回空字符串。

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        else if(s==t) return s;
        unordered_map<char,int> target;
        for(int i=0;i<t.size();i++){
            target[t[i]]+=1;
        }
        unordered_map<char,int> now;
        int resr=0;
        int resl=0;
        int minlen=INT_MAX;
        int goal=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(target.count(s[r])){
                now[s[r]]+=1;
                if(now[s[r]]==target[s[r]]){
                    goal+=1;
                }
            }
            while(goal==target.size()){
                if(target.count(s[l])){
                    now[s[l]]--;
                    if(now[s[l]]<target[s[l]]) goal--;
                }
                if(r-l+1<minlen){
                    resr=r;
                    resl=l;
                    minlen=r-l+1;
                }
                l++;
            }
        }
        return (minlen==INT_MAX)?"":s.substr(resl,resr-resl+1);
    }
};

int main(int argc,char ** argv){
    Solution sol;

    //case 1
    string s1="ADOBECODEBANC";
    string t1="ABC";
    cout << "示例1：\"" << sol.minWindow(s1,t1) << "\"" << endl;

    //case 2
    string s2="a";
    string t2="a";
    cout << "示例2：\"" << sol.minWindow(s2,t2) << "\"" << endl;

    //case 3
    string s3="a";
    string t3="aa";
    cout << "示例3：\"" << sol.minWindow(s3,t3) << "\"" << endl;
}