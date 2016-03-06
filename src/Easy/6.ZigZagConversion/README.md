###锯齿状字符排列 找规律  

numRows = 3  

0   4   8    12    16    20 ...  
1 3 5 7 9 11 13 15 17 19  
2   6   10   14    18  

numRows = 4, rim = 2*(4-1) = 6  

0       6       12       18 ...  
1    5  7    11 13    17  
2 4     8 10    14 16  
3       9       15   

遍历string s 对于s[i]来说  
	- i == 0||i == numRows-1, i:=i+rim 在同一行  
	- i%rim == k // k>0 && k<numRows-1, i:=(k*rim-i) 在同一行  

```cpp
string ans = "";
for (int line=0; line<numRows; ++line) {
	int k = 0;
	for (int i=line; i<s.size();) {
		ans += s[i];
		if (line%rim==0||line%rim==numRows-1) i+=rim;
		else i=(++k)*rim-i;
	}
}
return ans;
```