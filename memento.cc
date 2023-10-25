#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Memento{
    private:
        string state;
    public:
        Memento(string state){this->state=state;}
        string getState(){return state;}
};
class Originator{
    private:
        string state;
    public:
        void setState(string state){this->state=state;}
        string getState(){return state;}
        Memento saveStateToMemento(){
            // return (1)
            return Memento(this->state);
        }
        void getStateFromMemento(Memento Memento)
        {
            // state=(2);
            state= Memento.getState();
        }
};
class CareTaker{
    private:
        vector<Memento> mementoList;
    public:
    // void (3){mementoList.push_back(state);}
    void add(Memento state)
    {
        mementoList.push_back(state);
    }
    // void 
    // (4){return mementoList[index];}
    Memento get(int index){return mementoList[index];}
};
//my version ,some wrong there.
// new Memento(this->state);
// memento->state
// add(state)
// Memento get(int index)
// originator->getState()
// originator->getState()

int main()
{
    Originator* originator=new Originator();
    CareTaker* careTaker=new CareTaker();
    originator->setState("State #1");
    originator->setState("State #2");
    // careTaker->add((5));
    careTaker->add(originator->saveStateToMemento());
    originator->setState("State #3");
    // careTaker->add((6));
    careTaker->add(originator->saveStateToMemento());
    originator->setState("State #4");
    cout << "Current State：" + originator->getState() << endl;
    originator->getStateFromMemento(careTaker->get(0));
    cout << "First saved State：" + originator->getState() << endl;
    originator->getStateFromMemento(careTaker->get(1));
    cout << "Second saved State：" + originator->getState() << endl;
    
    return 0;
}