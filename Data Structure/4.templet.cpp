#include<bits/stdc++.h>
using namespace std;
// template<typename T> 
// T sum(T a, T b)
// {
//     T s=a+b;
//     return s;

// }

template<typename T1,typename T2>
T2 sum(T1 a,T1 b)
{
    T2 s=(a+b)*2.11;
    return s;

}

int main()
{
    // int a=10,b=20;
    // int add=sum<int>(a,b);
    // cout<<add<<endl;
    // float c=4.5,d=9.2;
    // float add2=sum<float>(c,d);
    // cout<<add2<<endl;

    int a=10,b=20;
     double add=sum<int,double>(a,b);
     cout<<add<<endl;


}