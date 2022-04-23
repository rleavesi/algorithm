[26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
- 数组_双指针
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int j = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[j] != nums[i]) nums[++j] = nums[i];
		}
		return j;
	}
};
```

[27. 移除元素](https://leetcode-cn.com/problems/remove-element/)
- 数组_双指针
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int left = 0;
		int right = nums.size();
		while (left < right) {
			if (nums[left] == val) {
				nums[left] = nums[right - 1];
				right--;
			}
			else {
				left++;
			}
		}
		return left;
	}
};
```

[283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)
- 数组_双指针
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() < 2)	return;
		int size = nums.size();
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		for (int k = j; k < nums.size(); k++)
			nums[k] = 0;
    }
};
```
[844. 比较含退格的字符串](https://leetcode-cn.com/problems/backspace-string-compare/)

- 数组_栈
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

#define max(a,b) a>b?a:b

class Solution {
public:

	std::string stack_string(std::string s)
	{
		std::string t;
		for (char c : s) {
			if (c == '#') {
				if(t.size() != 0)
					t.pop_back();
			}
			else {
				t.push_back(c);
			}
		}
		return t;
	}

	bool backspaceCompare(string s, string t) {
		s = stack_string(s);
		t = stack_string(t);
		if (s == t) return true;
		else return false;
	}
};

```
[977. 有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/)

- 数组
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define max(a,b) a>b?a:b

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
			nums[i] = nums[i] * nums[i];
		sort(nums.begin(), nums.end()); // quick sort
		return nums;
	}
};

```

- 数组_双指针
``` C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define max(a,b) a>b?a:b

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int size = nums.size() - 1;
		vector<int> res(nums.size(), 0);
		
		for (int i = 0, j = size; i <= j;) {
			if (abs(nums[i]) > abs(nums[j])) {
				res[size--] = nums[i] * nums[i];
				i++;
			}
			else {
				res[size--] = nums[j] * nums[j];
				j--;
			}
		}
		return res;
	}
};

```


[209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)
- 数组_滑动窗口
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;
#define min(a,b) a<b?a:b

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int len = 0;
		int i = 0;
		int sum = 0;
		for (int j = 0; j < nums.size(); j++) {
			sum += nums[j];
			while (sum >= target) {
				len = len == 0 ? j - i + 1 : min(len, j - i + 1);
				sum -= nums[i++];
			}
		}
		return len;
	}
};
```

[203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/)
- 链表
```C++
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while(head != NULL && head->val == val) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
		
		ListNode* cur = head;
		while (cur != NULL && cur->next != NULL) {
			if (cur->next->val == val) {
				ListNode* temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}
};
```


