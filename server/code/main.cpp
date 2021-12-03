#include "entities/Student.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <ctime>


const std::string subdir = "../files/";
const std::vector<std::string> name_of_files{"student_file_1.txt","student_file_2.txt"};

bool date_valid(tm &date){ 
    int vyear = date.tm_year;
    int vmonth = date.tm_mon;
    int vday = date.tm_mday;
    time_t r = mktime(&date);
    if (r == -1 || (vday != date.tm_mday) || (vmonth != date.tm_mon) || (vyear != date.tm_year)) {
      return false;
    }
    return true;
}


int main(){
    //tm date;
    //std::string date_string = "30.9.1988";
    //strptime(date_string.c_str(), "%d.%m.%Y", &date);
    //printf("%d %d %d", date.tm_mday, date.tm_mon, date.tm_year);
    //Student s = Student("name", "sec", "sur", date);
    //Student s1 = Student("name", "test", "sur", date);
    //std::cin >> s;
    // work with file
    std::unordered_set<Student,StudentHashFunction> set_from_files;
    
    //
    //set_from_files.insert(s);
    //set_from_files.insert(s1);
    //for (Student elem: set_from_files) {
    //    std::cout << elem << "\n";
    //}


    std::cout << "Subdirectory:" << subdir<< std::endl;
    for (std::string name_of_file : name_of_files){
        std::cout <<"Work with:" << name_of_file << std::endl;
        std::ifstream fin;
        fin.open(subdir+name_of_file);
        if (!fin) {
            std::cerr << "Error in opening the file:"<< name_of_file << std::endl;
        }
        Student temp;
        unsigned int i = 0;
        while (fin >> temp) {
            // for check date
            tm temp_date;
            temp_date.tm_mon = temp.get_date().tm_mon;
            temp_date.tm_year = temp.get_date().tm_year;
            temp_date.tm_mday = temp.get_date().tm_mday;
            if (date_valid(temp_date)){
                set_from_files.insert(temp);
                temp.set_id(i);
                std::cout << temp << std::endl;
                std::cout << "\tdate:ok" <<std::endl;
            }
            i++;
        }
    }
    std::cout << "All files completed.\n\nResult:\n";
    unsigned int i = 0;
    for (auto entinity:set_from_files){
        entinity.set_id(i++);
        std::cout << entinity << std::endl;
    }
}