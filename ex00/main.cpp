#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat qq("Rami", 150);
        std::cout << qq << std::endl;
        qq.decrement();
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what();
    };
}
