#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}


ShrubberyCreationForm::~ShrubberyCreationForm()
{}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecute(executor);
    std::string name = target + "_shrubbery";
    std::ofstream file(name.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to create shrubbery file");
    }
    file << "     /\\     /\\\n";
    file << "    /  \\   /  \\\n";
    file << "   /    \\ /    \\\n";
    file << "  /      \\      \\\n";
    file << "        ||   ||\n";
    file << "        ||   ||\n";
    file.close();
}