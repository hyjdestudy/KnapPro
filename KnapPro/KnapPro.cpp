/*
0-1��������
n����Ʒ��������������weights[]�У�����������СΪsize
���Ƿ����һ��ȡ����ʹ����ȡ��Ʒǡװ������

������
knap(w[],s,n)�н�ֻ������������������һ��w[n-1]�Ͱ���w[n-1]
1.���������һ��w[n-1]����knap(w,s,n)�Ƿ��н⼴Ϊknap(w,s,n-1)�Ƿ��н⣻
2.���������һ��w[n-1]����knap(w,s,n)�Ƿ��н⼴Ϊknap(w,s-w[n-1],n-1)�Ƿ��н⡣
���⣬
1.��size<0����Ϊ��s-w[n-1]��ÿ�εݹ鶼�п��ܰ�s���ͣ������޽⣻
2.��size>0����n<1����Ϊÿ�εݹ鶼��n-1�������޽⣨���ˣ����Ѿ�������ˣ����ӻ�ûװ������
3.��size=0�����н⣨ʲôҲ��װ��
�����Ϸ���֪��Ҫôsize����0��Ҫôn����0���ܻ�ͣ�����еݹ���ڣ����Կ����õݹ�
*/
#include <iostream>
using namespace std;

//�нⷵ��true
bool knap(int weights[], int size, int n) {  //weightsΪ����Ʒ������sizeΪ����������nΪ��Ʒ����
	if (size < 0) {  //����������СΪ�������޽�
		return false;
	}
	if (size > 0 && n < 1) {  //������������0������û����Ʒ���޽�
		return false;
	}
	if (size == 0) {  //����������СΪ0����ʱ�н⣬ȫ0
		return true;
	}
	if (knap(weights, size - weights[n - 1], n - 1)) {  //��n����Ʒװ�������£�ǰn-1����Ʒװ������Ϊsize-w[n-1]�İ���ǡ��װ��
		cout << "װ��" << n << "����Ʒ�������Ϊ��" << weights[n - 1] << endl;
		return true;
	}
	return knap(weights,size,n-1);  //��n����Ʒ��װ�������£��⼴Ϊ��ǰn-1����Ʒ�Ƿ�ǡ��װ������Ϊsize�İ���Ľ�
}

int main() {
	/*int n = 6;
	int goods[] = {1,8,4,3,5,2};*/
	int n = 5;
	int goods[] = { 1,2,3,4,5 };
	int bag_size = 10;
	int i = 0;
	for (i = 0; i < n; i++) {
		cout << "��" << i + 1 << "����Ʒ�����" << goods[i] << endl;
	}
	cout << "������Ϊ��" << bag_size << endl;
	cout << endl << "һ��װ������Ϊ��" << endl;
	knap(goods,bag_size,n);
	cout << endl;
	system("pause");
	return 0;
}