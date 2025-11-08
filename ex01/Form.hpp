/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:37 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/07 12:44:03 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool		_isSigned;
	const int	_gradeToExec;
	const int	_gradeToSign;
public:
	Form();
	Form(std::string name, const int toExec, const int toSign);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	void		beSigned(const Bureaucrat& other);
	const		std::string& getName() const;
	bool		getIsSigned() const;
	int			getGradeToExec() const;
	int			getGradeToSign() const;
	
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, const Form& form);
