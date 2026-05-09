#include <string>
using namespace std;

class Assessment {

protected:
    string type;
    double rawScore;
    double maxScore;
    double weightage;

public:
    Assessment(string type, double rawScore, double maxScore, double weightage);
    virtual double calculateWeightedScore() = 0;//abstarct class
    virtual void   display() = 0;
    string getType();
    double getRawScore();
    double getMaxScore();
    double getWeightage();
    virtual ~Assessment();
};