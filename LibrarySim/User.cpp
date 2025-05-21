#include "User.h"
#include <iostream>

unsigned User::nextId = 1000; // Statikus változó a következő felhasználó azonosítójának inicializálása

User::User(std::string pname) : name(pname), userId(nextId++){} // Konstruktor: beállítja a nevet és egyedi azonosítót generál
User::~User(){} // Destruktor

unsigned User::getUserId() const { return userId; } // Visszaadja a felhasználó azonosítóját
std::string User::getName() const { return name; } // Visszaadja a felhasználó nevét
const std::vector<LibraryItem*>& User::getBorrowedItems() const { return borrowedItems; } // Visszaadja a kölcsönzött elemek listáját

void User::borrowItem(LibraryItem* item) {
    borrowedItems.push_back(item); // Hozzáadja az elemet a kölcsönzött listához
    item->setBorrowed(true); // Beállítja az elem állapotát kölcsönzöttre
}

void User::returnItem(unsigned itemId)
{
    for (std::vector<LibraryItem*>::const_iterator it = borrowedItems.begin(); it != borrowedItems.end(); ++it)
    {
        if ((*it)->getItemId() == itemId) // Ha az elem azonosítója megegyezik a keresettel
        {
            (*it)->setBorrowed(false); // Beállítja az elem állapotát nem kölcsönzöttre
            borrowedItems.erase(it); // Eltávolítja az elemet a kölcsönzött listából
            return; // Kilép a függvényből, ha az elem megtalálható és vissza lett véve
        }
    }

    std::cout << "Item not found in items borrowed by this user." << std::endl; // Üzenet, ha az elem nem található a felhasználó kölcsönzött elemei között
}

bool User::isBorrowing(unsigned itemId) const
{
    for (std::vector<LibraryItem*>::const_iterator it = borrowedItems.begin();
        it != borrowedItems.end();
        ++it)
    {
        if ((*it)->getItemId() == itemId) // Ha az elem azonosítója megegyezik a keresettel
            return true; // Visszaadja, hogy a felhasználó kölcsönzi az elemet
    }

    return false; // Visszaadja, hogy a felhasználó nem kölcsönzi az elemet
}

void User::printUserDetails(std::ostream& os) const {
    os << "User ID: " << userId << ". Name: " << name;
    if (!borrowedItems.empty()) // Ha vannak kölcsönzött elemek
    {
        os << std::endl << "Books borrowed: " << std::endl;
        for (std::vector<LibraryItem*>::const_iterator it = borrowedItems.begin();
            it != borrowedItems.end();
            ++it)
            os << **it; // Kiírja a kölcsönzött elemek részleteit (feltételezve, hogy a LibraryItem-nek van << operátora)
    }
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    user.printUserDetails(os); // Meghívja a felhasználó adatainak kiírására szolgáló függvényt
    os << std::endl;
    return os; // Visszaadja a kimeneti stream-et
}