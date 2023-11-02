#include<iostream>
using namespace std;
class FrequentFlyer;class CBasic;class CSilver;class CGold;class CNoCustomer;
class CState{
    private:
        int flyMiles;
    public:
        // (1);
        virtual double travel(int miles,FrequentFlyer* context)=0;
};

class FrequentFlyer{
    friend class CBasic;
    friend class CSilver;
    friend class CGold;
    private:
        CState* state;CState* nocustomer;CState* basic;CState* silver;CState* gold;
        double flyMiles;
    public:
        FrequentFlyer(){
            //why it is declared but the compiler tells me it isn't declared.
            // state=new CNoCustomer();
            flyMiles=0;
            setState(nocustomer);
        }
        void setState(CState* state)
        {
            this->state=state;
        }
        void travel(int miles)
        {
            double bonusMiles=state->travel(miles,this);
            flyMiles=flyMiles+bonusMiles;
        }

};
class CNoCustomer:public CState{
    public:
        double travel(int miles,FrequentFlyer* context)
        {
            cout<<"Your travel will not account for points\n";
            return miles;
        }
   
};
class CBasic:public CState{
    public:
        double travel(int miles,FrequentFlyer* context)
        {
            if(context->flyMiles>=25000&&context->flyMiles<50000)
            {
                // (2);
                context->setState(context->silver);

            }
            if(context->flyMiles>50000)
            {
                // (3)
                context->setState(context->gold);
            }
            return miles;
        }
   
};
class CGold:public CState{
    public:
        double travel(int miles,FrequentFlyer* context)
        {
            if(context->flyMiles>=25000&&context->flyMiles<50000)
            {
                // (4);
                context->setState(context->silver);
            }
            if(context->flyMiles<25000)
            {
                // (5)
                context->setState(context->basic);
            }
            return miles+0.5*miles;
        }
   
};
class CSilver:public CState{
    public:
        double travel(int miles,FrequentFlyer* context)
        {
            if(context->flyMiles<=25000)
            {
                context->setState(context->basic);
            }
            if(context->flyMiles>=50000)
            {
                context->setState(context->gold);
            }
            return miles+0.25*miles;
        }
   
};
int main() {
    FrequentFlyer traveler;

    // Simulate travel and accumulate miles
    traveler.travel(1000);  // Travel without being a customer
    traveler.travel(30000); // Reach the Basic level
    traveler.travel(10000); // Stay in the Basic level
    traveler.travel(30000); // Upgrade to Silver
    traveler.travel(50000); // Upgrade to Gold

    // Additional travel after reaching Gold
    traveler.travel(2000);

    return 0;
}
