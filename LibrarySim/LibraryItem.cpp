#include "LibraryItem.h"
#include "Publication.h"
#include <iostream>
#include <string>

unsigned LibraryItem::nextId = 500;

LibraryItem::LibraryItem(Publication* pub) :
    itemId(nextId++), publication(pub), isBorrowed(false) {
}

LibraryItem::~LibraryItem() {
    delete publication;
}

unsigned LibraryItem::getItemId() const { return itemId; } // Getter az elem ID-jának lekérdezéséhez
Publication* LibraryItem::getPublication() const { return publication; } // Getter a Publication objektumra mutató pointer lekérdezéséhez

bool LibraryItem::isItemBorrowed() const { return isBorrowed; } // Getter annak ellenőrzéséhez, hogy az elem ki van-e kölcsönözve
void LibraryItem::setBorrowed(bool borrowed) { isBorrowed = borrowed; } // Setter az elem kölcsönzési állapotának beállításához

void LibraryItem::printItemDetails(std::ostream& os) const {
    os << "Item ID: " << itemId << ", ";
    publication->print(os); // Meghívja a Publication objektum print metódusát az adott publikáció adatainak kiírásához
    os << ", Status: " << (isBorrowed ? "Borrowed" : "Available"); // Kiírja az elem állapotát (Kölcsönzött vagy Elérhető)
}

std::ostream& operator<<(std::ostream& os, const LibraryItem& item) {
    item.printItemDetails(os);
    os << std::endl;
    return os;
}