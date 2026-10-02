#include <iostream>
#include <string>
using namespace std;
class Matrix{
	private:
	int *ptr;
	public:
	Matrix(){
		ptr = new int[10];
	}
	~Matrix(){
		delete[] ptr;
		cout<<"constructor deleted"<<endl;
	}
};

int main(){
	Matrix M[10];
	for(int i=0;i<10;i++){
		M[i];
		cout<<"constructor created"<<endl;
	}
	cout<<"------------------------"<<endl;;
	return 0;
}