/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:22:19 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/10 14:02:40 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unnamed"), _isSigned(false), 
		_gradeToExec(150), _gradeToSign(150)
{}

AForm::AForm(std::string name, const int toExec, const int toSign) : _name(name), 
		_isSigned(false), _gradeToExec(toExec), _gradeToSign(toSign)
{
	if (toExec > 150 || toSign > 150)
		throw GradeTooLowException();
	if (toExec < 1 || toSign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned),
		_gradeToExec(other._gradeToExec), _gradeToSign(other._gradeToSign)
{}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{}

void	AForm::beSigned(const Bureaucrat& other)
{
	if (_isSigned)
		return ;
	if (other.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int		AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

int		AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!. Fēnshù hen gāo!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!. Fēnshù hen dī!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Name: " << form.getName()
		<< ", Sign status: " << form.getIsSigned() 
		<< ",\n Grade needed to sign: " << form.getGradeToSign()
		<< ", Grade needed to execute: " << form.getGradeToExec();
	return os;
}