#include<iostream>
using namespace std;
int main() {
	int temp = 0;
	int arr[] = { 4,7,5,8,6,1,2,0,3,9 };
	int p = 9;
	while (p > 0) {
		for (int t = 0; t < p; t++) {
			if (arr[t] > arr[t + 1]) {
				temp = arr[t];
				arr[t] = arr[t + 1];
				arr[t + 1] = temp;
			}
		}
		p--;
	}
	int i = 0;
	while(i<10)
	{
		cout << arr[i] << endl; i++;
	}
	system("pause");
	return 0;
}