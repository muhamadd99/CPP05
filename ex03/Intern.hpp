/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:57:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/11/09 16:41:17 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* makeForm(const std::string formNameParam, const std::string target);
};