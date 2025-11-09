/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 18:03:32 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));
	Bureaucrat Ceo("Ceo", 1);
	Bureaucrat Slave("Slave", 150);
	Intern intern;

	std::cout << "\n=== INTERN TEST ===" << std::endl;
	AForm* form1 = intern.makeForm("Presidential Pardon Form", "President Form");
	AForm* form2 = intern.makeForm("Robotomy Request Form", "Robotomy Form");
	AForm* form3 = intern.makeForm("Shrubbery Creation Form", "Shrubbery Form");
	AForm* form4 = intern.makeForm("abc form", "abc form");
	std::cout << std::endl;
	
	if (form1)
	{
		Ceo.signForm(*form1);
		Ceo.executeForm(*form1);
	}
	if (form2)
	{
		Ceo.signForm(*form2);
		Ceo.executeForm(*form2);
	}
	if (form3)
	{
		Ceo.signForm(*form3);
		Ceo.executeForm(*form3);
	}
	std::cout << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return (0);
}