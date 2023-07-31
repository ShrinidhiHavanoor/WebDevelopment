#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,esum,osum;
    cout<<"Enter the array size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements:"<<endl;
    for(i=0;i<n;i++)
    {
        esum+=a[i];
    }
    cout<<"The Even sum is:"<<esum<<endl;
    for(i=1;i<n;i++)
    {
        if(a[2i+1]<n)
        {
            osum+=a[2i+1];
        }
    }
    cout<<"The Odd sum is:"<<osum<<endl;
    cout<<"The Diff of even and odd sum is:"<<esum-osum<<endl;
}
