//
//  main.cpp
//  leetcode-27移除元素
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 
 示例 1:
 
 给定 nums = [3,2,2,3], val = 3,
 
 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 
 示例 2:
 
 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 
 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 
 注意这五个元素可为任意顺序。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 
 说明:
 
 为什么返回数值是整数，但输出的答案是数组呢?
 
 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 */



#include <iostream>
#include <vector>

using namespace std;


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
    
    int removeElement2(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};


int main(int argc, const char * argv[]) {
    int a[10] = {1,1,1,3,3,4,3,2,4,2};
    sort(a,a+10);
    
    Solution sol;

    vector<int> b;
    for(int i=0;i< 10;i++){
        b.push_back(a[i]);
    }
    cout<<endl;

    cout << sol.removeElement(b ,4) << endl;
    return 0;
}
