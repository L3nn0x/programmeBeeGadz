/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysql_driver.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: availlan <availlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:37:46 by availlan          #+#    #+#             */
/*   Updated: 2014/11/10 11:57:18 by availlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MYSQL_DRIVER_H
# define MYSQL_DRIVER_H

#include <mysql.h>
#include <string>
#include <vector>

class	Mysql
{
	public:
		Mysql(std::string server, std::string db, std::string user, std::string passwd);
		~Mysql();
		Mysql(const Mysql&) = delete;
		Mysql						&operator=(const Mysql) = delete;

		bool						sendRequest(const std::string request);
		bool						sendRequestData(const std::string request);
		std::vector<std::string>	getData(size_t nbLine);
		std::vector<std::string>	getNextData();


	private:
		std::string	m_server;
		std::string	m_db;
		std::string	m_user;
		std::string	m_passwd;
		MYSQL		m_mysql;
		MYSQL_RES	*m_result;
		size_t		m_nbFields;
};

#endif /* !MYSQL_DRIVER_H */
