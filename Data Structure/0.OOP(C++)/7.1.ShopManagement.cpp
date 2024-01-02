#include<bits/stdc++.h>
using namespace std;
class Shop
{
public:
    string productName[10];
    int productPrice[10];
    int productQuantity[10];
protected:
    int totalIncome;
public:
    shop()
    {
        this->totalIncome=0;
    }
    void SetTotalIncome(int amount)
    {
        this->totalIncome+=amount;
    }
    int GetTotalIncome()
    {
        return this->totalIncome;
    }

};
Shop* shop()
{
    cout<<"WELCOME TO ABC SHOP!"<<endl;
    Shop *myShop=new Shop();
    return myShop;
}
void ProductList(Shop *myShop,int no)
{
    int n=no;
   // cout<<"Number of products:";
   // cin>>n;
    cout<<endl;

    cout<<"\t\tPRODUCT LIST"<<endl;
    cout<<"\t\t____________"<<endl;
    cout<<"Product Index\t\t";
        for(int i=1;i<=n;i++)
        {
            cout<<i<<"\t";
        }
        cout<<endl;
        cout<<"product Name\t\t";
         for(int i=1;i<=n;i++)
        {
            cout<<myShop->productName[i]<<"\t";
        }

           cout<<endl;
        cout<<"Product Price\t\t";
        for(int i=1;i<=n;i++)
        {
            cout<<myShop->productPrice[i]<<"\t";
        }
        cout<<endl;
        cout<<"Product Quantity\t";
        for(int i=1;i<=n;i++)
        {
            cout<<myShop->productQuantity[i]<<"\t";
        }
        cout<<endl<<endl;
}
int main()
{
    Shop *myShop=shop();
    int number;
    cout<<"Enter number of products:";
    cin>>number;
     for(int i=1;i<=number;i++)
    {
        cout<<"Product "<<i<<"name:";
        cin>>myShop->productName[i];
        cout<<endl;
        cout<<"Product "<<i<<"price:";
        cin>>myShop->productPrice[i];
        cout<<endl;
        cout<<"Product "<<i<<"quantity:";
        cin>>myShop->productQuantity[i];
        cout<<endl;

    }
    //ProductList(myShop,number);



        bool choice =true;
        while(choice)
        {
            ProductList(myShop,number);
            cout<<"Select an option"<<endl;
            cout<<"1.Purchase"<<endl;
            cout<<"2.Exit"<<endl;
            int option;
            cin>>option;
            switch(option)
            {
                 case 1:

            cout<<"Which product do you want? From 1 to "<<number<<": ";
            int index,quantity;
            cin>>index;
            if(index>number||index<=0)
            {
                cout<<"Invalid choice"<<endl;
            }
            else
            {

                 cout<<"What is the quantity that you want of "<<myShop->productName[index]<<" : ";
                 cin>>quantity;
                 if(myShop->productQuantity[index]<quantity)
                 {
                     cout<<"This quantity is not available"<<endl;
                 }
                 else
                 {
                     myShop->SetTotalIncome(quantity*myShop->productPrice[index]);
                     myShop->productQuantity[index]-=quantity;
                     cout<<myShop->productName[index]<<" bought "<<quantity<<" pc successfully"<<endl;
            cout<<"Your total income : "<<myShop->GetTotalIncome()<<endl;
                 }

            }
            break;
        case 2:
            choice=false;
            break;
        default:
            cout<<"Invalid option"<<endl;
            }

        }

}
