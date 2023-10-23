#include <iostream>
#include <vector>
#include<algorithm>
class Observer {
public:
    virtual void update() = 0;
};

class Subject {
public:
    virtual void Attach(Observer* obs) = 0;
    virtual void Detach(Observer* obs) = 0;
    virtual void Notify() = 0;
    virtual void setStatus(int status) = 0;
    virtual int getStatus() = 0;
};

class OfficeDoc : public Subject {
private:
    std::vector<Observer*> myObs;
    std::string mySubjectName;
    int m_status;

public:
    OfficeDoc(std::string name) {
        mySubjectName = name;
        m_status = 0;
    }

    void Attach(Observer* obs) {
        myObs.push_back(obs);
    }

    void Detach(Observer* obs) {

        myObs.erase(std::remove(myObs.begin(), myObs.end(), obs), myObs.end());
        // auto it = std::find(myObs.begin(),myObs.end(), obs);
        // if (it != myObs.end()) {
        //     myObs.erase(it);
        // }
    }

    void Notify() {
        for (Observer* obs : myObs) {
            obs->update();
        }
    }

    void setStatus(int status) {
        m_status = status;
        std::cout << "SetStatus subject[" << mySubjectName << "] status:" << status << std::endl;
    }

    int getStatus() {
        return m_status;
    }
};

class DocExplorer : public Observer {
private:
    std::string myObsName;

public:
    DocExplorer(std::string name, Subject* sub) {
        myObsName = name;
        sub->Attach(this);
    }

    void update() {
        std::cout << "update observer[" << myObsName << "]" << std::endl;
    }
};

int main() {
    // std::cout << "Hello World" << std::endl;
    Subject* subjectA = new OfficeDoc("subject A");
    Observer* observerA = new DocExplorer("observer", subjectA);
    subjectA->setStatus(1);
    subjectA->Notify();
    // "update observer[observer]" is printed when subjectA->Notify(); is called,
    // and it invokes the update method of observerA.

    delete observerA;
    delete subjectA;

    return 0;
}
