#include<bits/stdc++.h>
using namespace std;
class Example
{
public:
    int a,b;
    Example(int x)
    {
        b=x;
        //cout<<a<<" ";
    }
    Example operator +(Example obj)
    {
        cout<<b<<" "<<obj.b<<endl;
        cout<<b+obj.b;

        Example ans(0);
        ans.a=a+obj.a;
        return ans;
    }
};

int main()
{
    Example a(10),b(20),c(30);
//    cout<<a+b;//can't sum becz a, b are object. Object cannot be sum
    a+b;
    //Example ans=a+b;
    //cout<<ans.a<<endl;
    //Example ans2=ans+c;
    //cout<<ans2.b;


}
