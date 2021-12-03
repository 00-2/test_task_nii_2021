#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>
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
std::istream& operator>>(std::istream& is, Student & ref){
    std::string s_date;
    unsigned int number;
    std::cin >> number >> ref.first_name >> ref.last_name >> ref.surname >> s_date;
    std::stringstream ss(s_date);
    char ch;
    ss >> ref.date.tm_mday >> ch >> ref.date.tm_mon >> ch >> ref.date.tm_year;
    return is;
}

std::ostream& operator<<(std::ostream& os, Student & ref){
    std::cout << ref.id << " " << ref.first_name << " " << ref.last_name << " " << ref.surname << " " << ref.date.tm_mday<<"."<<ref.date.tm_mon<<"."<<ref.date.tm_year;
    return os;
}

Student::Student(std::string first_name,std::string last_name,std::string surname, tm date)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->surname = surname;
    this->date = date;    
}
Student::~Student(){}
