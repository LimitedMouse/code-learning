#include<iostream>
using namespace std;
#include<ctime>
int main()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
		//rand()%100 ��˼������һ��0-99���������α�����
	cout << "����������ɣ���Ϸ��ʼ" << endl;
	int val = 0;
	int a = 0;
	while (val != num)
	{
		cout << "���һ����" << endl;
		cin >> val;
		a++;
		if (val == num) { break; }
		if(val<num)
		{
			cout << "���С��" << endl;
		}
		else
		{
			cout << "��´���" << endl;
		}
	}

	cout << "��ϲ��¶��ˣ���Ϸ����.\n��һ������"<<a<<"��"<<endl;
	system("pause");
	return 0;

}