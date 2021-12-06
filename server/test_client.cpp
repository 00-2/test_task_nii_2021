//
//  Weather update client in C++
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
//

#include <zmq.hpp>
#include <iostream>
#include <sstream>
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
    for (update_nbr = 0; update_nbr < 100; update_nbr++) {

        zmq::message_t update;
        Student s = Student();
        std::string deser_s;
        subscriber.recv(update, zmq::recv_flags::none);
        std::istringstream iss(static_cast<char*>(update.data()));
        int size_fn, size_ln;
        std::string first_name,last_name, date;
        char c;
        while(iss >> size_fn >>c >> std::setw(size_fn) >> first_name >> c >> size_ln >> c >> std::setw(size_ln) >> last_name >> c >> date){
            std::cout << " " << first_name <<  " " << last_name  << " "<< date << std::endl;
        }
        std::cout << '\n';
    }
    return 0;
}