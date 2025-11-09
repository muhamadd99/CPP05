/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 16:54:07 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(0));
	
	std::cout << "\n=== FORM SIGNING SCENARIOS ===" << std::endl;
	//AForm form1("Normal Grade Form", 25, 50);
	PresidentialPardonForm PresidentForm("Presidentform");
	RobotomyRequestForm RobotomyForm("Robotomyform");
	ShrubberyCreationForm ShrubForm("Shrubform");
	Bureaucrat Ceo("Ceo", 1);
	Bureaucrat CommonPeople("Common People", 50);
	Bureaucrat Slave("Slave", 150);
	
	std::cout << "\n=== UNSIGNED FORM TEST ===" << std::endl;
	Ceo.executeForm(PresidentForm);
	CommonPeople.executeForm(RobotomyForm);
	Slave.executeForm(ShrubForm);

	std::cout << "\n=== SIGNED FORM TEST ===" << std::endl;
	Ceo.signForm(PresidentForm);
	Ceo.signForm(RobotomyForm);
	Slave.signForm(ShrubForm); //wrong case

	std::cout  << "\n=== EXECUTE FORM INSUFFICIENT GRADE TEST ===" << std::endl;
	Slave.executeForm(PresidentForm);
	Slave.executeForm(RobotomyForm);
	Slave.executeForm(ShrubForm);//improper signing
	
	std::cout  << "\n=== EXECUTE FORM GRADE TEST ===" << std::endl;
	Ceo.executeForm(PresidentForm);
	Ceo.executeForm(RobotomyForm);
	Ceo.executeForm(ShrubForm);//proper execute, improper signing
	
	std::cout << "\n=== RANDOM 50 PERCENT CHANCE FOR ROBOTOMY ===" << std::endl;
	for (int i = 0; i < 6; i++)
		Ceo.executeForm(RobotomyForm); 

	std::cout << "\n=== PROPER SHRUB ===" << std::endl;
	Ceo.signForm(ShrubForm);
	Ceo.executeForm(ShrubForm);
	return (0);
}