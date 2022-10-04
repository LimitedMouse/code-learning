#include<iostream>
using namespace std;
#include<ctime>
int main()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
		//rand()%100 意思是生成一个0-99的随机数（伪随机）
	cout << "随机数已生成，游戏开始" << endl;
	int val = 0;
	int a = 0;
	while (val != num)
	{
		cout << "请猜一个数" << endl;
		cin >> val;
		a++;
		if (val == num) { break; }
		if(val<num)
		{
			cout << "你猜小了" << endl;
		}
		else
		{
			cout << "你猜大了" << endl;
		}
	}

	cout << "恭喜你猜对了！游戏结束.\n您一共猜了"<<a<<"次"<<endl;
	system("pause");
	return 0;

}