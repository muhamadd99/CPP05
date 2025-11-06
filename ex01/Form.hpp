/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:37 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/06 23:16:24 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string _name;
	bool		_isSigned;
	const int	_gradeToExec;
	const int	_gradeToSign;
public:
	Form();
	Form(std::string name);
	Form(const Form& other);
	~Form();
	void		beSigned(const Bureaucrat& other);
	void		signForm();

	const		std::string& getName() const;
	bool		getIsSigned() const;
	const int	getGradeToExec;
	const int	getGradeToSign() const;
	class	GradeTooHighExepetion : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	}
		public:
			virtual const char* what() const throw();
	};