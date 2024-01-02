#include<bits/stdc++.h>
using namespace std;

class Example
{
private:
    int x,pass;
public:


    /*void Setter(int a)
    {
        x=a;
    }
    int Get()
    {
        return x;
    } */

    //more efficiently................
    Example(int p)
    {
        pass=p;
    }
    void Set(int a,int p)
    {
        if (pass==p)
        {
            x=a;
        }
        else
            cout<<"Invalid Password, can't set..."<<endl;
    }

    int Get(int p)
    {
        if(pass==p)
            return x;
        else
        {
            cout<<"Invalid Password, can't get..."<<endl;
        }
        return -1;
    }
};

int main()
{

    /*Example ex;
    ex.Setter(10);
    cout<<ex.Get();*/

    //more efficiently
    Example ex(1234);
    ex.Set(10,12134);
    cout<<ex.Get(1234);
}
