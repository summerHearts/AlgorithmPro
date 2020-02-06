//
//  main.cpp
//  leetcode-137 只出现一次的数字 II
//
//  Created by 佐毅 on 2020/2/3.
//  Copyright © 2020 dfjr. All rights reserved.
//


/**
 C++，位运算。讲一个更容易理解的解法吧，复杂度是32 * O(n)，也是符合题目要求的。热评大佬的解法我暂时没看懂。

 只要是在int范围内，每个整数都是用32位二进制表示的。如果我们将nums中所有数都转成32位的二进制，并用一个size为32的数组bits表示每个位中1的个数，就能发现一件很巧妙的事情。

 有一些位的值，是3的倍数
 有一些位的值，不是3的倍数，且对3取模一定等于1
 不存在有值对3取模等于2
 举个例子，nums = [5, 3, 3, 3]，为了简单，我们用4位二进制表示，则nums = [0101, 0011, 0011, 0011]。根据刚才的规律和定义的bits的功能，我们得到bits应该是bits = [4, 3, 1, 0]。bits有如下规律：

 bits[0, 2] % 3 == 1
 bits[1, 3] % 3 == 0
 然后我们直接把bits数组中能够整除3的值置0，不能整除3的值置1，就得到了一个表示二进制的整型数组。经过这个操作的bits为bits = [1, 0, 1, 0]，用二进制来看就是0101，也就是5，正好是只出现一次的那个数。

 这个规律不仅对本例适用，对所有例子都是适用的，这里我就不证明了，其实我也不会证明。。。

 用这个规律解本题，只要实现三个操作就行了：

 用bits数组统计nums中所有数转化成二进制后，每个位上1的个数
 将bits数组中能够整除3的值置0，不能整除3的值置1
 将bits转换成真的二进制数
 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++){
                bits[i] += (nums[j] >> i) & 1;
            }
            ans |= (bits[i] % 3) << i;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int > temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(3);
    
    Solution solution;
    
    std::cout << solution.singleNumber(temp);
    
    
    return 0;
}
