/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_driver.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: availlan <availlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/19 22:30:28 by availlan          #+#    #+#             */
/*   Updated: 2014/10/29 17:30:38 by availlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINT_DRIVER_H
# define PRINT_DRIVER_H

#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>

class   Printer
{
	public:
	Printer(bool isDebug);
	~Printer();

	enum    Type {INFO, ERROR, DEBUG};
	void    printMessage(Type type, std::string message);
	void    printDebug(std::string message);
	void    printError(std::string message);
	void    printInfo(std::string message);

	bool	isDebug() const;

	template<typename T>
	static std::string	valueToString(const T &value, bool hex = false)
	{
		std::stringstream	oss("");
		if (hex)
			oss << std::hex;
		oss << value;
		return oss.str();
	}

	template<typename T>
	static std::string	arrayToString(const T array[], size_t len, size_t fill = 2)
	{
		std::stringstream  oss("");
		oss << std::hex << std::setfill('0');
		for (size_t tmp = 0; tmp < len; ++tmp)
			oss << std::setw(fill) << +array[tmp] << " ";
		return oss.str();
	}

	private:
	bool    m_debug;
};

#endif /* !PRINT_DRIVER_H */
