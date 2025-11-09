/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:37:36 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 13:35:12 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery Creation Form", 137, 145), _target(target)
{}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return ;
	}
	
    file << "       ^       " << std::endl;
    file << "      ^^^      " << std::endl;
    file << "     ^^^^^     " << std::endl;
    file << "    ^^^^^^^    " << std::endl;
    file << "   ^^^^^^^^^   " << std::endl;
    file << "  ^^^^^^^^^^^  " << std::endl;
    file << " ^^^^^^^^^^^^^ " << std::endl;
    file << "^^^^^^^^^^^^^^^" << std::endl;
    file << "      |||      " << std::endl;
    file << "      |||      " << std::endl;

	file.close();
	std::cout << "Shrubbery created in file: " << filename << std::endl;
}