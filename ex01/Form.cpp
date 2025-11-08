/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:22:19 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/08 07:42:41 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unnamed"), _isSigned(false), 
		_gradeToExec(150), _gradeToSign(150)
{}

Form::Form(std::string name, const int toExec, const int toSign) : _name(name), 
		_isSigned(false), _gradeToExec(toExec), _gradeToSign(toSign)
{}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
		_gradeToExec(other._gradeToExec), _gradeToSign(other._gradeToSign)
{}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{}

void	Form::beSigned(const Bureaucrat& other)
{
	if (other.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int		Form::getGradeToExec() const
{
	return (_gradeToExec);
}

int		Form::getGradeToSign() const
{
	return (_gradeToSign);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!. Fēnshù hen gāo!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!. Fēnshù hen dī!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Name: " << form.getName()
			<< ", Sign status: " << form.getIsSigned() 
			<< "\n, Grade form: " << form.getGradeToSign()
			<< ", Grade needed to execute: " << form.getGradeToExec();
	return os;
}