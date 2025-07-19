#include <iostream>
using namespace std;

class Employee {
public:
    void work() {
        cout << "Employee working" << endl;
    }
    void report() {
        cout << "Employee reporting" << endl;
    }
};

class Manager : public Employee {
};

class Intern : private Employee {
public:
    void doInternWork() {
        work();
    }
};

class TeamLead : protected Employee {
public:
    void leadTeam() {
        work();
    }
};

int main() {
    Manager m;
    m.work();
    m.report();

    Intern i;
    i.doInternWork();

    TeamLead t;
    t.leadTeam();
  

    return 0;
}
