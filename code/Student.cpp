#include "Student.h"

bool Student::operator==(const IComparable &ref){
    const Student *o = dynamic_cast<const Student*>(&ref);
    if (o==NULL) return false;
    if (o->first_name == this->first_name &&
        o->last_name == this->last_name &&
        o->surname == this->surname && 
        o->date.tm_year == this->date.tm_year &&
        o->date.tm_mon == this->date.tm_mon &&
        o->date.tm_mday == this->date.tm_mday
        ) return true;
    return false;
}

Student::Student(std::string first_name,std::string last_name,std::string surname, tm date)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->surname = surname;
    this->date = date;    
}
Student::~Student(){}
