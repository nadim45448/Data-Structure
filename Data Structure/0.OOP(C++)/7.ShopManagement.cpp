#include<iostream>
using namespace std;
class Shop
{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
protected:

    int total_income;
public:
    Shop()
    {
        this->total_income=0;
    }
    int GetTotal()
    {
        return total_income;
    }
    void setTotal(int total_income)
    {
        this->total_income+=total_income;
    }

};
int main()
{
    Shop *myShop=new Shop();
     cout<<"Number of products : ";
    int n;
    cin>>n;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Product "<<i<<" name: ";
        cin>>myShop->product_name[i];
        cout<<"Product "<<i<<" Price: ";
        cin>>myShop->product_price[i];
        cout<<"Product "<<i<<" Quantity: ";
        cin>>myShop->product_quantity[i];
        cout<<endl;
    }
    while(true)
    {
        cout<<"\t\t BUY PRODUCT"<<endl;
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
            cout<<myShop->product_name[i]<<"\t";
        }

           cout<<endl;
        cout<<"Product Price\t\t";
        for(int i=1;i<=n;i++)
        {
            cout<<myShop->product_price[i]<<"\t";
        }
        cout<<endl;
        cout<<"Product Quantity\t";
        for(int i=1;i<=n;i++)
        {
            cout<<myShop->product_quantity[i]<<"\t";
        }
        cout<<endl<<endl;
        cout<<"Which product do you want? From 1 to "<<n<<": ";
        int index,quantity;
        cin>>index;
        if(index>n)
        {
            cout<<"Invalid choice"<<endl;
        }
        else
        {
               cout<<"What is the quantity that you want of "<<myShop->product_name[index]<<" : ";
        cin>>quantity;
         if(myShop->product_quantity[index] < quantity)
        {
            cout<<"This quantity is not available"<<endl;
        }
         else
        {
            myShop->setTotal(quantity*myShop->product_price[index]);
            myShop->product_quantity[index]-=quantity;
            cout<<endl;
            cout<<myShop->product_name[index]<<" bought "<<quantity<<" pc successfully"<<endl;
            cout<<"Your total income : "<<myShop->GetTotal()<<endl;
        }
        }
          false;
    }
}