[707. 设计链表](https://leetcode-cn.com/problems/design-linked-list/)
- 双向链表
```C++
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

typedef struct LinkNode {
	int val;
	LinkNode* next;
	LinkNode* prior;
	LinkNode(int _val) :val(_val), prior(nullptr), next(nullptr) {}
	LinkNode(int _val, LinkNode* _prior, LinkNode* _next) :val(_val), prior(_prior), next(_next) {}
}LinkNode;

class MyLinkedList {
public:
	MyLinkedList() : _size(-1), head(nullptr), tail(nullptr) {}

	int get(int index) {
		if (index > _size || index < 0) return -1;
		LinkNode* cur = head;
		int j = 0;
		while (++j) {
			if (j - 1 == index) {
				return cur->val;
			}
			cur = cur->next;
		}
		return -1;
	}

	void addAtHead(int val) {
		if (head) {
			LinkNode* temp = new LinkNode(val, nullptr, head);
			head->prior = temp;
			head = temp;
			_size++;
			if (_size == 0) tail = temp;
		}
		else {
			LinkNode* temp = new LinkNode(val, nullptr, nullptr);
			head = tail = temp;
			_size++;
		}
		return;
	}

	void addAtTail(int val) {
		if (tail) {
			LinkNode* temp = new LinkNode(val, tail, nullptr);
			tail->next = temp;
			tail = temp;
			_size++;
			if (_size == 0) head = temp;
		}
		else {
			LinkNode* temp = new LinkNode(val, nullptr, nullptr);
			head = tail = temp;
			_size++;
		}
		return;
	}

	void addAtIndex(int index, int val) {
		if (index < 0) addAtHead(val);
        else if (index == 0) addAtHead(val);
		else if (index == _size + 1) addAtTail(val);
		else if (index > _size + 1) return;
		else {
			LinkNode* cur = head;
			int j = 0;
			while (++j) {
				if (j - 1 == index) {
					LinkNode* temp = new LinkNode(val,cur->prior,cur);
					temp->next->prior = temp;
					temp->prior->next = temp;
					_size++;
					return;
				}
				else {
					cur = cur->next;
				}
			}
		}
	}

	void deleteHead() {
		if (_size == -1)	return;
		LinkNode* temp = head;
		if (head != tail) head->next->prior = nullptr;
		head = head->next;
		_size--;
		delete temp;
	}

	void deleteTail() {
		if (_size == -1)	return;
		LinkNode* temp = tail;
		if(head != tail) tail->prior->next = nullptr;
		tail = tail->prior;
		_size--;
		delete temp;
	}


	void deleteAtIndex(int index) {
		if (index < 0 || index > _size || _size == -1) return;
		else if (index == 0)	deleteHead();
		else if (index == _size) 	deleteTail();
		else {
			LinkNode* cur = head;
			int j = 0;
			while (++j) {
				if (j - 1 == index) {
					cur->prior->next = cur->next;
					cur->next->prior = cur->prior;
					_size--;
					delete cur;
					return;
				}
				else {
					cur = cur->next;
				}
			}
		}
	}

	void out() {
		LinkNode* cur = head;
		while (cur) {
			cout << cur->val << " -> ";
			cur = cur->next;
		}
		cout << " over " << endl;
		cout << " over ";
		cur = tail;
		while (cur) {
			cout << " <- " << cur->val;
			cur = cur->prior;
		}
		cout << endl;
		cout << "size -> " << _size << endl << endl;
	}

private:
	int _size;
	LinkNode* head;
	LinkNode* tail;
};

```


[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
- 双指针
- 递归
```C++
class Solution {
public:
	ListNode* reverse(ListNode* pre, ListNode* cur) {
		if (!cur) return pre;
		ListNode* temp = cur->next;
		cur->next = pre;
		return reverse(cur, temp);
	}

	ListNode* reverseList(ListNode* head) {
		return reverse(nullptr, head);
	}

};
```

[24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)
```C++
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* visual = new ListNode(0,head);
		ListNode* cur = visual;

		while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode* temp1 = cur->next;
			ListNode* temp2 = cur->next->next->next;
			
			cur->next = temp1->next;
			cur->next->next = temp1;
			cur->next->next->next = temp2;

			cur = cur->next->next;
		}
		return visual->next;
	}
};
```

[面试题 02.07. 链表相交](https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/)
```C++ 
#include <iostream>
#include <stdint.h>
#include <math.h>
using namespace std;

class Solution {
public:
	int get_len(ListNode* head) {
		if (!head) return 0;
		int len = 1;
		while (head->next) {
			len++;
			head = head->next;
		}
		return len;
	}
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = get_len(headA);
		int lenB = get_len(headB);
		if (lenA == 0 || lenB == 0)	return nullptr;
		
		ListNode* s;
		ListNode* l;
		
		if (lenA > lenB) {
			s = headB;
			l = headA;
		}
		else {
			s = headA;
			l = headB;
		}
		for (int i = 0; i < abs(lenA - lenB); i++) 
			l = l->next;

		while (s != l) {
			s = s->next;
			l = l->next;
			if (!s || !l) return nullptr;
		}
		return s;
	}

	void out(ListNode* head) {
		while (head) {
			cout << head->val << "->";
			head = head->next;
		}
		cout << endl;
	}
 };
```
[242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)
```C++
#include <iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int len[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
			len[s[i] - 'a'] ++;
		for (int i = 0; i < t.size(); i++) {
			len[t[i] - 'a'] --;
			if (len[t[i] - 'a'] < 0) return false;
		}
		for (int i = 0; i < 26; i++) {
			if (len[i] != 0) return false;
		}
		return true;
	}
};
```

[144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)
```C++
class Solution {
public:
	void reverse(TreeNode* root, vector<int> & res) {
		if (root == nullptr) return;
		res.push_back(root->val);
		reverse(root->left, res);
		reverse(root->right, res);
	}

vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		reverse(root, res);
		return res;
	}
};
```


[145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/submissions/)
```C++
class Solution {
public:
	void reverse(TreeNode* root, vector<int> &res) {
		if (root == nullptr) return;
		reverse(root->left, res);
		reverse(root->right, res);
		res.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		reverse(root, res);
		return res;
	}
};
```

[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)
```C++
#include "lc.hpp"
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> res;
		while (!que.empty()) {
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
			res.push_back(vec);
		}
		return res;
	}
};
```

[103. 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)
```C++
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> res;
		bool left = true;
		while (!que.empty()) {
			left = !left;
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			if (left) reverse(vec.begin(), vec.end());
			res.push_back(vec);
		}
		return res;
	}
};

```

[199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/)
```C++
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> res;
		while (!que.empty()) {
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);

			}
			res.push_back(vec[vec.size() - 1]);
		}
		return res;
	}
};
```

[429. N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)
```C++
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> res;
		while (!que.empty()) {
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Node* temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				for (auto i : temp->children) {
					if (i) que.push(i);
				}
			}
			res.push_back(vec);
		}
		return res;
	}
};
```
[515. 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)
```C++
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int>  res;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode*  temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			int max = vec[0];
			for (auto i : vec) {
				if (i > max)	max = i;
			}
			res.push_back(max);
		}
		return res;
	}
};

```
[116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)
```C++
class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			Node* last;
			for (int i = 0; i < size; i++) {
                
				Node*  temp = que.front();
                if (i == size - 1)
					temp->next = nullptr;
				if (i != 0)
					last->next = temp;
				last = temp;
				que.pop();
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}
	return root;
	}
};
```


[226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)
```C++
#include "lc.hpp"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();

				TreeNode* cur = temp->left;
				temp->left = temp->right;
				temp->right = cur;

				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}
		return root;
	}
};
```

[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)
```C++
class Solution {
public:
	bool compare(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right != nullptr) return false;
		if (right == nullptr && left != nullptr) return false;
		if (right == nullptr && left == nullptr) return true;
		if (left->val != right->val) return false;
		if (!compare(left->left, right->right))	return false;
		if (!compare(left->right, right->left))	return false;
		return true;
	}

	bool isSymmetric(TreeNode* root) {
		return compare(root->left,root->right);
	}
};
```

[104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
```C++
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return	1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};
```

[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)
```C++
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;
		if (root->left == nullptr && root->right != nullptr) return 1 + minDepth(root->right);
		if (root->right == nullptr && root->left != nullptr) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};
```

[222. 完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/) 
```C++
class Solution {
public:
	void order(TreeNode* root, vector<int>& res) {
		if (root == nullptr)	return;
		res.push_back(root->val);
		order(root->left,res);
		order(root->right, res);
	}

	int countNodes(TreeNode* root) {
		vector<int> res;
		order(root, res);
		return res.size();
	}
};
```

[110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)
```C++
class Solution {
public:
	int getHeight(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		int leftHeight = getHeight(node->left);
		if (leftHeight == -1)	return -1;
		int rightHeight = getHeight(node->right);
		if (rightHeight == -1)	return -1;	
		return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
	}
	bool isBalanced(TreeNode* root) {
		if (getHeight(root) == -1)	return false;
		else return true;
	}
};
```

[257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)
```C++
class Solution {
public:
	void traversal(TreeNode* cur, vector<string>& res, vector<int> &path) {
		path.push_back(cur->val);
		if (cur->left == NULL && cur->right == NULL) {
			string sPath;
			for (int i = 0; i < path.size() - 1; i++) {
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);
			res.push_back(sPath);
			return;
		}
		if (cur->left) {
			traversal(cur->left, res, path);
			path.pop_back();	//回溯
		}
		if (cur->right) {
			traversal(cur->right, res, path);
			path.pop_back();	// 回溯
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		vector<int> path;
		if (root == NULL)	return res;
		traversal(root, res, path);
		return res;
	}
};
```

[404. 左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/)
```C++
class Solution {
public:
	void cal(int& res, TreeNode* root) {
		if (root == nullptr)	return;
		
		if (root->left != nullptr) {
			if (root->left->left == nullptr && root->left->right == nullptr) {
				res += root->left->val;
			}
			else cal(res, root->left);
		}

		cal(res, root->right);
	}

	int sumOfLeftLeaves(TreeNode* root) {
		int res = 0;
		cal(res, root);
		return res;
		
	}
};

// 精简版
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if(root == nullptr) return 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            res = root->left->val;
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```
[513. 找树左下角的值](https://leetcode-cn.com/problems/find-bottom-left-tree-value/)
```C++
class Solution {
public:
	int maxLen = INT_MIN;
	int maxval;
	
	void traversal(TreeNode* root,int leftlen) {
		if (root->left == nullptr && root->right == nullptr) {
			if (leftlen > maxLen) {
				maxLen = leftlen;
				maxval = root->val;
			}
		}
		if (root->left) {
			leftlen++;
			traversal(root->left, leftlen);
			leftlen--;
		}

		if (root->right) {
			leftlen++;
			traversal(root->right, leftlen);
			leftlen--;
		}
		
	}

	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 0);
		return maxval;
	}
};
```

[112. 路径总和](https://leetcode-cn.com/problems/path-sum/)
```C++
class Solution {
public:
	int target;
	
	bool traversal(int count, TreeNode* cur) {
		if (!cur->left && !cur->right && count == 0) return true;
		if (!cur->left && !cur->right) return false;			
		if(cur->left) {
			count -= cur->left->val;
			if (traversal(count, cur->left)) return true;
			count += cur->left->val;
		}
		if (cur->right) {
			count -= cur->right->val;
			if (traversal(count, cur->right)) return true;
			count += cur->right->val;
		}
		return false;
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)	return false;
		return traversal(targetSum - root->val, root);
	}
};
```

[113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)
```C++
class Solution {
public:
	void traversal(TreeNode* cur,int count, vector<int> vec ,vector<vector<int>> &res) {
		if (!cur->left && !cur->right && count == 0) {
			res.push_back(vec);
			return;
		}
		if (!cur->left && !cur->right) {
			return;
		}
		
		if (cur->left) {
			count -= cur->left->val;
			vec.push_back(cur->left->val);
			traversal(cur->left, count, vec, res);
			count += cur->left->val;
			vec.pop_back();
		}
		
		if (cur->right) {
			count -= cur->right->val;
			vec.push_back(cur->right->val);
			traversal(cur->right, count, vec, res);
			count += cur->right->val;
			vec.pop_back();
		}

	}
	
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		vector<int> vec;
		if (!root) return res;
		vec.push_back(root->val);
		traversal(root, targetSum - root->val, vec, res);
		return res;
		
	}
};
```