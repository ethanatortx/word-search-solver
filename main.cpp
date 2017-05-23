
#include <iostream>
#include <string>
#include "charTable.h"
#include "wordSearch.h"
#include "process.h"

int main()
{
	int r, c, p, q;
	char a;
	/* 	word search example (easy): 
			xksquirrel
			fieldmouse
			auhzayrfox
			bbehubafyv
			nddkbabojn
			eugfrdbooj
			yoexmgiweo
			nehfoetlku
			aooilrvual
			zlgmeonyqc
		words:
			badger, fieldmouse, fox, hedgehog, mole, rabbit, squirrel, fox, owl

		example (hard):
			VEVDBSNIHPLODLEVOHSJ
			FNBVRGVSOUVENIRSRKEE
			LIAQCEYRHCAEBELTRYML
			ILTKIAIDELTSACDNASZL
			AEHLWRRPENIHSNUSXPRY
			PRIAAWEIGDRAOBFRUSLF
			LONWTAKVBNDEEWAESDAI
			EHGDELTRIBIFLIPFLOPS
			WSSRRISLAREHVLOOPBTH
			OSUASCLFAPYASXASWCSS
			TEIOLEDIENHZNIUCISEE
			HSTBICMVFWTSARFGCEVO
			CSSQDRGLPEKIALECSVET
			AABOEEONNNGGCLTSBAFY
			ELJJXAGHBDRUGOPAOWID
			BGGVRMTAOBLIASCSFRLN
			CNFLOGINIMATGRXEYCTA
			JUGGASEASHELLQDQAFVS
			USSHELBYALEXANDRANKT
			OPSUNSCREENWUMBRELLA

		words:
			ATLANTIC OCEAN; LIFEGUARD; SHOVEL; BATHING SUITS;
			MINI GOLF; SOUVENIRS; BEACH TOWEL; MYRTLE BEACH;
			SPLASH PARK; BOARDWALK; PAIL; SUNGLASSES;
			CARIBBEAN; RESORT; POOL; SUNSCREEN;
			DOLPHINS; SAILBOAT; SUNSHINE; FISHING;
			PIER; SANDCASTLE; SURFBOARD; FLIP FLOPS;
			SANDY TOES; UMBRELLA; ICE CREAM; SEASHELL;
			WATER SLIDE; JELLYFISH; SEAWEED WAVES; LAZY RIVER;
			SHELBY ALEXANDRA; LIFE VEST; SHORELINE
	*/
	#ifdef ONLY_ALPHA_CHAR
	std::cout << "only alpha characters will be accepted...\n";
	#endif
	/*std::cout << "rows? "; std::cin >> r;
	std::cout << "columns? "; std::cin >> c;
	charTable ctbl(r, c);
	for(p = 0; p < r; ++p){
		for(q = 0; q < c; ++q)
		{
			std::cin >> a;
			ctbl.set(a, p, q);
		}
	}*/

	r = 20;
	c = 20;
	const char* str = "VEVDBSNIHPLODLEVOHSJFNBVRGVSOUVENIRSRKEELIAQCEYRHCAEBELTRYMLILTKIAIDELTSACDNASZLAEHLWRRPENIHSNUSXPRYPRIAAWEIGDRAOBFRUSLFLONWTAKVBNDEEWAESDAIEHGDELTRIBIFLIPFLOPSWSSRRISLAREHVLOOPBTHOSUASCLFAPYASXASWCSSTEIOLEDIENHZNIUCISEEHSTBICMVFWTSARFGCEVOCSSQDRGLPEKIALECSVETAABOEEONNNGGCLTSBAFYELJJXAGHBDRUGOPAOWIDBGGVRMTAOBLIASCSFRLNCNFLOGINIMATGRXEYCTAJUGGASEASHELLQDQAFVSUSSHELBYALEXANDRANKTOPSUNSCREENWUMBRELLA";

	wordSearch ws(str, r, c);
	ws.table().print();
	std::cout << "\nSearch for word? (y/n) "; std::cin >> a;
	std::string s;
	while((a == 'y') || (a == 'Y'))
	{
		do {
			std::getline(std::cin, s);
		} while (s.length() < 2);

		if(ws.search(s) == 1)
			std::cout << "Word found!\n";
		else
			std::cout << "Word not found.\n";
		std::cout << "Search again? (y/n) "; std::cin >> a;
	}

	return 0;
}