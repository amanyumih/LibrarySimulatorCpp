#pragma once
#include <string>
#include <vector>
#include "LibraryItem.h"

class User
{
	static unsigned nextId;
	const unsigned userId;
	const std::string name;
	std::vector<LibraryItem*> borrowedItems; // A felhasználó által kölcsönzött elemek listája
public:
	User(std::string name);
	~User();
	std::string getName() const; // Visszaadja a felhasználó nevét
	unsigned getUserId() const; // Visszaadja a felhasználó azonosítóját
	const std::vector<LibraryItem*>& getBorrowedItems() const; // Visszaadja a kölcsönzött elemek listáját

	void borrowItem(LibraryItem* item);	// Elem kölcsönzése
	void returnItem(unsigned itemId); // Elem visszavétele az azonosító alapján
	bool isBorrowing(unsigned itemId) const;	// Ellenőrzi, hogy a felhasználó kölcsönöz-e egy adott elemet

	void printUserDetails(std::ostream& os) const;	// Felhasználó adatainak kiírása
};

std::ostream& operator<<(std::ostream& os, const User& user); // Operátor a felhasználó objektum kiírásához