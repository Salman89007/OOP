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
        title = "unknown";
        pages = 0;
    }
    Book(string Title,int Pages)
    {
        title = Title;
        pages = Pages;
    }
    void Display(){
        cout<<"Title is : "<<title<<endl;
        cout<<"Pages : "<<pages<<endl;
    }
};
int main()
{
    Book B1;
    Book B2("Ozymandias",100);
    B1.Display();
    B2.Display();
    return 0;
}