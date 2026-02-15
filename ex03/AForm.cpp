#include "AForm.hpp"


AForm::AForm(): name("default"), sign_grade(150), exec_grade(100)
{
    sign = false;
}

AForm::~AForm()
{}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException();
    sign = false;
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign),
                                sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return *this;
}

std::string AForm::GetName() const
{
    return this->name;
}

bool AForm::GetSign() const
{
    return this->sign;
}

int AForm::GetSingGrade() const
{
    return this->sign_grade;
}

int AForm::GetSignExec() const
{
    return this->exec_grade;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "Name "<< f.GetName() << " Sign " << f.GetSign() << " Sign Grade " << f.GetSingGrade() << " Sign exec " << f.GetSignExec();
    return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form Not Signed";
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->GetSingGrade())
        throw AForm::GradeTooLowException();
    else
        sign = true;
}

void AForm::checkExecute(Bureaucrat const & executor) const
{
    if (!sign)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > exec_grade)
        throw AForm::GradeTooLowException();
}
