#include <iostream>
#include <string>

using namespace std;

class Cloneable {
public:
    virtual Cloneable* Clone() = 0;
};

class WorkExperience : public Cloneable {
private:
    string workDate;
    string company;

public:
    void SetWorkExperience(const string &date, const string &comp) {
        workDate = date;
        company = comp;
    }

    Cloneable* Clone() override {
        WorkExperience* obj = new WorkExperience();
        obj->workDate = this->workDate;
        obj->company = this->company;
        return obj;
    }

    void Display() {
        cout << "Work Date: " << workDate << ", Company: " << company << endl;
    }
};

class Resume : public Cloneable {
private:
    string name;
    string sex;
    string age;
    WorkExperience* work;

public:
    Resume(string name) : name(name), work(new WorkExperience()) {}

    void SetPersonalInfo(string sex, string age) {
        this->sex = sex;
        this->age = age;
    }

    void SetWorkExperience(string workDate, string company) {
        work->SetWorkExperience(workDate, company);
    }

    Cloneable* Clone() override {
        Resume* obj = new Resume(*this);
        obj->work = (WorkExperience*)this->work->Clone();
        return obj;
    }

    void Display() {
        cout << "Name: " << name << ", Sex: " << sex << ", Age: " << age << endl;
        work->Display();
    }

    ~Resume() {
        delete work;
    }
};

int main() {
    Resume* a = new Resume("zhangsan");
    a->SetPersonalInfo("male", "29");
    a->SetWorkExperience("1998~2000", "XXXcompany");
    cout<<"&a:" <<a<<endl;
    a->Display(); // Display initial resume
    
    Resume* b = (Resume*)a->Clone();
    b->SetWorkExperience("2001~2006", "YYYcompany");
    cout<<"&b:" <<b<<endl;
    b->Display(); // Display cloned and modified resume

    delete a;
    delete b;

    return 0;
}
