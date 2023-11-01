#include <iostream>
#include <string>
using namespace std;
class Patient {
public:
// （1） ;
    virtual string getName()=0;

};
class Disposer{
    public:
    // (2);
    virtual void dispose(Patient* patient)=0;

};
class Registry: public Disposer{
    public:
        void dispose(Patient *patient)
        {
            cout<< "I am registering...." << patient->getName() << endl;
        }
};
class Doctor:public Disposer{
    public:
        void dispose(Patient* patient)
        {
            cout << "I am giving medicine...." << patient->getName() << endl;
        }
};
class Pharmacy : public Disposer { // 取药
    public:
        void dispose(Patient *patient) {
        cout << "I am giving medicine...." << patient->getName() << endl;
        }
};
class Facade{
    private:
        Patient* patient;
    public:
        Facade(Patient* patient){this->patient=patient;}
        void dispose()
        {
            Registry* registry=new Registry();
            Doctor* doctor=new Doctor();
            Pharmacy *pharmacy = new Pharmacy();
            registry->dispose(patient);
            doctor->dispose(patient);
            pharmacy->dispose(patient);
        }
};
class ConcretePatient:public Patient{
    private:
        string name;
    public:
        ConcretePatient(string name) { this->name = name; }
        string getName(){return name;}
};
int main() {
    // Patient *patient = （3） ;
    Patient* patinet=new ConcretePatient("hhh");

    //if the parameter is nullptr,it can't work.
    // Patient* patinet=new ConcretePatient(NULL);
    //if the parameter is a empty string,it works.
    // Patient* patinet=new ConcretePatient("");
    // （4） f = （5） ;
    Facade* f=new Facade(patinet);
    // （6） ;
    f->dispose();
    return 0;
}