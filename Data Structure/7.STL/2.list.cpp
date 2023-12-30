#include<bits/stdc++.h>
using namespace std;
void print(list<int>l)
{
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++)
    {

        cout<<*it<<"-->";
    }
    cout<<endl;

}
int main()
{

    list<int>l;
    l.push_back(5);
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_back(40);
//    cout<<l.front()<<endl<<endl;
//    cout<<l.back()<<endl<<endl;
//    print(l);
//    list<int>::iterator it=l.begin();
//    advance(it,3);
//    cout<<*it;
     //l.insert(it,100);

//print(l);
//l.pop_front();
//print(l);
//l.pop_back();
//print(l);

print(l);
list<int>::iterator it1=l.begin();
list<int>::iterator it2=l.begin();
advance(it1,1);
advance(it2,4);
l.erase(it1,it2);
print(l);


}
