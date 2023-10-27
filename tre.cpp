#include<list>
#include<iostream>
#include<string>
using namespace std;
class AbstractFile{
protected:
	string name;//file or folder name
public:
	void printName(){cout<<name<<endl;}
    virtual void addChild(AbstractFile *file)=0;
    virtual void removeChild(AbstractFile *file)=0;
    virtual list<AbstractFile*> *getChildren()=0;//get the descent of the file or folder;
};

class File:public AbstractFile{
    public:
        File(string name){
            // (1)
            this->name=name;
        }
        void addChild(AbstractFile *file){return;}
        //no Child,but it should be kept to the same structure
        void removeChild(AbstractFile* file){return ;}
        // (2) 
        list<AbstractFile*> *getChildren(){
        // -- (3);
            // return this->;
        //    list<AbstractFile*> *childList = new list<AbstractFile*>; // (3) Create a list to return.
            return nullptr;
         }
};
class Folder:public AbstractFile{
    private:
    list<AbstractFile*> childList;
    public:
        Folder(string name){
            // (4)
            this->name=name;
            }
        void addChild(AbstractFile *file)
        {
            childList.push_back(file);
        }
        void removeChild(AbstractFile* file)
        {
            childList.remove(file);
        }
        virtual list<AbstractFile*>* getChildren()
        {
            // return (5);
            return &childList;
        }
};
void printTree(AbstractFile* ifile);
int main()
{
    AbstractFile* rootFolder=new Folder("C:\\");
    AbstractFile* compositeFolder=new Folder("composite");
    AbstractFile* windowsFolder=new Folder("windows");
    AbstractFile* file=new File("Testcompposite.cc");
    rootFolder->addChild(compositeFolder);
    rootFolder->addChild(windowsFolder);
    compositeFolder->addChild(file);
    printTree(rootFolder);
    return 0;
}
void printTree(AbstractFile* ifile)
{
    ifile->printName();
    list<AbstractFile*>* children=ifile->getChildren();
    if(children==nullptr)return ;
    // for(AbstractFile* file:children)
    // {
    //     printTree(file);
    // }
    // for(list<AbstractFile*>::iterator it=children->begin();it!=children->end();it++)
    // {
    //     printTree(*it);
    // }
    for(auto file:*children)
    {
        printTree(file);
    }
}
