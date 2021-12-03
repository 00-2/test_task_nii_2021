#include "IComparable.h"
#include "Object.h"
#include <ctime>

class Student:private Object
{
    public:
        Student(std::string first_name,std::string last_name,tm date);
        Student(){};
        ~Student();
        bool operator==(const Student &ref) const;
        friend std::istream& operator>>(std::istream& is, Student &ref);
        friend std::ostream& operator<<(std::ostream& os, Student &ref);
        void set_id(unsigned int id){ this->id = id;}
        std::string get_first_name () const;
        std::string get_last_name() const;
        std::string get_surname() const;
        tm get_date() const;
    private:
        std::string first_name, last_name;
        tm date;
};

class StudentHashFunction{
    public:
    size_t operator()(const Student& ref) const
    {
        return (std::hash<std::string>{}(ref.get_first_name())) ^ (std::hash<std::string>{}(ref.get_last_name()));
    }
};
