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