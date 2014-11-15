#include "print_driver.h"
#include "nfc_driver.h"
#include "card.h"

#include <iostream>
#include <iomanip>
#include <endian.h>
#include <string>

using namespace std;

void	print_hexa(bool S0[3], bool S1[3], bool S2[3], bool S3[3])
{
	char b6 = 0, b7 = 0, b8 = 0;
	b6 = ~S3[1] << 7 | ~S2[1] << 6 | ~S1[1] << 5 | ~S0[1] << 4 | ~S3[0] << 3 | ~S2[0] << 2 | ~S1[0] << 1 | ~S0[0];
	b7 = S3[0] << 7 | S2[0] << 6 | S1[0] << 5 | S0[0] << 4 | ~S3[2] << 3 | ~S2[2] << 2 | ~S1[2] << 1 | ~S0[2];
	b8 = S3[2] << 7 | S2[2] << 6 | S1[2] << 5 | S0[2] << 4 | S3[1] << 3 | S2[1] << 2 | S1[1] << 1 | S0[1];
	for (int i = 0; i < 8; ++i)
		cout << (int)((b6 & (1 << i)) >> i);
	cout << endl;
	for (int i = 0; i < 8; ++i)
		cout << (int)((b7 & (1 << i)) >> i);
	cout << endl;
	for (int i = 0; i < 8; ++i)
		cout << (int)((b8 & (1 << i)) >> i);
	cout << endl;
	cout << hex << (int)(b6 & 0xff) << endl << hex << (int)(b7 & 0xff) << endl << hex << (int)(b8 & 0xff) << endl;
}

void	setAdmin(Card &card)
{
	string	admin("ADMIN");
	for (size_t i = 0; i < admin.size(); ++i)
		card[1][0][i] = admin[i];
	card[1][0][admin.size()] = 0;
	card.writeSector(1);
}

int	main()
{
	Printer		p(true);
	NfcDevice	device(&p);
	std::unique_ptr<Card>	card;;

	card = device.findCard(true);
	card->readSector(1);
	/* setAdmin(*card); */
	return 0;
}
