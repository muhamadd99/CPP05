/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/08 23:10:39 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// 🎯 All possible errors
	std::cout << "\n=== SPECIFIC EXCEPTION HANDLING ===" << std::endl;
	try
	{
	    Bureaucrat guy("Test Guy", 75);
	    std::cout << " Created: " << guy << std::endl;
	
	    guy.incrementGrade();
	    guy.decrementGrade(); 
	    std::cout << "✅ All operations successful!" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
	    std::cout << "⬆️ High grade error: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
	    std::cout << "⬇️ Low grade error: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
	    std::cout << "⚠️ Generic error: " << e.what() << std::endl;
	}
	std::cout << "\n=== FORM SIGNING SCENARIOS ===" << std::endl;
	Form form1("Normal Grade Form", 25, 150);
	Form formHighGrade("High Grade Form", 1, 1);
	Form formLowGrade("Low Grade Form", 1, 2);
	Bureaucrat Ceo("Ceo", 1);
	Bureaucrat CommonPeople("Common People", 50);
	Bureaucrat Slave("Slave", 150);
	
	Ceo.signForm(form1);
	Ceo.signForm(formHighGrade);
	Ceo.signForm(formLowGrade);
	
	CommonPeople.signForm(form1);
	CommonPeople.signForm(formHighGrade);
	CommonPeople.signForm(formLowGrade);

	Slave.signForm(form1);
	Slave.signForm(formHighGrade);
	Slave.signForm(formLowGrade);
	return (0);
}