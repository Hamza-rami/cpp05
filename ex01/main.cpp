#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("Rami", 70);
        Form f("Hajji", 70, 8);
        b.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}
