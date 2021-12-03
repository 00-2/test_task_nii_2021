#include "IComparable.h"
#include "Object.h"
#include <ctime>

class Student:public IComparable,private Object
{
    public:
        Student(std::string first_name,std::string last_name,std::string surname, tm date);
        ~Student();
        virtual bool operator==(const IComparable &ref);
        friend std::istream& operator>>(std::istream& is, Student &ref);
        friend std::ostream& operator<<(std::ostream& os, Student &ref);
    private:
        std::string first_name, last_name, surname;
        tm date;
};