#include<iostream>
using namespace std;

class Parent
{
private:
    int taka;
public:
    Parent(int tk)
    {
        taka=tk;
    }

    friend class AbburBondhu;
    //friend void TellSecret(Parent *ptr);//optional

};
class AbburBondhu
{

    public:
        void TellSecret(Parent *ptr) // Parent is the class name
        {
            cout<<ptr->taka;
        }
};
int main()
{
    Parent pt(1500);
    AbburBondhu bondhu;
    bondhu.TellSecret(&pt);
}
