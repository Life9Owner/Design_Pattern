#include<iostream>
#include<string>
using namespace std;
class Pizza{
    private:
        string parts;
    public:
        void setParts(string parts){this->parts=parts;}
        string getParts(){return parts;}
        
};
class PizzaBuilder{
    protected:Pizza* pizza;
    public:
        Pizza* getPizza(){return pizza;}
        void createNewPizza(){pizza=new Pizza();}
        // (1);
        virtual void buildParts()=0;

};
class HawiianPizzaBuilder:public PizzaBuilder{
    public:
        void buildParts(){pizza->setParts("cross+mild+ham&pineapple");}
};
class SpicyPizzaBuilder:public PizzaBuilder{
    public:
        void buildParts(){
            pizza->setParts("pan baked+hot+pepperoni&salami");
        }

};
class Waiter{
    private:
        PizzaBuilder* pizzaBuilder;
    public:
        void setPizzaBuilder(PizzaBuilder* pizzaBuilder)
        {
            //(2);
            this->pizzaBuilder=pizzaBuilder;
        }
        Pizza* getPizza(){return pizzaBuilder->getPizza();}
        void construct(){
            pizzaBuilder->createNewPizza();
            // (3);
            pizzaBuilder->buildParts();

        }
};
int main()
{
    Waiter*waiter=new Waiter();
    PizzaBuilder* hawiian_PizzaBuilder=new HawiianPizzaBuilder();
    //(4);
    waiter->setPizzaBuilder(hawiian_PizzaBuilder);
    //(5);
    waiter->construct();
    cout<<"pizza: "<<waiter->getPizza()->getParts()<<endl;
    return 0;
}