#include<iostream>
using namespace std;
void hannuota(int n, string a, string b, string c)
	{
	if (n == 1) {
		cout << a << "->" << c << endl;
	}
	else {
		hannuota(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		hannuota(n - 1, b, a, c);
	}
	}
int main() {
	cout << "请输入盘子个数" << endl;
	int n;
	cin >> n;
	hannuota(n, "a", "b", "c");
	system("pause");
	return 0;
};