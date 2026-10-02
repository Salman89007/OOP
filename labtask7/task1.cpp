#include <iostream>
#include <string>
using namespace std;
class Book{
	private:
	string title;
	int pages;
	public:
	Book()
	{
		title = "Unknown";
		pages = 0;
	}
	
	Book(string Title,int Pages)
	{
		title = Title;
		pages = Pages;
	}
};
int main(){
	Book B1;
	Book B2("ozymandias",100);
	cout<<"BOOK B1 : "<<B1<<endl;
	cout<<"BOOK B2 : "<<B2<<endl;
	return 0;
}