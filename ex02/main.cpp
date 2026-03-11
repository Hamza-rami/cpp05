#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    Bureaucrat b("rami", 15);
    ShrubberyCreationForm c("hhh");
    RobotomyRequestForm d("jjj");
    PresidentialPardonForm a("kkk");
    b.signForm(d);
    b.executeForm(d);
    b.signForm(c);
    b.executeForm(c);
    return 0;
}
