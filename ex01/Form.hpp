#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Form
{
    private:
        const std::string name;
        bool sign;
        int const  sign_grade;
        int const exec_grade;
    public:
        Form();
		Form(std::string name, int sign_grade, int exec_grade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

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


std::ostream& operator<<(std::ostream& out, Form& f);


#endif