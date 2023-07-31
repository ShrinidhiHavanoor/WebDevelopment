#include <iostream>
#include <cstring>
#include <cmath>
#include<fstream>
using namespace std;
int ta=0;
class customer
{
    public:
    string name;
    string fname;
    int billamount; 
    customer(){}
    customer(string n,string fn,int b)
    {
        name=n;
        fname=fn;
        billamount=b;
    }
    friend ofstream & operator<<(ofstream &ofs,customer c);
    friend ifstream & operator>>(ifstream &ifs,customer &c);
    friend ostream & operator<<(ostream &os,customer &c);
};
ofstream & operator<<(ofstream &ofs,customer c)
{
    ofs<<c.name<<endl;
    ofs<<c.fname<<endl;
    ofs<<c.billamount<<endl;
    return ofs;
}
ifstream &operator>>(ifstream &ifs,customer &c)
{
    ifs>>c.name;
    ifs>>c.fname;
    ifs>>c.billamount;
    return ifs;
}
ostream & operator<<(ostream &os,customer &c)
{
    cout<<"NAME:-"<<c.name<<endl;
    cout<<"FATHER`S NAME:-"<<c.fname<<endl;
    cout<<"BILLAMOUNT:-"<<c.billamount<<endl;
    return os;
}
int main()
{   
    customer c;
    int n=5,m,billamount=0,disamount=0,count=1,key=0;
    string name,fname;
    cout<<"Are you?"<<endl;
    cout<<"1.CUSTOMER"<<endl;
    cout<<"2.OWNER"<<endl;
    cin>>m;
    if(m==1)
    {
        cout<<"-----------:WELCOME TO OUR RESTURANT BILLING SYSTEM:-------------------"<<endl<<endl;
    cout<<"_PLEASE CHOOSE FROM OUR MENU_"<<endl<<endl;
    cout<<"PLEASE CHECK OUT OUR VEG PIZZAS"<<endl<<endl;
    cout<<"1.MARGHERITA                                    RS-200/-"<<endl;
    cout<<"2.DOUBLE CHEESE MARGHERITA                      RS-350/-"<<endl;
    cout<<"3.PEPPY PANEER                                  RS-400/-"<<endl;
    cout<<"4.CHEESE AND CORN                               RS-300/-"<<endl;
    cout<<"5.INDI TANDOOORI PANEER                         RS-450/-"<<endl<<endl;
    cout<<"PLEASE CHECK OUT OUR NON-VEG PIZZAS"<<endl<<endl;
    cout<<"6.CHICKEN DOMINATOR                             RS-600/-"<<endl;
    cout<<"7.INDI CHICKEN TIKKA                            RS-550/-"<<endl;
    cout<<"8.CHICKEN SAUSAGE                               RS-600/-"<<endl;
    cout<<"9.PEPPER BARBECUE CHICKEN                       RS-400/-"<<endl;
    cout<<"10.NON-VEG SUPREME                              RS-650/-"<<endl;
    cout<<"PRESS 0 TO EXIT"<<endl<<endl;


    while(n>0 && n<11)
    {
        cout<<"CHOICE "<<count<<":";
        cin>>n;
        if(n>0 && n<11)
        {
            cout<<"CHOICE SAVED SUCCESSFULLY"<<endl;
        }
        count++;
        switch(n)
        {
            case 0:
            cout<<"EXITED SUCCESSFULLY"<<endl<<endl;
            break;

            case 1:
            billamount+=200;
            break;

            case 2:
            billamount+=350;
            break;

            case 3:
            billamount+=400;
            break;

            case 4:
            billamount+=300;
            break;

            case 5:
            billamount+=450;
            break;

            case 6:
            billamount+=600;
            break;

            case 7:
            billamount+=550;
            break;

            case 8:
            billamount+=600;
            break;

            case 9:
            billamount+=400;
            break;

            case 10:
            billamount+=650;
            break;

            default:
            cout<<"WRONG RESPONSE ENTERED"<<endl;
            cout<<"THEREFORE,EXITED SUCCESSFULLY"<<endl<<endl;
            break;
        }
    }
    if(count>0)
    {
        cout<<"PLEASE ENTER YOUR NAME:"<<endl;
        getline(cin,name);
        if(name=="\0")
        {
            getline(cin,name);
        }
        cout<<"PLEASE ENTER YOUR FATHER`S NAME:"<<endl;
        getline(cin,fname);
        if(fname=="\0")
        {
            getline(cin,fname);
        }
        cout<<endl<<"YOU HAVE SUCCESSFULLY CHOOSEN "<<(count-2)<<" PIZZA`S"<<endl;;
        cout<<"YOUR BILLAMOUNT IS="<<billamount<<endl;
        billamount+=billamount*18/100;//In India there is 18% payable gst on all products
        cout<<"AMOUNT AFTER TAXATION="<<billamount<<endl;
        if(billamount>=200)
        {
            if(billamount>=10000)
            {
                billamount-=billamount*50/100;
                cout<<"50 PERCENT DISCOUNT APPLIED"<<endl;
            }
            else if(billamount>=5000)
            {
                billamount-=billamount*40/100;
                cout<<"40 PERCENT DISCOUNT APPLIED"<<endl;
            }
            else if(billamount>=3000)
            {
                billamount-=billamount*30/100;
                cout<<"30 PERCENT DISCOUNT APPLIED"<<endl;
            }
            else if(billamount>=2000)
            {
                billamount-=billamount*20/100;
                cout<<"20 PERCENT DISCOUNT APPLIED"<<endl;
            }
            else if(billamount>=200)
            {
                billamount-=billamount*40/100;
                cout<<"10 PERCENT DISCOUNT APPLIED"<<endl;
            }
            cout<<"AMOUNT AFTER DISCOUNT:-"<<billamount<<endl;
        }
        customer c(name,fname,billamount); 
        ofstream ofs("My.txt",ios::app);
        if(ofs.is_open())
        {
            ofs<<c;
            ofs.close();
        }
    }
    else
    cout<<"PLEASE VISIT AGAIN"<<endl;
    }
    if(m==2)
    {
        cout<<"PLEASE ENTER YOUR PASSWORD:-"<<endl;
        cin>>key;
        if(key==1234)
        {
            cout<<"-----------:OPERATIONS:-------------"<<endl;
        cout<<"1.TO KNOW ALL ORDER`S INFORMATION."<<endl;
        cout<<"2.TO KNOW ABOUT MONEY EARNED TILL NOW."<<endl;
        int o=0;
        cin>>o;
        if(o==1)
        {
            ifstream ifs("My.txt",ios::in);
            while(1)
            {
                ifs>>c;
                if(ifs.eof())
                break;
                cout<<c;
            }
        }
        else if(o==2)
        {
            ifstream ifs("My.txt",ios::in);
            while(1)
            {
                ifs>>c;
                if(ifs.eof())
                break;
                ta+=c.billamount;
            }
            if(ta>0)
            cout<<"TOTAL MONEY EARNED="<<ta<<endl;
            else
            cout<<"NO MONEY EARNED"<<endl;
        }
        else if(o>2 || o<1)
        {
            cout<<"WRONG RESPONSE GIVEN"<<endl;
            cout<<"CODE EXITED SUCESSFULLY"<<endl;
        }
        }
        else
        {
            cout<<"WRONG PASSWORD GIVEN"<<endl;
            cout<<"CODE EXITED SUCESSFULLY"<<endl;
        }
    }
    if(m>2 || m<1)
    {
        cout<<"WRONG RESPONSE GIVEN"<<endl;
        cout<<"CODE EXITED SUCESSFULLY"<<endl;
    }
}