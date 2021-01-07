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
          6|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了98.59%的用户
*	内存消耗：12.9 MB, 在所有 C++ 提交中击败了38.98%的用户
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

void flatten(TreeNode* root) {
    TreeNode* curr = root;
    //如果当前节点存在的话
    while (curr) {
        //判断是否有左节点
        if (curr->left) {
            //存放左节点变量
            TreeNode* next = curr->left;
            TreeNode* pre = next;
            //一直找到左子树的右下角叶节点
            while (pre->right) {
                pre = pre->right;
            }
            //当前节点的右子树转接到左子树的右下角叶结点上
            pre->right = curr->right;
            //释放当前节点左子树
            curr->left = nullptr;
            //将原来的左子树变成右子树
            curr->right = next;
        }
        //当前节点向右子节点移动
        curr = curr->right;
    }
}