/*
0-1背包问题
n件物品，各自重量存在weights[]中，背包容量大小为size
问是否存在一种取法，使得所取物品恰装满背包

分析：
knap(w[],s,n)有解只有两种情况：不含最后一件w[n-1]和包含w[n-1]
1.若不含最后一件w[n-1]，则knap(w,s,n)是否有解即为knap(w,s,n-1)是否有解；
2.若包含最后一件w[n-1]，则knap(w,s,n)是否有解即为knap(w,s-w[n-1],n-1)是否有解。
另外，
1.若size<0（因为有s-w[n-1]，每次递归都有可能把s降低），则无解；
2.若size>0，但n<1（因为每次递归都有n-1），则无解（个人：货已经检查完了，袋子还没装满）；
3.若size=0，则有解（什么也不装）
由以上分析知，要么size减到0，要么n减到0，总会停下来有递归出口，所以可以用递归
*/
#include <iostream>
using namespace std;

//有解返回true
bool knap(int weights[], int size, int n) {  //weights为各物品重量，size为背包容量，n为物品个数
	if (size < 0) {  //背包容量大小为负数，无解
		return false;
	}
	if (size > 0 && n < 1) {  //背包容量大于0，但是没有物品，无解
		return false;
	}
	if (size == 0) {  //背包容量大小为0，此时有解，全0
		return true;
	}
	if (knap(weights, size - weights[n - 1], n - 1)) {  //第n件物品装入的情况下，前n-1个物品装入容量为size-w[n-1]的包里恰能装满
		cout << "装入" << n << "号物品，其体积为：" << weights[n - 1] << endl;
		return true;
	}
	return knap(weights,size,n-1);  //第n件物品不装入的情况下，解即为“前n-1个物品是否恰能装满容量为size的包里”的解
}

int main() {
	/*int n = 6;
	int goods[] = {1,8,4,3,5,2};*/
	int n = 5;
	int goods[] = { 1,2,3,4,5 };
	int bag_size = 10;
	int i = 0;
	for (i = 0; i < n; i++) {
		cout << "第" << i + 1 << "件物品体积：" << goods[i] << endl;
	}
	cout << "包容量为：" << bag_size << endl;
	cout << endl << "一种装包方案为：" << endl;
	knap(goods,bag_size,n);
	cout << endl;
	system("pause");
	return 0;
}