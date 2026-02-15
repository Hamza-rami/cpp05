#include "Form.hpp"


Form::Form(): name("default"), sign_grade(150), exec_grade(100)
{
    sign = false;
}

Form::~Form()
{}

Form::Form(std::string name, int sign_grade, int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
    sign = false;
}

Form::Form(const Form& other) : name(other.name), sign(other.sign),
                                sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return *this;
}

std::string Form::GetName() const
{
    return this->name;
}

bool Form::GetSign() const
{
    return this->sign;
}

int Form::GetSingGrade() const
{
    return this->sign_grade;
}

int Form::GetSignExec() const
{
    return this->exec_grade;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Name "<< f.GetName() << " Sign " << f.GetSign() << " Sign Grade " << f.GetSingGrade() << " Sign exec " << f.GetSignExec();
    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low";
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->GetSingGrade())
        throw Form::GradeTooLowException();
    else
        sign = true;
}