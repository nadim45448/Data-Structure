#include<iostream>
using namespace std;
class BankAccount
{
   public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    float balance;
private:
    string password;

    public:
    BankAccount(string account_holder,string address,int age,string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%1000000000;
        this->balance=0;
        cout<<"your account number is: "<<this->account_number<<endl;
    }
    float ShowBalance(string password)
    {
        if(this->password==password)
            return this->balance;
        else
            return -1;
    }



};
void CreateAccount()
{
    string account_holder,address,password;
    int age;
    cout<<"CREATE ACCOUNT"<<endl;
    cout<<"Enter name,address,password"<<endl;
    cin>>account_holder>>address>>password;

    BankAccount *myAccount=new BankAccount(account_holder,address,age,password);//delete kora chara myaccount delete hobe na


}
int main()
{
    CreateAccount();

}
