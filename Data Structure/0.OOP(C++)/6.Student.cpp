#include<iostream>
using namespace std;
class Student
{
public:
    string name;
    char section;
    int roll;
protected:

    int english_marks;
private:

    string password;
public:

    void set_marks(int marks)
    {
        english_marks=marks;
    }
    void set_password(string pass)
    {
        password=pass;
    }
    int get_marks()
    {
        return english_marks;
    }
    void update_marks(string pass,int marks)
    {
        if(pass==password)
        {
            english_marks=marks;
        }
        else
        {
            cout<<"Password didn't match!"<<endl;
        }
    }

};
int main()
{
    int n;
    cout<<"Enter number of student:";
    cin>>n;
    Student st[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter name,section,roll,marks,password for"<<i+1<<" student"<<endl;
        string name,password;
        char section;
        int roll,marks;
        cin>>name>>section>>roll>>marks>>password;
        st[i].name=name;
        st[i].section=section;
        st[i].roll=roll;
        st[i].set_marks(marks);
        st[i].set_password(password);
    }

    cout<<"Update marks"<<endl;
      int roll,marks;
    string password;
    cout<<"Enter roll,marks,password"<<endl;
    cin>>roll>>marks>>password;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(st[i].roll==roll)
        {
            found=true;
            st[i].update_marks(password,marks);
        }
    }
      if(!found)
    {
        cout<<"Student not found!"<<endl;
        return 0;
    }
      for(int i=0;i<n;i++)
    {
        cout<<st[i].name<<" "<<st[i].section<<" "<<st[i].roll<<" "<<st[i].get_marks()<<endl;
    }

}
