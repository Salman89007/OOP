#include <iostream>
using namespace std;

class Friend{
    int x;
    public:
    Friend(int X){
        x = X;
    }
    friend void showX(Friend f);

};
void showX(Friend f){
    cout<<f.x<<endl;
}

int main() {
    Friend f(5);
    showX(f);
    
    return 0;
}