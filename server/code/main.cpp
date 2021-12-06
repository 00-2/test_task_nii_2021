#include "entities/Student.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <ctime>

const std::string subdir = "../files/";
const std::vector<std::string> name_of_files{"student_file_1.txt","student_file_2.txt"};


//zeromq server
#include <zmq.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if (defined (WIN32))
#include <zhelpers.hpp>
#endif

#define within(num) (int) ((float) num * random () / (RAND_MAX + 1.0))

void start_server(std::unordered_set<Student,StudentHashFunction>& set_from_files) {
    std::cout << "START SERVER" << std::endl;
    
    //  Prepare our context and publisher
    zmq::context_t context (1);
    zmq::socket_t publisher (context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5556");
    // tm date;
    // std::string date_string = "30.9.1988";
    // strptime(date_string.c_str(), "%d.%m.%Y", &date);
    // Student s = Student("name", "sec", date);
    unsigned int i;
    std::stringstream set_ser;
    for(Student entitity:set_from_files){
        std::string entitity_ser = serialize(entitity);
        set_ser << entitity_ser << "\n";
    }
    std::cout << set_ser.str();
    while (1) {
        //  Send message to all subscribers
        zmq::message_t request((void*)set_ser.str().c_str(), set_ser.str().size()+1, NULL);
        publisher.send(request, zmq::send_flags::none);
    }
    
}


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


// create thread for zeromq - send
// create thread for updating files -> name_of_files 



int main(){
    tm date;
    std::string date_string = "30.9.1988";
    strptime(date_string.c_str(), "%d.%m.%Y", &date);
    //printf("%d %d %d", date.tm_mday, date.tm_mon, date.tm_year);
    Student s = Student("name", "sec", date);
    //std::cout << s;
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
            else{
                temp.set_id(i);
                std::cout << temp << std::endl;
                std::cout << "\tdate:not ok" <<std::endl;
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

    start_server(set_from_files);



}