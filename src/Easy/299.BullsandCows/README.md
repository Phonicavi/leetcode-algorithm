###猜数字 A数字对位置对 B数字对位置不对  
	字符串长度都不一样肯定不对  
	扫一遍两个字符串 如果数字一样则A加一  
	如果不一样，则用两个数组 分别记录一下secret和guess中这个数字出现了多少次  

	A就是相同的数字的个数 即“数字对位置也对”有多少个  
	B就是扫一遍那两个辅助计数的数组 看看每个digit两边各有多少 取min 就是“数字对但位置不对”的数量  

```cpp
int A = 0, B = 0;
int digit_A[10] = {0};
int digit_B[10] = {0};

for (int i=0; i<secret.size(); ++i) {
	if (secret[i] == guess[i]) A++;
	else {
		digit_A[secret[i]-'0']++;
		digit_B[guess[i]-'0']++;
	}
}

for (int i=0; i<10; ++i) {
	B+=min(digit_A[i], digit_B[i]);
}

string s = to_string(A)+"A"+to_string(B)+"B";

// 或者用 stringstream 保存输出
// stringstream s;
// s << A <<"A"<< B <<"B";
// string ans = s.str();

```