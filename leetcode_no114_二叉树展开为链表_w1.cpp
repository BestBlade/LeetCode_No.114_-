/* ------------------------------------------------------------------|
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：12 ms, 在所有 C++ 提交中击败了55.71%的用户
*	内存消耗：13.3 MB, 在所有 C++ 提交中击败了6.30%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, vector<TreeNode*>& s) {
    if (!root) {
        return;
    }
    s.emplace_back(root);
    dfs(root->left, s);
    dfs(root->right, s);
}

void flatten(TreeNode* root) {
    vector<TreeNode*> s;
    dfs(root, s);
    int n = s.size();
    for (int i = 1; i < n; i++) {
        TreeNode* pre = s[i - 1];
        TreeNode* curr = s[i];
        pre->left = nullptr;
        pre->right = curr;
    }
}