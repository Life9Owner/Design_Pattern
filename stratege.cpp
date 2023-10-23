#include <iostream>
using namespace std;

class Interval;
class PrintStrategy {
    public:
            //    （1）      ;
};
class Interval {
    private:
        double lowerBound;
        double upperBound;

    public:
        Interval(double p_lower, double p_upper) {
               lowerBound = p_lower;
               upperBound = p_upper;

        }
        void printInterval(PrintStrategy*ptr){
                        // （2）      ;

        }
        double getLower() {   return lowerBound;    }
        double getUpper() {   return upperBound;    }

};

class PrintIntervalsComma : public PrintStrategy {
    public:
        void doPrint(Interval *val) {
            cout << "[" << val->getLower() << "," << val->getUpper() << "]" << endl; }

};

class PrintIntervalsDots : public PrintStrategy {
    public:
         void doPrint(Interval *val) {

             cout << "[" << val->getLower() << "..." << val->getUpper() << "]" << endl; }

};

class PrintIntervalsLine:public PrintStrategy {
    public:
        void doPrint(Interval *val) {
            cout << "[" << val->getLower() << "-" << val->getUpper() << "]" << endl; }

};

enum TYPE {COMMA, DOTS, LINE};
PrintStrategy* getStrategy(int type) {
    PrintStrategy* st;
    switch(type){
        case COMMA:
                //    （3）      ;
           break;
        case DOTS:
                //    （4）      ;
           break;
        case LINE:
                //    （5）      ;
           break;

         }
         return st;

}

int main() {
        Interval a(1.7,2.1);
        a.printInterval(getStrategy(COMMA));
        a.printInterval(getStrategy(DOTS));
        a.printInterval(getStrategy(LINE));
        return 0;

}