//
//  main.cpp
//  leetcode-35搜索插入位置
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 
 你可以假设数组中无重复元素。
 
 示例 1:
 输入: [1,3,5,6], 5
 输出: 2
 
 
 示例 2:
 输入: [1,3,5,6], 2
 输出: 1
 
 
 示例 3:
 输入: [1,3,5,6], 7
 输出: 4
 
 
 示例 4:
 输入: [1,3,5,6], 0
 输出: 0
 
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    long searchInsert(vector<int>& nums, int target) {
        long n = nums.size();
        long left = 0;
        long right = n; // 定义target在左闭右开的区间里，[left, right)  target
           while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
               long middle = left + ((right - left) / 2);
               if (nums[middle] > target) {
                   right = middle; // target 在左区间，在[left, middle)中
               } else if (nums[middle] < target) {
                   left = middle + 1; // target 在右区间，在 [middle+1, right)中
               } else { // nums[middle] == target
                   return middle; // 数组中找到目标值的情况，直接返回下标
               }
           }
           // 分别处理如下四种情况
           // 目标值在数组所有元素之前 [0,0)
           // 目标值等于数组中某一个元素 return middle
           // 目标值插入数组中的位置 [left, right) ，return right 即可
           // 目标值在数组所有元素之后的情况 [left, right)，return right 即可
           return right;
       }
    
    long searchInsert2(vector<int>& nums, int target) {
            long n = nums.size();
            long left = 0;
            long right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
            while (left <= right) { // 当left==right，区间[left, right]依然有效
                long middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
                if (nums[middle] > target) {
                    right = middle - 1; // target 在左区间，所以[left, middle - 1]
                } else if (nums[middle] < target) {
                    left = middle + 1; // target 在右区间，所以[middle + 1, right]
                } else { // nums[middle] == target
                    return middle;
                }
            }
            // 分别处理如下四种情况
            // 目标值在数组所有元素之前  [0, -1]
            // 目标值等于数组中某一个元素  return middle;
            // 目标值插入数组中的位置 [left, right]，return  right + 1
            // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
            return right + 1;
        }
};
int main(int argc, const char * argv[]) {
    
    Solution sol;
    int a[7] = {1,3,4,6,9,10,12};
    
    vector<int> b;
    for(int i=0;i< 7;i++){
        b.push_back(a[i]);
    }
    cout<<endl;
    
    cout<< sol.searchInsert(b, 5) <<endl;
    return 0;
}


