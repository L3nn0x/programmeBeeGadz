/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: availlan <availlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/19 23:08:09 by availlan          #+#    #+#             */
/*   Updated: 2014/10/21 00:01:38 by availlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CARD_H
# define CARD_H

#include <nfc/nfc-types.h>
#include "print_driver.h"

class   Card
{
	public:
	Card(void* device, Printer *print, uint8_t uid[8], uint8_t type);
	~Card();

	bool    read();
	bool    write() { return false; }

	bool    operator==(Card &other);
	bool    operator!=(Card &other);

	enum { MifareClassic, };

	private:
	static const uint8_t    keys[];

	bool    loadMifare();
	bool    authenticate(size_t sector);

	typedef uint16_t block;
	typedef block sector[4];

	sector      m_data[16];
	uint32_t    m_uid;
	uint8_t     m_type;
	Printer     *m_print;
	void        *m_device;
};

#endif /* !CARD_H */