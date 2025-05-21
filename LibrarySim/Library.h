#pragma once
#include "LibraryItem.h"
#include "User.h"
#include <vector>
#include <string>

class Library
{
private:
	std::vector<LibraryItem*> items; // A könyvtárban lévő elemek tárolására szolgáló vektor
	std::vector<User*> users; // A könyvtár felhasználóinak tárolására szolgáló vektor
	void loadInitialItems(); // Függvény a kezdeti könyvtári elemek betöltésére
	void loadInitialUsers(); // Függvény a kezdeti felhasználók betöltésére

public:
	Library();
	~Library();

	void addItem(LibraryItem* item);	// Elem hozzáadása a könyvtárhoz
	void addItemFromMenu();	// Elem hozzáadása a menün keresztül
	
    void addNewUser(User* newUser); // Új felhasználó hozzáadása a könyvtárhoz
    void addUserFromMenu(); // Új felhasználó hozzáadása a menün keresztül

    LibraryItem* findItemById(const unsigned itemId) const; // Elem keresése azonosító alapján
    LibraryItem* findItemByTitle(const std::string itemTitle) const; // Elem keresése cím alapján
    void findItemFromMenu(); // Elem keresése a menün keresztül

    User* findUserById(const unsigned userId) const; // Felhasználó keresése azonosító alapján

    void borrowItem(const unsigned itemId, const unsigned userId); // Elem kölcsönzése egy felhasználónak
    void returnItem(const unsigned itemId, const unsigned userId); // Elem visszavétele egy felhasználótól
    void borrowItemFromTerminal(); // Elem kölcsönzése a terminálon keresztül
    void returnItemFromTerminal(); // Elem visszavétele a terminálon keresztül

    void printAllItems(std::ostream& os) const; // Az összes könyvtári elem kiírása
    void printAllUsers(std::ostream& os) const; // Az összes felhasználó kiírása
};