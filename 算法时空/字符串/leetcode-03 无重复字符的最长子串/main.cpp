//
//  main.cpp
//  leetcode-03 无重复字符的最长子串
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/*
 给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。
 
 **示例 1:**
 
 ```java
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 ```
 */

/*
 解题思路
 
 建立一个256位大小的整型数组 freg ，用来建立字符和其出现位置之间的映射。
 
 维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
 
 - （1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
 - （2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
 - （3）重复（1）（2），直到左边索引无法再移动；
 - （4）维护一个结果res，每次用出现过的窗口大小来更新结果 res，最后返回 res 获取结果。
 **/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    long lengthOfLongestSubstring(string s) {
        long freq[256] = {0};
        long l = 0, r = -1; //滑动窗口为s[l...r]
        long res = 0;
        // 整个循环从 l == 0; r == -1 这个空窗口开始
        // 到l == s.size(); r == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
        while(l < s.size()){
            if(r + 1 < s.size() && freq[s[r+1]] == 0){
                r++;
                freq[s[r]]++;
            }else {   //r已经到头 || freq[s[r+1]] == 1
                freq[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
    
    long lengthOfLongestSubstrings(string s) {
        long max=0;
        long hashmap[130];
        long n = s.size();
        for(long i=0,j=0;j<n;j++){//当前判断是否重复的串为s[i..j]
            hashmap[s[j]]++;
            while(hashmap[s[j]]>1){
                hashmap[s[i++]]--;  //i指针右移
            }
            if(j-i+1>max)
                max = j-i+1;
        }
        return max;
    }
    
    int lengthOfLongestSubstringss(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solu;
    string str("abcabcbb");
    std::cout << solu.lengthOfLongestSubstringss(str);
    return 0;
}
