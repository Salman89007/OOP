#include <iostream>
using namespace std;

class Bank;

class Wallet{
    int cash;
    public:
    Wallet(int cash){
        this->cash = cash;
    }
    friend void transfer(Wallet &w, Bank &b, int amount);

};
class Bank{
    int vault;
    public:
    Bank(int vault){
        this->vault = vault;
    }
    friend void transfer(Wallet &w, Bank &b, int amount);
};
void transfer(Wallet &w, Bank &b, int amount){

}

int main() {
    
    return 0;
}