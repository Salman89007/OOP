#include <iostream>
#include <string>
using namespace std;
class Matrix
{
private:
	int *ptr;
	int id = 0;

public:
	Matrix() { ptr = nullptr; }
	Matrix(int n, int ID)
	{
		ptr = new int[n];
		cout << "constructor created for ID : " << ID + 1 << endl;
		id = ID;
	}
	~Matrix()
	{
		delete[] ptr;
		cout << "constructor destroyed for ID : "<<id+1 << endl;
	}
};

int main()
{
	int n;
	cout << "enter n: " << endl;
	cin >> n;
	Matrix **M = new Matrix *[n];
	int ID = 0;
	for (int i = 0; i < n; i++)
	{
		M[i] = new Matrix(i + 1, ID);
		ID++;
	}

	for (int i = 0; i < n; i++)
		delete M[i];
	delete[] M;
	return 0;
}