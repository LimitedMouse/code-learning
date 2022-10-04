#include<iostream>
using namespace std;
void menu() {
	cout << "****1.添加联系人****\n****2.显示联系人****\n****3.删除联系人****\n****4.查找联系人****\n****5.修改联系人****\n****6.清空联系人****\n****7.退出通讯录****" << endl;
	cout << "请选择需要进行的操作" << endl;
}
struct person {
	string name;
	int age=0;
	bool sex=0;//1男，0女
	string phone;
	string addr;
};

struct books {
	struct person perArr[1000];
	int size=0;
};

void addPerson(books *txl) {
	if (txl->size >= 1000) {
		cout << "通讯录已满，请清理后重试！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		txl->perArr[txl->size].name=name;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		txl->perArr[txl->size].age = age;

		bool sex;
		cout << "请输入性别（1男，0女）" << endl;
		cin >> sex;
		txl->perArr[txl->size].sex = sex;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		txl->perArr[txl->size].phone = phone;

		string addr;
		cout << "请输入住址" << endl;
		cin >> addr;
		txl->perArr[txl->size].addr = addr;
		cout << "添加成功" << endl;
		txl->size++;
	}
}
void showPerson(books* txl) {
	if (txl->size <= 0) {
		cout << "通讯录是空的！" << endl;
	}
	else {
		for (int i = 0; i < txl->size; i++) {
			if (txl->perArr[i].sex) 
			{
				cout << i+1 << ".\n姓名：" << txl->perArr[i].name << "\n年龄：" << txl->perArr[i].age << "\t性别：男\n电话：" << txl->perArr[i].phone << "\n住址：" << txl->perArr[i].addr << endl;
			}
			else {
				cout << i+1 << ".\n姓名：" << txl->perArr[i].name << "\n年龄：" << txl->perArr[i].age << "\t性别：女\n电话：" << txl->perArr[i].phone << "\n住址：" << txl->perArr[i].addr << endl;
			}
		}
	}
}
void deletePerson(books* txl,int k) {
	txl->perArr[k].name = "";
	txl->perArr[k].age = 0;
	txl->perArr[k].phone = "";
	txl->perArr[k].addr="";
	for (int i = k; i < txl->size; i++) {
		txl->perArr[i] = txl->perArr[i + 1];
	}
}
int searchPerson(books* txl, string name) {
	for (int i = 0; i < txl->size; i++) {
		if (txl->perArr[i].name == name) {
			return i;
		}
	}return -1;
}
int main() {
	books txl;
	int select = 0;
	while (select != 7) {
		menu();
		cin >> select;
		switch (select) {
		case 1://1.添加联系人
		{addPerson(&txl); }
			break;
		case 2://2.显示联系人
		{showPerson(&txl); }
			break;
		case 3://3.删除联系人
		{string name;
		cout << "请输入需要删除的联系人姓名" << endl;
		cin >> name;
		int temp = searchPerson(&txl, name);
		if (temp != -1) {
			deletePerson(&txl, temp);
			cout << "已成功删除" << endl;
			txl.size--;
		}
		else {
			cout << "未找到符合标准的联系人！" << endl;
		}
		}
			break;
		case 4://4.查找联系人
		{string name;
		cout << "请输入需要查找的联系人姓名" << endl;
		cin >> name;
		int temp = searchPerson(&txl, name);
		if (temp != -1) {
			cout << temp+ 1 << ".\n姓名：" << txl.perArr[temp].name << "\n年龄：" << txl.perArr[temp].age << "\t性别：男\n电话：" << txl.perArr[temp].phone << "\n住址：" << txl.perArr[temp].addr << endl;
		}
		else {
			cout << "未找到符合标准的联系人！" << endl;
		}}
			break;
		case 5://5.修改联系人
		{string name;
		cout << "请输入需要修改的联系人姓名" << endl;
		cin >> name;
		int l = searchPerson(&txl, name);
		cout << "请输入姓名" << endl;
		cin >> name;
		txl.perArr[l].name = name;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		txl.perArr[l].age = age;

		bool sex;
		cout << "请输入性别（1男，0女）" << endl;
		cin >> sex;
		txl.perArr[l].sex = sex;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		txl.perArr[l].phone = phone;

		string addr;
		cout << "请输入住址" << endl;
		cin >> addr;
		txl.perArr[l].addr = addr;
		cout << "修改成功" << endl;
		}
			break;
		case 6://6.清空联系人
		{
			for (int i = 0; i < txl.size; i++) {
				deletePerson(&txl, i);
			}
			txl.size = 0;
		}
			break;
		case 7://7.退出通讯录
			cout << "欢迎下次再来" << endl;
			system("pause");
			return 0;
		default:cout << "发生错误,请重新选择" << endl;
			break;
		}
		system("pause");
		system("cls");//清屏
	}

	system("pause");
	return 0;
}