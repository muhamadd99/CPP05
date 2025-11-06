/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:51:01 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/06 13:49:14 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string> //std::string
#include <exception>

class Bureaucrat {
private:
	const	std::string _name;
	int		_grade;
	
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	class	GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
		//virtual so it call the most derived function
		//const so it returns a non modifiable char* str
		//const means not changing object thingy
		//throw() specify throw mode with no throw
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);