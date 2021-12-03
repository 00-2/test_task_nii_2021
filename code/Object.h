#include <string>
class Object
{
    private:
        unsigned int id;
    public:
        virtual bool operator>>(const Object &ref) = 0;
        virtual std::string to_req() = 0;
};