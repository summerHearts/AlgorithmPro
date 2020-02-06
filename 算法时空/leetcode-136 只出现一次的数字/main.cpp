//
//  main.cpp
//  leetcode-136 只出现一次的数字
//
//  Created by 佐毅 on 2020/2/3.
//  Copyright © 2020 dfjr. All rights reserved.
//
/**
 ### 题目描述

 给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

 **说明：**

 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

 **示例 1:**

 ```
 输入: [2,2,1]
 输出: 1
 ```

 **示例 2:**

 ```
 输入: [4,1,2,1,2]
 输出: 4
 */

/**
 ### 题目解析

 根据题目描述，由于加上了时间复杂度必须是 O(n) ，并且空间复杂度为 O(1) 的条件，因此不能用排序方法，也不能使用 map 数据结构。

 程序员小吴想了一下午没想出来，答案是使用 **位操作Bit Operation** 来解此题。

 将所有元素做异或运算，即a[1] ⊕  a[2] ⊕  a[3] ⊕ …⊕  a[n]，所得的结果就是那个只出现一次的数字，时间复杂度为O(n)。
 */
/**
 ### 异或

 异或运算A ⊕  B的真值表如下：

 | A    |  B   |    ⊕ |
 | :--- | :--: | ---: |
 | F    |  F   |    F |
 | F    |  T   |    T |
 | T    |  F   |    T |
 | T    |  T   |    F |
 
 巧妙的解法：使用异或^运算符
 a^a=0;
 0^b=b;
 b^b=0;

 例如：2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3

 */

/**
 ### 进阶版

 有一个 n 个元素的数组，除了两个数只出现一次外，其余元素都出现两次，让你找出这两个只出现一次的数分别是几，要求时间复杂度为 O(n) 且再开辟的内存空间固定(与 n 无关)。
 */

/**
 #### 示例 :

 输入: [1,2,2,1,3,4]
 输出: [3,4]

 ### 题目再解析

 根据前面找一个不同数的思路算法，在这里把所有元素都异或，那么得到的结果就是那两个只出现一次的元素异或的结果。

 然后，因为这两个只出现一次的元素一定是不相同的，所以这两个元素的二进制形式肯定至少有某一位是不同的，即一个为 0 ，另一个为 1 ，现在需要找到这一位。

 根据异或的性质 `任何一个数字异或它自己都等于 0 `，得到这个数字二进制形式中任意一个为 1 的位都是我们要找的那一位。

 再然后，以这一位是 1 还是 0 为标准，将数组的 n 个元素分成两部分。

 - 将这一位为 0 的所有元素做异或，得出的数就是只出现一次的数中的一个
 - 将这一位为 1 的所有元素做异或，得出的数就是只出现一次的数中的另一个。

 这样就解出题目。忽略寻找不同位的过程，总共遍历数组两次，时间复杂度为O(n)。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
      int singleNumber(vector<int>& nums) {
          int res=nums[0];
          for(int i=1;i<nums.size();i++)
          {
              res=res^nums[i];
          }
          return res;
      }
  };

int main(int argc, const char * argv[]) {
  
   vector<int > temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(3);
 
    Solution solution;

    std::cout << solution.singleNumber(temp);
    return 0;
}
