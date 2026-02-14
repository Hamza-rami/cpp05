#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
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
        virtual ~AForm();
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
        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };
		void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;
    protected:
        void checkExecute(Bureaucrat const & executor) const;
};


std::ostream& operator<<(std::ostream& out, const AForm& f);



#endif