#include <bits/stdc++.h>
#include"4.myStack.h";
using namespace std;
int globalID = 100;

class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }
    void setName(string name)
    {
        this->name=name;
    }
    void setSalary(float salary)
    {
        this->salary=salary;
    }
    person(string name, float salary)
    {
        setName(name);//this->name = name;
        setSalary(salary);//this->salary = salary;
        id = globalID;
        globalID++;
    }
    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        cout<<name<<" | "<<id<<" | "<<salary<<endl;
    }
};

int main()
{
    /*Stack<person>st;
    person a("Nadim Hossain", 1500.5);
    person b("Hasib Hasan", 200.6);
    person c("Victor Stany",1800.75);
    st.push(a);
    st.push(b);
    st.push(c);*/
    // while (!st.empty())
    // {
    //     person printObj;
    //     printObj=st.pop();
    //     printObj.print();
    // }
    /*person printObj;
         printObj=st.topElement();
         printObj.print();*/
         Stack<int>st;
         st.push(1);
         st.push(2);
         st.push(3);
         st.push(4);
         st.push(5);
         cout<<st.mid()<<endl;
   
    
  
}