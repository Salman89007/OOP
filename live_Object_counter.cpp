#include<iostream>//live object counter
using namespace std;
class Random{
    private:
    static int count;
    public:
    Random(){
        count++;
    }
    ~Random(){
        count--;
    }
    static int returnCount(){
        return count;
    }
};
int Random::count = 0;
int main()
{
    cout<<"before any object created: "<<Random::returnCount()<<endl;
    Random r1,r2,r3;
    cout<<"after : "<<Random::returnCount()<<endl;
    Random* r[3];
    cout<<"after : "<<Random::returnCount()<<endl;
    {
        Random r4,r5;
        
        r[0] = new Random();
        r[1] = new Random();
        r[2] = new Random();
        cout<<"after : "<<Random::returnCount()<<endl;
        
    }
    cout<<"after : "<<Random::returnCount()<<endl;
    delete r[0];
    delete r[1];
    delete r[2];
    cout<<"after : "<<Random::returnCount()<<endl;
    return 0;
}