#include<iostream>
using namespace std;
class BankAccount
{
    public:
    string account_holder;
    string address;

    int account_number;
protected:
    float balance;
private:
    string password;
public:
    BankAccount(string account_holder,string address,string password)
    {
        this->account_holder=account_holder;
        this->address=address;

        this->password=password;
        this->account_number=rand()%100000000;
        cout<<"Your account number is:"<<account_number<<endl;
        this->balance=0;
    }

    int ShowBalance(string password)
    {
        if(this->password==password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }

    void AddMoney(string password,int amount)
    {
        if(this->password==password)
        {
            if(amount<0)
            {
                cout<<"Invalid amount"<<endl;
            }
            else
            {
               this->balance+=amount;
               cout<<"ADD MONEY SUCCESSFUL"<<endl;
            }
        }
        else
        {
             cout<<"Invalid password, cannot add money"<<endl;
        }
    }

    void DepositMoney(string password,int amount)
    {
        if(this->password==password)
        {
            if(amount<0)
            {
                cout<<"Invalid amount"<<endl;
            }
            else if(this->balance<amount)
            {
                cout<<"Insufficient fund"<<endl;
                return;
            }
            else
            {
               this->balance-=amount;
               cout<<"DEPOSIT MONEY SUCCESSFUL"<<endl;
            }
        }
        else
        {
             cout<<"Invalid password, cannot deposit money"<<endl;
        }
    }
    friend class MyCash;
};
class MyCash
{
protected:
    int balance;
public:
    Mycash()
    {
        this->balance=0;
    }

    void AddMoneyFromBank(BankAccount *myAccount,string password,int amount)
    {
        if(myAccount->password==password)
        {
            if(amount<0)
            {
                cout<<"Invalid Amount"<<endl;
            }
            else if(myAccount->balance<amount)
            {
                cout<<"Insufficient fund"<<endl;
                return;
            }
            else
            {
                this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"ADD MONEY FROM BANK SUCCESSFUL!"<<endl;
            }

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
{
    string name,address,password;

    cout<<"CREATE ACCOUNT"<<endl;
    cout<<"Enter name,address,password"<<endl;
    cin>>name>>address>>password;
    BankAccount *myAccount=new BankAccount(name,address,password);
    return myAccount;
}
void AddMoney(BankAccount *myAccount)
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
    BankAccount *myAccount=CreateAccount();
    MyCash *myCash=new MyCash();
    bool choice=true;
    while(choice)
    {
        cout<<"Select an option"<<endl;
        cout<<"1.ADD MONEY TO BANK"<<endl;
        cout<<"2.DEPOSIT MONEY FROM BANK"<<endl;
        cout<<"3.ADD MONEY TO MyCash FROM BANK"<<endl;
        cout<<"4.Exit"<<endl;
    int option;
    cin>>option;
    switch(option)
    {
    case 1:
        AddMoney(myAccount);
        break;
    case 2:
        DepositMoney(myAccount);
        break;
    case 3:
        AddMoneyFromBank(myCash,myAccount);
        break;
    case 4:
        choice=false;
        break;
    default:
        cout<<"Invalid choice"<<endl;


    }
    }



   /* if(myAccount->ShowBalance("123")==-1)
    {
        cout<<"Invalid Password"<<endl;
    }
    else
    {
        cout<<"Your account balance:"<<myAccount->ShowBalance("123")<<endl;
    }*/
   /* AddMoney(myAccount);
    DepositMoney(myAccount);

    MyCash *myCash=new MyCash();
    AddMoneyFromBank(myCash,myAccount);*/
}




