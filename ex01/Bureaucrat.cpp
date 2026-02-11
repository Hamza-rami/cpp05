#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low";
}

void Bureaucrat::increment()
{
    grade--;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}


void Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName()  << " signed " << f.GetName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        std::cout << this->getName() << " couldn’t sign " << f.GetName() << " because ...\n";
    }
    
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
    out << b.getName() << " ,bureaucrat grade " << b.getGrade();
    return out;
}