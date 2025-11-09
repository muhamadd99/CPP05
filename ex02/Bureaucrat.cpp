/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:06:38 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 14:08:25 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), 
		_grade(other._grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this); //return value for reference
}

Bureaucrat::~Bureaucrat()
{
	
}

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!. Fēnshù hen gāo!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!. Fēnshù hen dī");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " cannot execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
