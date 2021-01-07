/* ------------------------------------------------------------------|

����һ����������ԭ�ؽ���չ��Ϊһ��������



���磬����������

    1
   / \
  2   5
 / \   \
3   4   6
����չ��Ϊ��

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

/*	˫ָ�뷨
*
*	ִ����ʱ��4 ms, ������ C++ �ύ�л�����98.59%���û�
*	�ڴ����ģ�12.9 MB, ������ C++ �ύ�л�����38.98%���û�
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
    //�����ǰ�ڵ���ڵĻ�
    while (curr) {
        //�ж��Ƿ�����ڵ�
        if (curr->left) {
            //�����ڵ����
            TreeNode* next = curr->left;
            TreeNode* pre = next;
            //һֱ�ҵ������������½�Ҷ�ڵ�
            while (pre->right) {
                pre = pre->right;
            }
            //��ǰ�ڵ��������ת�ӵ������������½�Ҷ�����
            pre->right = curr->right;
            //�ͷŵ�ǰ�ڵ�������
            curr->left = nullptr;
            //��ԭ�������������������
            curr->right = next;
        }
        //��ǰ�ڵ������ӽڵ��ƶ�
        curr = curr->right;
    }
}