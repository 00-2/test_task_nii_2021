#include "entities/Student.h"
#include <iostream>
int main(){
    tm date;
    std::string date_string = "30.9.1988";
    strptime(date_string.c_str(), "%d.%m.%Y", &date);
    //printf("%d %d %d", date.tm_mday, date.tm_mon, date.tm_year);
    Student s = Student("name", "sec", "sur", date);
    Student s1 = Student("name", "test", "sur", date);
    std::cin >> s;
    std::cout << s;
}