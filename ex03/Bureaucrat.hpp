#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;
class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    void signForm(AForm& f);
    void executeForm(AForm const & form) const;
};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
#endif