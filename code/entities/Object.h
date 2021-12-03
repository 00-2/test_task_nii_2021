#include <string>
class Object
{
    protected:
        unsigned int id;
    public:
        unsigned int get_id(){return id;}
        void set_id(unsigned int id){ this->id = id;}
};