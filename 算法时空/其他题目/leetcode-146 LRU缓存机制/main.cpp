//
//  main.cpp
//  leetcode-146 LRU缓存机制
//
//  Created by 佐毅 on 2021/4/8.
//  Copyright © 2021 dfjr. All rights reserved.
//

/**
 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
 实现 LRUCache 类：

 LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
  

 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

  
 示例：

 输入
 ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 输出
 [null, null, null, 1, null, -1, null, -1, 3, 4]

 解释
 LRUCache lRUCache = new LRUCache(2);
 lRUCache.put(1, 1); // 缓存是 {1=1}
 lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 lRUCache.get(1);    // 返回 1
 lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 lRUCache.get(2);    // 返回 -1 (未找到)
 lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 lRUCache.get(1);    // 返回 -1 (未找到)
 lRUCache.get(3);    // 返回 3
 lRUCache.get(4);    // 返回 4
  

 提示：

 1 <= capacity <= 3000
 0 <= key <= 3000
 0 <= value <= 104
 最多调用 3 * 104 次 get 和 put
 */
#include <iostream>
#include <vector>
#include <list>

#include <unordered_map>
using namespace std;

class LRUCache {
private:
  list<pair<int, int>> cache;   ////< @note pair[key]=value
  unordered_map<int, list<pair<int, int>>::iterator> hashMap;
  int cap;                      ////< @note 最大容量

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (hashMap.find(key) == hashMap.end()) {
      return -1;
    }
    pair<int, int> node = *hashMap[key];
    cache.erase(hashMap[key]); ////< @note 将节点移到链表头部并更新map
    cache.push_front(node);
    hashMap[key] = cache.begin();
    return node.second;
  }

  void put(int key, int val) {
    auto newNode = std::make_pair(key, val);

    if (hashMap.count(key)) {  ////< @note 若该节点已存在，则删除旧的节点
      cache.erase(hashMap[key]);
    } else {
      if (cap == cache.size()) {
        hashMap.erase(cache.back().first);
        cache.pop_back();       ////< @note 删除链表最后一个数据
      }
    }

    cache.push_front(newNode);  ////< @node 插入新的节点到头部
    hashMap[key] = cache.begin();
  }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
