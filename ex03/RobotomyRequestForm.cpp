#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecute(executor);
    std::cout << "Trrrrr... drilling noises...\n";
    srand(time(NULL));
    int succes = rand() % 2;
    if (succes == 1)
        std::cout << target << " has been robotomized successfully.\n";
    else
        std::cout << target << " robotomy failed.\n";
}