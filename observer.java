import java.util.*;
interface Observer{public void update();}//public (1);
interface Subject{
    public void Attach(Observer obs);
    public void Detach(Observer obs);
    public void Notify();
    public void setStatus(int status);
    public int getStatus();
}
class OfficeDoc implements Subject{
    private List<Observer> myObs;//list<2>
    private String mySubjectName;
    private int m_status;
    public OfficeDoc(String name)
    {
        mySubjectName=name;
        this.myObs=new ArrayList<Observer>();
        m_status=0;
    }
    public void Attach(Observer obs){this.myObs.add(obs);}
    public void Detach(Observer obs){this.myObs.remove(obs);}
    public void Notify(){
        for(Observer obs:this.myObs)
        {
            obs.update();//(3)
        }
    }
    public void setStatus(int status)
    {
        m_status=status;
        System.out.println("SetStatus subject["+mySubjectName+
        "] status:"+status);
    }
     public int getStatus(){return m_status;}
    
}
class DocExplorer implements Observer{
    private String myObsName;
    public DocExplorer (String name,Subject sub)//,(4) sub
    {
        myObsName=name;
        sub.Attach(this);
    }
    public void update(){
        System.out.println("update observer["+myObsName+"]");
    }
   
}
class ObserverTest{
    public static void main(String[] args)
    {
        // System.out.println("Hello World");
        Subject subjectA=new OfficeDoc("subject A");
        Observer observerA=new DocExplorer("observer",subjectA);
        subjectA.setStatus(1);
        subjectA.Notify();
        // "update observer[observer]" is printed when subjectA.Notify(); /-
        // is called, and it invokes the update method of observerA.
       
    }

}