#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

 

// 示例 1:

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//  示例 2:

// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        if(p.size()==0) return {};
        unordered_map<char,int> tar;
        int all=0;
        for(int i=0;i<p.size();i++){
            if(!tar.count(p[i])){
                tar[p[i]]=1;
            }
            else{
                tar[p[i]]+=1;
            }
        }
        vector<int> result;
        int l=0;
        unordered_map<char,int> ans;
        if(tar.count(s[l])){
            ans[s[l]]=1;
            all++;
        }
        if(all == (int)p.size()) result.push_back(0);
        for(int r=1;r<s.size();r++){
            if(ans.count(s[r])){
                if(ans[s[r]]<tar[s[r]]){
                    ans[s[r]]+=1;
                    all+=1;
                }
                else{
                    while(s[r]!=s[l]){
                        if(ans.count(s[l])){
                            all--;
                            if(ans[s[l]]>1) ans[s[l]]-=1;
                            else ans.erase(s[l]);
                        }
                        l++;
                    }
                    l++;
                }
            }
            else if(tar.count(s[r])){
                ans[s[r]]=1;
                all+=1;
            }
            else{
                if(r+1<s.size()){
                    ans.clear();
                    l=r+1;
                    r+=1;
                    all=0;
                    if(tar.count(s[l])){
                        ans[s[l]]=1;
                        all++;
                    }
                    if(all == (int)p.size()) result.push_back(l);
                    continue;
                }
                else break;
            }
            if(all==p.size()){
                result.push_back(r-all+1);
                if(ans.count(s[l])){
                    all--;
                    if(ans[s[l]]>1) ans[s[l]]-=1;
                    else ans.erase(s[l]);
                }
                l++;
            }
        }
        return result;
    }
};

int main(int argc,char ** argv){
    //先用我这个自己手搓出来的石
    Solution1 sol1;

    //case 1
    string s1="cbaebabacd";
    string p1="abc";
    cout << "示例1：[";
    vector<int> res1=sol1.findAnagrams(s1,p1);
    for(int i=0;i<res1.size()-1;i++){
        cout << res1[i] << ",";
    }
    cout << res1.back() << "]" << endl;

    //case 2
    string s2="abab";
    string p2="ab";
    cout << "示例2：[";
    vector<int> res2=sol1.findAnagrams(s2,p2);
    for(int i=0;i<res2.size()-1;i++){
        cout << res2[i] << ",";
    }
    cout << res2.back() << "]" << endl;
}