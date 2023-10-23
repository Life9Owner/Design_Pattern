#include<string>
#include<iostream>
using namespace std;
class Cloneable{
    public:
    // (1);
    virtual Cloneable* Clone()=0;
};
class WorkExperience:public Cloneable{
    // private:
    public:
        string workDate;
        string company;
        WorkExperience(){}
        WorkExperience(string workDate,string company):
        workDate(workDate),company(company){}
       
    public:
        Cloneable* Clone()
        {
            //(2);
            WorkExperience* obj=new WorkExperience();
            obj->workDate=this->workDate;
            obj->company=this->company;
            return obj;
        }


        //... the other codes remain empty.
        virtual ~WorkExperience() {}
};
class Resume:public Cloneable{
    private:
        string name; string sex; string age;
        WorkExperience* work;
        
        Resume(WorkExperience* work)
        {
            // this->work=(3);
            // this->work=work;//mine, wrong one
               this->work = (WorkExperience*)work->Clone();
        }
        
    public:
        Resume(string name)
        {
             //... the other codes remain empty.
             this->name=name;
             this->work=new WorkExperience();
        }
        void SetPersonalInfo(string sex,string age)
        {
            //... the other codes remain empty.
            this->age=age;
        }
        void SetWorkExperience(string workDate,string company)
        {
             //... the other codes remain empty.
             this->work->workDate=workDate;
             this->work->company=company;
        }
        Cloneable* Clone()
        {
            // (4);
            Resume* obj=new Resume(this->work);
            obj->name=this->name;
            obj->sex=this->sex;
            obj->age=this->age;
            return obj;
        }
        void display()
        {
            cout<<this->name<<" "<<this->age<<" "<<
            this->work->workDate<<" "<<this->work->company<<endl;
        }
        // In Resume class
        ~Resume() {
            delete work;
        }

};
int main()
{
    Resume* a=new Resume("zhangsan");
    a->SetPersonalInfo("male","29");
    a->SetWorkExperience("1998~2000","XXXcompany");
    // Resume* b=(5);
    // Resume* b=a->Clone();//mine ,wrong one
    std::cout<<"&a:"<<a;a->display();
    Resume* b=(Resume*)a->Clone();//error
    b->SetWorkExperience("2001~2006","YYYcompany");
    std::cout<<"&b:"<<b;b->display();
    return 0;
}