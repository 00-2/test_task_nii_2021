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
        std::string get_first_name () const;
        std::string get_last_name() const;
        std::string get_surname() const;

    private:
        std::string first_name, last_name, surname;
        tm date;
};

class StudentHashFunction{
    size_t operator()(const Student& ref) const
    {
        return (std::hash<std::string>{}(ref.get_first_name())) ^ (std::hash<std::string>{}(ref.get_last_name())) ^ (std::hash<std::string>{}(ref.get_surname()));
    }
};
