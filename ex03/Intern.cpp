#include "Intern.hpp"


Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* make_shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* make_robotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* make_presidential(std::string target)
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string Box[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*ptr[])(std::string target) = 
    {
        &make_shrubbery,
        &make_robotomy,
        &make_presidential
    };
    for (int i = 0; i < 3; i++)
    {
        if (Box[i] == formName)
            return ptr[i](target);
    }
    throw std::runtime_error("Form not found");
    return NULL;
}