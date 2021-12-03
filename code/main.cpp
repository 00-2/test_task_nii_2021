#include "entities/Student.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <fstream>

const std::string subdir = "../files/";
const std::vector<std::string> name_of_files{"student_file_1.txt","student_file_2.txt"};

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
    
    /*vector<People> people;
    People temp;
    while (fin >> temp.name >> temp.surname >> temp.years) {
        people.push_back(temp);
    }
    */
    }
}