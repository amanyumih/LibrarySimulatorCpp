#include "Header.h"
#include "Library.h"

int main()
{
	Library managerLibrary; // Létrehoz egy Library objektumot, amely a könyvtárat kezeli

	unsigned select = 1;	// Változó a felhasználó menüválasztásának tárolására, kezdetben 1-re állítva, hogy a ciklus elinduljon

	while (select)	// Ciklus, amely addig fut, amíg a felhasználó nem 0-t választ (kilépés)
	{
		menuArt();	 // A menü grafikus megjelenítésének függvénye
		std::cin >> select;	// Felhasználói választás beolvasása

		MenuSelect(select, managerLibrary);	// A felhasználó választása alapján a megfelelő művelet végrehajtása a Library objektumon
		std::cout << std::endl;
		centerText("Press enter button to continue.");
		getchar();	// Várakozás az Enter gomb megnyomására

		std::system("cls");	// Képernyő törlése a következő menü megjelenítése előtt
	}
	return 0;
}