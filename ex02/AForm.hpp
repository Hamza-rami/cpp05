#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class AForm
{
    private:
        const std::string name;
        bool sign;
        int const  sign_grade;
        int const exec_grade;
    public:
        AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        std::string GetName() const;
        bool GetSign() const;
        int GetSingGrade() const;
        int GetSignExec() const;

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
		void beSigned(Bureaucrat& b);
};


std::ostream& operator<<(std::ostream& out, AForm& f);


#endif