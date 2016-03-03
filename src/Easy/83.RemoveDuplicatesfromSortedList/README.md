###指针操作
	要注意的是删除重复结点 但多个结点要保留第一个，所以不要随意前进指针  

```cpp
auto pre = head;
while (pre&&pre->next) {
    auto tmp = pre->next;
    if (tmp->val == pre->val) {
        pre->next = tmp->next;
        delete tmp;
    } else { // 值相等的时候不移动pre 直到遇到新的值才前进pre
        pre = pre->next;
    }
}
```
