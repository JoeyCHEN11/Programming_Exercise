# LeetCode 100 笔记

与代码随想录重复的不再记录

## 双指针

- [[11] Container With Most Water ](.\11.container-with-most-water.cpp)双指技巧：初始位置不一定必须要在同一侧，根据题目，每个左边界的可能的最大盛水范围在最右侧，右边界则反之，所以应该从两边向中间收缩

## 滑动窗口

- [[3] Longest Substring Without Repeating Characters](.\3.longest-substring-without-repeating-characters.cpp)
- [[438] Find All Anagrams in a String](.\438.find-all-anagrams-in-a-string.cpp)

  重点为找到维护窗口的不变量，通用模板：外层扩展右边界，内层while收缩。此题窗口维护一个所有统计数都不小于0的cnt，复习：[[76] Minimum Window Substring](.\76.minimum-window-substring.cpp)

## 数组

- [[189] Rotate Array](.\189.rotate-array.cpp) 与 [KamaCoder_55.右旋字符串](.\KamaCoder_55.右旋字符串.cpp) 等价。注意调整k大小
- 

## 矩阵

- [[48] Rotate Image](.\48.rotate-image.cpp) 顺时针旋转矩阵90度,旋转前后关系：

$$
matrix[row][col] \rightarrow matrix[col][n - row - 1]
$$

该操作与：水平翻转，然后按对角线翻转（转置）等价，或竖直反转，再按反对角线翻转。

- [[73] Set Matrix Zeroes](.\73.set-matrix-zeroes.cpp) O(1)空间解法：借用第一行和第一列做为行列标记，再使用两个标记位记录第一行和第一列是否需要置0
- [[240] Search a 2D Matrix II](.\240.search-a-2-d-matrix-ii.cpp) 杨氏矩阵搜索：Z字查找O(m + n)

## 哈希

- [[1] Two Sum](.\1.two-sum.cpp)
- [[128] Longest Consecutive Sequence](.\128.longest-consecutive-sequence.cpp)
  先记录元素，然后遍历**set**（这里必须遍历set，否则在nums内会重复计数导致超过O(n)），遇到一个可能的连续序列的最小值时（即check[num-1]不存在时）进行计数，否则直接跳过
- [[49] Group Anagrams](.\49.group-anagrams.cpp)
  两种思路：
  1. 将string排序后作为key，构建map
  2. 用一个计数数组作为key，**演示了自定义类的hash构建方法**

## 图

- [[994] Rotting Oranges](.\994.rotting-oranges.cpp) 多源bfs，初始时将多个源节点入队即可，开distance保存距离
- [[207] Course Schedule ](.\207.course-schedule.cpp)拓扑排序标准模板，bfs同样可转为多源
- [[208] Implement Trie (Prefix Tree) ](.\208.implement-trie-prefix-tree.cpp)前缀树模板

## 栈

- [[394] Decode String](.\394.decode-string.cpp)
- [[155] Min Stack](.\155.min-stack.cpp)

## 堆

- [[215] Kth Largest Element in an Array](.\215.kth-largest-element-in-an-array.cpp)

  快速选择模板
  优化思路：基础划分（TLE）->随机化（AC）->均匀二分（大幅优化）->三路划分（最优）

## DP

- [118] Pascal's Triangle
- [[152] Maximum Product Subarray](.\152.maximum-product-subarray.cpp)
- 

## 多维DP

- [[64] Minimum Path Sum](.\64.minimum-path-sum.cpp)
- [[5] Longest Palindromic Substring](.\5.longest-palindromic-substring.cpp) 除dp外还可以借用manacher算法找出最长回文串，修正了manacher算法的逻辑

## 回溯

- [[22] Generate Parentheses](.\22.generate-parentheses.cpp) 使用cnt(或open + close + max)保证正确生成括号
- [[79] Word Search](.\79.word-search.cpp) 注意特殊情况返回条件：word只有1时，无法进入下一层，所以应该在最后一个字符匹配成功后的当前层直接判断是否完成搜索
- 

## 二分

- [[74] Search a 2D Matrix](.\74.search-a-2-d-matrix.cpp)
- [[33] Search in Rotated Sorted Array](.\33.search-in-rotated-sorted-array.cpp) 先找k的位置，再二分，或直接在查找时判断有序区间
- [[153] Find Minimum in Rotated Sorted Array](.\153.find-minimum-in-rotated-sorted-array.cpp) 把上面find k抠出来

## 技巧

- [[136] Single Number](.\136.single-number.cpp) 位运算
- [[169] Majority Element ](.\169.majority-element.cpp)摩尔投票
- [[287] Find the Duplicate Number](.\287.find-the-duplicate-number.cpp) 该问题与：环状链表[[142] Linked List Cycle II](.\142.linked-list-cycle-ii.cpp) 等价
