#include <iostream>
#include <string>
using namespace std;
class Matrix
{
private:
	int *ptr;

public:
    Matrix(){ ptr = nullptr;}
	Matrix(int n)
	{
		ptr = new int[n];
		cout << "constructor created" << endl;
	}
	~Matrix()
	{
		delete[] ptr;
		cout << "constructor deleted" << endl;
	}
};

int main()
{
	int n;
	cout<<"enter n: "<<endl;
	cin>>n;
	Matrix **M = new Matrix *[n];
	for (int i = 0; i < n; i++)
		M[i] = new Matrix(i + 1); // constructor runs here with i+1

	for (int i = 0; i < n; i++)
		delete M[i];
	delete[] M;
	return 0;
}