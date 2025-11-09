/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:57:08 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 16:43:13 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return(*this);
}

Intern::~Intern()
{}

AForm* Intern::makeForm(const std::string formNameParam, const std::string target)
{
	std::string formName[3] = 
	{
		"Presidential Pardon Form",
		"Robotomy Request Form",
		"Shrubbery Creation Form"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNameParam == formName[i])
		{
			std::cout << "Intern creates " << formName[i] << std::endl;
			switch(i)
			{
				case 0:
					return new PresidentialPardonForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
		}
		
	}
	std::cout << "Intern cannot create " << formNameParam 
		<< " -name given dont exists" << std::endl;
	return NULL;
}