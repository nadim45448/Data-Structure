#include<bits/stdc++.h>

using namespace std;
class Restaurant
{
public:

    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];


protected:

    double total_tax;
public:
    Restaurant()
    {
        this->total_tax=0;
    }
    void set_Tax(double tax)
    {
        this->total_tax=tax;
    }



};
Restaurant* restaurant()
{
    Restaurant *rt=new Restaurant();
    return rt;
}
void ShowItem(Restaurant *rt,int item)
{
    int it=item;
    cout<<"\t\t\tMAKE BILL"<<endl;
    cout<<"\t\t__________________________"<<endl<<endl;
    cout<<"Item Code\t\t";
    cout<<"Item Name\t\t";
    cout<<"Item Price\t\t";
    cout<<endl<<endl;
    for(int i=1;i<=it;i++)
    {
    cout<<rt->food_item_codes[i]<<"\t\t\t"<<rt->food_item_names[i]<<"\t\t\t"<<rt->food_item_prices[i]<<endl;
    }
       cout<<endl;
}
void Order(Restaurant *rt,int item)
{
    int it=item;

    int table_no,number_of_item;
    cout<<"Enter Table No:";
    cin>>table_no;
    cout<<"Enter Number of item:";
    cin>>number_of_item;
    cout<<endl;

    int ar_code[number_of_item]={0};
    int ar_quantity[number_of_item];
    int total_price[number_of_item]={0};



   //Flag:
       for(int i=1;i<=number_of_item;i++)//..............................
    {
        Flag:
        bool found=false;
        //int item_code;
        cout<<"Enter item "<<i<<" code:";
        cin>>ar_code[i];

       // cout<<"Enter item "<<i<<" quantity:";
       // cin>>ar_quantity[i];
        //cout<<endl;
        for(int b=1;b<=it;b++)
        {
            if(ar_code[i]==rt->food_item_codes[b])
            {
                found=true;
                cout<<"Enter item "<<i<<" quantity:";
                cin>>ar_quantity[i];
                cout<<endl;
            }

        }
        if(!found)
    {
        cout<<"code not valid.Reenter item "<<i<<" code"<<endl<<endl;
        //i--;
        goto Flag;
    }

    }


    cout<<endl;
    double tax;
    double tax_parcent=0.05;
    float net_total=0;
    cout<<"\t\t\t BILL SUMMARY"<<endl;
    cout<<"\t\t______________________________"<<endl;
    cout<<"Table No. :"<<table_no<<endl;
    cout<<"Item Code\t\t";
    cout<<"Item Name\t\t";
    cout<<"Item Price\t\t";
    cout<<"Item quantity\t\t";
    cout<<"Total Price";
    cout<<endl;
    for(int i=1; i<=number_of_item; i++)
    {
        for(int a=1; a<=it; a++)
        {
            if(ar_code[i]==rt->food_item_codes[a])

            {
                total_price[i]=ar_quantity[i]*rt->food_item_prices[a];

                cout<<ar_code[i]<<"\t\t\t"<<rt->food_item_names[a]<<"\t\t\t"<<rt->food_item_prices[a]<<"\t\t\t"<<ar_quantity[i]<<"\t\t\t"<<total_price[i]<<endl;
                net_total+=total_price[i];

            }
        }

    }
    tax=net_total*tax_parcent;
    cout<<"Tax\t\t\t\t\t\t\t\t\t\t\t\t"<<tax;
    cout<<endl;
    net_total+=tax;
    cout<<"_______________________________________________________________________________________________________________________"<<endl;
    cout<<"NET TOTAL\t\t\t\t\t\t\t\t\t\t\t"<<net_total<<endl;
    rt->set_Tax(tax);

}
int main()
{
   // Restaurant *rt=new Restaurant();
    Restaurant *rt= restaurant();
    cout<<"Number of items:";
    int item;
    cin>>item;
    cout<<endl;
    for(int i=1;i<=item;i++)
    {
        cout<<"Item "<<i<<" code: ";
        cin>>rt->food_item_codes[i];
        cout<<"Item "<<i<<" name: ";
        //cin>>rt->food_item_names[i];
       //gets(rt->food_item_names[i]);
       cin.ignore();
       getline(cin,rt->food_item_names[i]);
        cout<<"Item "<<i<<" price: ";
        cin>>rt->food_item_prices[i];
        cout<<endl<<endl;
    }
    ShowItem(rt,item);
    Order(rt,item);


}
