/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:24:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/10 12:23:52 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// int main()
// {
// 	//normal
// 	try
// 	{
// 		Bureaucrat ZhengchangRen("Normal Guy", 20);
// 		std::cout << ZhengchangRen << std::endl;
		
// 		ZhengchangRen.incrementGrade();
// 		std::cout << "Post promotion: " << ZhengchangRen << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	//wrong case
// 	try
// 	{
// 		Bureaucrat CuoRen("Wrong Guy+", 1500);
// 		Bureaucrat CuoRen2("Wrong Guy-", -1);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	//wrong promotion
// 	try
// 	{
// 		Bureaucrat CeoGuy("Ceo Guy", 1);
// 		std::cout << CeoGuy << std::endl;
// 		CeoGuy.incrementGrade();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
// 	//wrong demotion
// 	try
// 	{
// 		Bureaucrat SlaveGuy("Slave Guy", 150);
// 		std::cout << SlaveGuy << std::endl;
// 		SlaveGuy.decrementGrade();
// 		std::cout << "❌ Try dont skip" << std::endl; //demonstrate that try skip remaining codes
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout<< "Error: " << e.what() << std::endl;
// 	}
// 	//all possible error
// 	try
// 	{
// 	    Bureaucrat guy("Test", 75);
	
// 	    guy.incrementGrade();
// 	    guy.decrementGrade(); 
// 	}
// 	// Multiple catch blocks for SPECIFIC types:
// 	catch (const Bureaucrat::GradeTooHighException& e) {
// 	    std::cout << "High grade error: " << e.what() << std::endl;
// 	}
// 	catch (const Bureaucrat::GradeTooLowException& e) {
// 	    std::cout << "Low grade error: " << e.what() << std::endl;
// 	}
// 	catch (const std::exception& e) {
// 	    std::cout << "Generic error: " << e.what() << std::endl;
// 	}
// 	return (0);
// }


#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Normal case
	std::cout << "\n=== NORMAL CASE ===" << std::endl;
	try
	{
		Bureaucrat ZhengchangRen("Normal Guy", 20);
		std::cout << "Created: " << ZhengchangRen << std::endl;
		
		ZhengchangRen.incrementGrade();
		std::cout << "✅ After promotion: " << ZhengchangRen << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "❌ Error: " << e.what() << std::endl;
	}

	//  Wrong creation case
	std::cout << "\n=== INVALID CREATION ===" << std::endl;
	try
	{
		Bureaucrat CuoRen("Wrong Guy+", 1500);
		Bureaucrat CuoRen2("Wrong Guy-", -1);
	}
	catch(const std::exception& e)
	{
		std::cout << "❌ Error: " << e.what() << std::endl;
	}

	// Wrong promotion case
	std::cout << "\n=== PROMOTION LIMIT ===" << std::endl;
	try
	{
		Bureaucrat CeoGuy("Ceo Guy", 1);
		std::cout << " Created: " << CeoGuy << std::endl;
		CeoGuy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "❌ Error: " << e.what() << std::endl;
	}

	// ⬇️ Wrong demotion case
	std::cout << "\n === DEMOTION LIMIT ===" << std::endl;
	try
	{
		Bureaucrat SlaveGuy("Slave Guy", 150);
		std::cout << " Created: " << SlaveGuy << std::endl;
		SlaveGuy.decrementGrade();
		std::cout << "🚫 This line is skipped when exception occurs" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "❌ Error: " << e.what() << std::endl;
	}

	// 🎯 All possible errors
	std::cout << "\n=== SPECIFIC EXCEPTION HANDLING ===" << std::endl;
	try
	{
	    Bureaucrat guy("Test Guy", 75);
	    std::cout << " Created: " << guy << std::endl;
	
	    guy.incrementGrade();
	    guy.decrementGrade(); 
	    std::cout << "✅ All operations successful!" << std::endl;
		//throw std::runtime_error("Out of memory!");
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
	    std::cout << "⬆️ High grade error: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
	    std::cout << "⬇️ Low grade error: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
	    std::cout << "⚠️ Generic error: " << e.what() << std::endl;
	}
	return (0);
}