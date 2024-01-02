#include<bits/stdc++.h>
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

      void AddMoney(string password,float amount)
    {
        if(this->password==password)
        {
            this->balance+=amount;
            cout<<"Add money successful"<<endl;
        }
        else
        {
            cout<<"Invalid password, cannot add money"<<endl;
        }
    }

     void DepositMoney(string password,float amount)
    {
        if(this->password==password)
        {
            this->balance-=amount;
            cout<<"Deposit money successful"<<endl;
        }
        else
        {
            cout<<"Invalid password, cannot deposit"<<endl;
        }
    }
    friend class MyCash;

};

class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance=0;
    }
    void AddMoneyFromBank(BankAccount *myAccount,string password,int amount)
    {
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"ADD MONEY FROM BANK SUCCESSFUL!"<<endl;
        }
        else
        {
            cout<<"Invalid Password"<<endl;
        }
    }
    int ShowBalance()
    {
        return this->balance;
    }
};
BankAccount* CreateAccount()
//void CreateAccount()
{
    string account_holder,address,password;
    int age;
    cout<<"CREATE ACCOUNT"<<endl;
    cout<<"Enter name,address,password"<<endl;
    cin>>account_holder>>address>>password;

    BankAccount *myAccount=new BankAccount(account_holder,address,age,password);//delete kora chara myaccount delete hobe na
      return myAccount;

}

void AddMoney(BankAccount *myAccount)//obj chara money add korte parbe na,tai age parameter e bankAcccount er obj rcv korte hbe, pointer akare nise becz main function pointer akare ache
{
    string password;
    float amount;
    cout<<"ADD MONEY"<<endl;
    cout<<"Enter password and amount"<<endl;
    cin>>password>>amount;
    myAccount->AddMoney(password,amount);
    cout<<"Your account balance:"<<myAccount->ShowBalance(password)<<"tk"<<endl;
}

void DepositMoney(BankAccount *myAccount)//obj chara money add korte parbe na,tai age parameter e bankAcccount er obj rcv korte hbe, pointer akare nise becz main function pointer akare ache
{
    string password;
    float amount;
    cout<<"DEPOSIT MONEY"<<endl;
    cout<<"Enter password and amount"<<endl;
    cin>>password>>amount;
    myAccount->DepositMoney(password,amount);
    cout<<"Your account balance:"<<myAccount->ShowBalance(password)<<"tk"<<endl;
}
void AddMoneyFromBank(MyCash *myCash,BankAccount *myAccount)
{
    string password;
    float amount;
    cout<<"ADD MONEY FROM BANK"<<endl;
    cout<<"Enter password and amount"<<endl;
    cin>>password>>amount;
   myCash->AddMoneyFromBank(myAccount,password,amount);
   cout<<"Your account balance:"<<myAccount->ShowBalance(password)<<"tk"<<endl;
   cout<<"Your MyCash balance: "<<myCash->ShowBalance()<<endl;
}
int main()
{
    //CreateAccount();
    BankAccount*myAccountt=CreateAccount();

   /* if(myAccount->ShowBalance("ab123")==-1)
    {
        cout<<"Invalid password"<<endl;
    }
    else{
        cout<<"Your account balance:"<<myAccount->ShowBalance("ab123")<<"tk"<<endl;
    }*/

    AddMoney(myAccountt);
    DepositMoney(myAccountt);

    //MyCash class.............
    //MyCash myCash;
    MyCash *myCash=new MyCash();
    AddMoneyFromBank(myCash,myAccountt);
    return 0;

}
