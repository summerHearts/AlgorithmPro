//
//  main.cpp
//  leetcode-54螺旋矩阵
//
//  Created by 佐毅 on 2021/4/8.
//  Copyright © 2021 dfjr. All rights reserved.
//


/**
 解题思路：
 这里的方法不需要记录已经走过的路径，所以执行用时和内存消耗都相对较小

 首先设定上下左右边界
 其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
 判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
 若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
 C++
  https://leetcode-cn.com/problems/spiral-matrix/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-3/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
