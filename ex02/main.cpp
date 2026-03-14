#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    try
    {
        Bureaucrat b("rami", 5);
        ShrubberyCreationForm c("hhh");
        RobotomyRequestForm d("jjj");
        PresidentialPardonForm a("kkk");
        b.signForm(d);
        b.executeForm(d);
        b.signForm(c);
        b.executeForm(c);
        b.signForm(a);
        b.executeForm(a);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
