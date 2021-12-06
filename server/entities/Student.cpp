#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>


Student::Student(std::string first_name,std::string last_name,tm date)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->date = date;    
}
Student::~Student(){}


bool Student::operator==(const Student &ref) const{
    const Student *o = dynamic_cast<const Student*>(&ref);
    if (o==NULL) return false;
    if (o->first_name == this->first_name &&
        o->last_name == this->last_name &&
        o->date.tm_year == this->date.tm_year &&
        o->date.tm_mon == this->date.tm_mon &&
        o->date.tm_mday == this->date.tm_mday
        ) return true;
    return false;
}
std::istream& operator>>(std::istream& is, Student & ref){
    std::string s_date;
    unsigned int number;
    is >> number >> ref.first_name >> ref.last_name >> s_date;
    std::stringstream ss(s_date);
    char ch;
    ss >> ref.date.tm_mday >> ch >> ref.date.tm_mon >> ch >> ref.date.tm_year;
    return is;
}

std::ostream& operator<<(std::ostream& os, Student & ref){
    os << ref.id << " " << ref.first_name << " " << ref.last_name << " " << ref.date.tm_mday<<"."<<ref.date.tm_mon<<"."<<ref.date.tm_year;
    return os;
}
std::string serialize(Student & ref){
    std::stringstream ss;
    ss << ref.first_name.size() <<"," << ref.first_name << ","<< ref.last_name.size() <<"," << ref.last_name << "," << ref.date.tm_mday<<"."<<ref.date.tm_mon<<"."<<ref.date.tm_year;
    return ss.str();
}
std::string Student::get_first_name() const{
    return this->first_name;
}

std::string Student::get_last_name() const{
    return this->last_name;
}
tm Student::get_date() const{
    return this->date;
}