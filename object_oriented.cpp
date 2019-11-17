

// friend class
// friend function

class Employee
{
public:     
  char* name;
  
private:     // NOTE; Only this class and friend classes can see within.
  int id;

protected:  // NOTE: Inherited classes and friend classes can see withi
  char gender;
  int age;
  
};


class SoftwareEngineer: public Employee
{

protected:
  int income;
};
