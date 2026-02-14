#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat b("rami", 1);
    ShrubberyCreationForm c("hhh");
    RobotomyRequestForm d("jjj");
    PresidentialPardonForm a("kkk");
    b.signForm(a);
    b.executeForm(a);
    return 0;
}
