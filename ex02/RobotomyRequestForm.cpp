/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 22:37:33 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/10 14:37:48 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> //std::rand

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy Request Form", 45, 72), _target(target)
{}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!getIsSigned())
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	
	std::cout << "DRRRRRRR....GRRRRRR....BRRRRRRR" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " succesfully robotomized!" << std::endl; 
	else
		std::cout << _target << " failed robotomization!" << std::endl;
}