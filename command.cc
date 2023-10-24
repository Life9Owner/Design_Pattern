#include<iostream>
using namespace std;
class Light{
    string name;
    public:
        Light(string name){this->name=name;}
        void on(){cout<<this->name<<" "<<"Light on"<<endl;}//open the light
        void off(){cout<<this->name<<" "<<"Light off"<<endl;}
};
class Command{
    public:
    // (1)
    virtual void excuate()=0;
};
class LightOnCommand:public Command{
    private:
        Light* light;
    public:
        LightOnCommand(Light* light){this->light=light;}
        void excuate()override{
            // (2);
            light->on();
            
        }
};
class LightOffCommand:public Command{
    private:
        Light* light;
    public:
        LightOffCommand(Light* light)
        {
            this->light=light;
        }
        void excuate()override{
            // (3);
           light->off();
        }
};
class RemoteControl{
    private:
        Command* onCommands[7];
        Command* offCommands[7];
    public:
        RemoteControl(){/*This paragraph is omitted*/}
        void setCommand(int slot,Command* onCommand,Command* offCommand)
        {
        //     (4)=onCommand;
        onCommands[slot]=onCommand;
        //     (5)=offCommand;
        offCommands[slot]=offCommand;
        }
        void onButtonWasPushed(int slot){
            // (6);
            onCommands[slot]->excuate();
        }
        void offButtonWasPushed(int slot){
            //(7);
            offCommands[slot]->excuate();
        }
};
int main()
{
    RemoteControl* remoteControl=new RemoteControl();
    Light* livingRoomLight=new Light("Living Room");
    Light* kitchenLight=new Light("Kitchen");
    LightOnCommand* livingRoomLightOn=new LightOnCommand(livingRoomLight);
    LightOffCommand* livingRoomLightOff=new LightOffCommand(livingRoomLight);
    LightOnCommand* kitchenLightOn=new LightOnCommand(kitchenLight);
    LightOffCommand* kitchenRoomLightOff=new LightOffCommand(kitchenLight);
    remoteControl->setCommand(0,livingRoomLightOn,livingRoomLightOff);
    remoteControl->setCommand(1,kitchenLightOn,kitchenRoomLightOff);
    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(1);
    remoteControl->offButtonWasPushed(1);

    return 0;

}