class Solution {
public:
	int addDigits(int num) {
		return (num-1)%9 + 1;
	}

    int addDigits2(int num) {// 最basic的方法 即逐位相加 用递归
        if (num < 10) return num;
        int sum = 0;
        while (num/10) {
            sum += num%10;
            num /= 10;
        }
        return addDigits2(sum+num);
    }
};