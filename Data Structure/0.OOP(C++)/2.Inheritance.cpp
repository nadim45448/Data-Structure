#include<bits/stdc++.h>
using namespace std;
class Parent
{
public:
    int x;
private:
    int y;
protected:
    int z;
public:
    Parent(int a,int b,int c)
    {
        x=a;
        y=b;
        z=c;
    }

};
class Child :public Parent
{
public:
    int xx;
    Child(int aa,int a, int b, int c):Parent(a,b,c)
    {
        xx=aa;
    }
//protected data access...............
void TellMe()
{
    cout<<z;
}

};
int main()
{

    Parent pt(10,20,30);
    //cout<<pt.y;

    Child ch(5,10,20,300);
    //cout<<ch.xx<<endl;
    //cout<<ch.x<<endl;
    //cout<<ch.y<<endl;
   //cout<<ch.z<<endl;
   ch.TellMe();
}
