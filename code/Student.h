#include "IComparable.h"
#include "Object.h"
#include <ctime>

class Student:public IComparable, private Object
{
    public:
        Student(std::string first_name,std::string last_name,std::string surname, tm date);
        ~Student();
        virtual bool operator==(const IComparable &ref);
        virtual bool operator>>(const Object &ref){};
        virtual std::string to_req(){};
    private:
        std::string first_name, last_name, surname;
        tm date;
};