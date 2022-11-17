#include <iostream>
using namespace std;


const int N = 4;
int chess[N][N];
int point[N];
int Count = 0;
void Print()
{
	cout << "第" << Count+1 << "组" << endl;
	cout<<"┌ ─ ┬ ─ ┬ ─ ┬ ─ ┐" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "│";
		for (int j = 0; j < N; j++)
		{
			if (chess[i][j] == 0) {
				cout << " * │";
			}
			else {
				cout << "   │";
			}

		}
		cout << endl;
		if (i == N - 1)break;
		cout << "├ ─ ┼ ─ ┼ ─ ┼ ─ ┤" << endl;
	}
	cout<<"└ ─ ┴ ─ ┴ ─ ┴ ─ ┘" << endl;
	cout << endl << endl;
	Count++;

}

void Go(int row)
{
	if (row == N) //输出可行解
	{
		Print();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{

			if (point[i] < 2 && point[j] < 2) 
			{
				point[i]++; point[j]++;
				chess[row][i] = chess[row][j] = 1;
				Go(row + 1);
				point[i]--; point[j]--;               //回溯
				chess[row][i] = chess[row][j] = 0;
			}
		}
	}
}
void main()
{
	Go(0);
	cout << "共有" << Count << "组解" << endl;

}