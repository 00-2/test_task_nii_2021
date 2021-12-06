//
//  Weather update client in C++
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
//

#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "code/entities/Student.h"


int main (int argc, char *argv[])
{
    zmq::context_t context (1);

    //  Socket to talk to server
    std::cout << "Collecting updates from weather server...\n" << std::endl;
    zmq::socket_t subscriber (context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");

    //  Subscribe to zipcode, default is NYC, 10001
	const char *filter = (argc > 1)? argv [1]: "10001 ";
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "",0);

    //  Process 100 updates
    int update_nbr;
    long total_temp = 0;
    std::unordered_set<Student,StudentHashFunction> set_from_req;

    for (update_nbr = 0; update_nbr < 100; update_nbr++) {

        zmq::message_t update;
        std::string deser_s;
        subscriber.recv(update, zmq::recv_flags::none);
        std::istringstream iss(static_cast<char*>(update.data()));
        if (update.size()>0){
            int size_fn, size_ln;
            std::string first_name,last_name, s_date;
            char c;
            while(iss >> size_fn >>c >> std::setw(size_fn) >> first_name >> c >> size_ln >> c >> std::setw(size_ln) >> last_name >> c >> s_date){
                //std::cout << " " << first_name <<  " " << last_name  << " "<< date << std::endl;
                tm date;
                std::stringstream ss(s_date);
                char ch;
                ss >> date.tm_mday >> ch >> date.tm_mon >> ch >> date.tm_year;
                set_from_req.insert(Student(first_name,last_name, date));
            }
        }
    }
    std::vector<Student>vec_for_sort(set_from_req.size());
    unsigned int i = 0;
    for (auto entinity:set_from_req){
        vec_for_sort[i] = entinity;
        entinity.set_id(i++);
        std::cout << entinity << std::endl;
    }
    std::cout << "SORTED" << std::endl;
    i = 0;
    std::sort(vec_for_sort.begin(), vec_for_sort.end());
    for (auto entinity:vec_for_sort){
        entinity.set_id(i++);
        std::cout << entinity << std::endl;
    }
}