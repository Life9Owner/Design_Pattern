#include<string>
using namespace std;
class Cloneable{
    public:
    // (1);
    virtual Cloneable* Clone()=0;
};
class WorkExperience:public Cloneable{
    private:
        string workDate;
        string company;
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

};
class Resume:public Cloneable{
    private:
        string name; string sex; string age;
        WorkExperience* work;
        Resume(WorkExperience* work)
        {
            // this->work=(3);
            this->work=work;//mine, wrong one
            // this->work=(WorkExperience *)work->Clone();
        }
    public:
        Resume(string name)
        {
             //... the other codes remain empty.
        }
        void SetPersonalInfo(string sex,string age)
        {
            //... the other codes remain empty.
        }
        void SetWorkExperience(string workDate,string company)
        {
             //... the other codes remain empty.
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

};
int main()
{
    Resume* a=new Resume("zhangsan");
    a->SetPersonalInfo("male","29");
    a->SetWorkExperience("1998~2000","XXXcompany");
    // Resume* b=(5);
    // Resume* b=a->Clone();//mine ,wrong one
    Resume* b=(Resume*)a->Clone();//error
    b->SetWorkExperience("2001~2006","YYYcompany");
    return 0;
}