#include<iostream>
using namespace std;
class Address{
    public:
        void street(){cout<<"English mode:street"<<endl;}
        void zip(){cout<<"English mode:zip"<<endl;}
        void city(){cout<<"English mode:city"<<endl;}
};
class DutchAddress{
    public:
    virtual void straat()=0;
    virtual void postcode()=0;
    virtual void plaats()=0;
};
class DutchAddressAdapter:public DutchAddress{
    private:
        // (1);
        Address* address;
    public:
        DutchAddressAdapter(Address* addr)
        {
            address=addr;
        }
        void straat(){
            // (2);
            address->street();
        }
        void postcode()
        {
            //(3);
            address->zip();
        }
        void plaats()
        {
            //(4);
            address->city();
        }

        //...
        
};
void testDutch(DutchAddress* addr)
{
    addr->straat();
    addr->postcode();
    addr->plaats();
}
int main()
{
    Address* addr=new Address();
    // (5);
    // DutchAddressAdapter* addrAdapter=new DutchAddressAdapter(addr);/*may wrong*/
    //
    DutchAddress *addrAdapter=new DutchAddressAdapter(addr);
    cout<<"\n The DutchAddress\n"<<endl;
    testDutch(addrAdapter);
    return 0;
}