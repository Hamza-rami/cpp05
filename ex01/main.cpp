#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat qq("Rami", 1);
    std::cout << qq << std::endl;
    try 
    {
        qq.decrement();
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what();
    };
}
