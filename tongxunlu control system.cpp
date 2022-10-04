#include<iostream>
using namespace std;
void menu() {
	cout << "****1.�����ϵ��****\n****2.��ʾ��ϵ��****\n****3.ɾ����ϵ��****\n****4.������ϵ��****\n****5.�޸���ϵ��****\n****6.�����ϵ��****\n****7.�˳�ͨѶ¼****" << endl;
	cout << "��ѡ����Ҫ���еĲ���" << endl;
}
struct person {
	string name;
	int age=0;
	bool sex=0;//1�У�0Ů
	string phone;
	string addr;
};

struct books {
	struct person perArr[1000];
	int size=0;
};

void addPerson(books *txl) {
	if (txl->size >= 1000) {
		cout << "ͨѶ¼����������������ԣ�" << endl;
		return;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		txl->perArr[txl->size].name=name;

		int age;
		cout << "����������" << endl;
		cin >> age;
		txl->perArr[txl->size].age = age;

		bool sex;
		cout << "�������Ա�1�У�0Ů��" << endl;
		cin >> sex;
		txl->perArr[txl->size].sex = sex;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		txl->perArr[txl->size].phone = phone;

		string addr;
		cout << "������סַ" << endl;
		cin >> addr;
		txl->perArr[txl->size].addr = addr;
		cout << "��ӳɹ�" << endl;
		txl->size++;
	}
}
void showPerson(books* txl) {
	if (txl->size <= 0) {
		cout << "ͨѶ¼�ǿյģ�" << endl;
	}
	else {
		for (int i = 0; i < txl->size; i++) {
			if (txl->perArr[i].sex) 
			{
				cout << i+1 << ".\n������" << txl->perArr[i].name << "\n���䣺" << txl->perArr[i].age << "\t�Ա���\n�绰��" << txl->perArr[i].phone << "\nסַ��" << txl->perArr[i].addr << endl;
			}
			else {
				cout << i+1 << ".\n������" << txl->perArr[i].name << "\n���䣺" << txl->perArr[i].age << "\t�Ա�Ů\n�绰��" << txl->perArr[i].phone << "\nסַ��" << txl->perArr[i].addr << endl;
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
		case 1://1.�����ϵ��
		{addPerson(&txl); }
			break;
		case 2://2.��ʾ��ϵ��
		{showPerson(&txl); }
			break;
		case 3://3.ɾ����ϵ��
		{string name;
		cout << "��������Ҫɾ������ϵ������" << endl;
		cin >> name;
		int temp = searchPerson(&txl, name);
		if (temp != -1) {
			deletePerson(&txl, temp);
			cout << "�ѳɹ�ɾ��" << endl;
			txl.size--;
		}
		else {
			cout << "δ�ҵ����ϱ�׼����ϵ�ˣ�" << endl;
		}
		}
			break;
		case 4://4.������ϵ��
		{string name;
		cout << "��������Ҫ���ҵ���ϵ������" << endl;
		cin >> name;
		int temp = searchPerson(&txl, name);
		if (temp != -1) {
			cout << temp+ 1 << ".\n������" << txl.perArr[temp].name << "\n���䣺" << txl.perArr[temp].age << "\t�Ա���\n�绰��" << txl.perArr[temp].phone << "\nסַ��" << txl.perArr[temp].addr << endl;
		}
		else {
			cout << "δ�ҵ����ϱ�׼����ϵ�ˣ�" << endl;
		}}
			break;
		case 5://5.�޸���ϵ��
		{string name;
		cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
		cin >> name;
		int l = searchPerson(&txl, name);
		cout << "����������" << endl;
		cin >> name;
		txl.perArr[l].name = name;

		int age;
		cout << "����������" << endl;
		cin >> age;
		txl.perArr[l].age = age;

		bool sex;
		cout << "�������Ա�1�У�0Ů��" << endl;
		cin >> sex;
		txl.perArr[l].sex = sex;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		txl.perArr[l].phone = phone;

		string addr;
		cout << "������סַ" << endl;
		cin >> addr;
		txl.perArr[l].addr = addr;
		cout << "�޸ĳɹ�" << endl;
		}
			break;
		case 6://6.�����ϵ��
		{
			for (int i = 0; i < txl.size; i++) {
				deletePerson(&txl, i);
			}
			txl.size = 0;
		}
			break;
		case 7://7.�˳�ͨѶ¼
			cout << "��ӭ�´�����" << endl;
			system("pause");
			return 0;
		default:cout << "��������,������ѡ��" << endl;
			break;
		}
		system("pause");
		system("cls");//����
	}

	system("pause");
	return 0;
}