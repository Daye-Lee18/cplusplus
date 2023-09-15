/*
input: the root of a binary tree 
output: return the level order traversal of its nodes' values 
    - from left to right
    - level by level 

ex) 

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

        3 
      /   \ 
      9   20
         /  \ 
        15   7 
*/

#include <bits/stdc++.h>
#include "binary_search_tree_helper.h"
#include <queue> 

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel; // 새로운 cur level 형성 
      // 현재의 q.size 만큼만 currLevel에 넣기 
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        currLevel.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(currLevel);
    }

    return ans;
  }
};


