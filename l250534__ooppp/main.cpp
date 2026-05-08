


#include "RegularStudent.h"
#include <iostream>
    using namespace std;

    int main()
    {
        RegularStudent s1("24K-1234", "Meerab", "meerab@gmail.com");

        s1.addGrade(85);
        s1.addGrade(90);
        s1.addGrade(78);

        s1.displayProfile();
        s1.viewTranscript();

        return 0;
    }
  