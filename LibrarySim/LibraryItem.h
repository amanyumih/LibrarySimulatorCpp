#pragma once
#include <iostream>
#include <string>
#include "Publication.h"

class LibraryItem
{
    static unsigned nextId; // Statikus változó a következ? kiosztandó ID-hez
    const unsigned itemId; // Az elem egyedi, nem módosítható azonosítója
    Publication* publication; // Pointer a könyvtári elemhez tartozó publikációra (Book, Magazine, Album)
    bool isBorrowed; // Jelzi, hogy az elem ki van-e kölcsönözve
public:
    LibraryItem(Publication* pub); // Konstruktor
    ~LibraryItem(); // Destruktor

    unsigned getItemId() const; // Getter az elem ID-jához
    Publication* getPublication() const; // Getter a Publication objektumhoz

    bool isItemBorrowed() const; // Ellen?rzi, hogy az elem ki van-e kölcsönözve
    void setBorrowed(bool borrowed); // Beállítja az elem kölcsönzési állapotát

    void printItemDetails(std::ostream& os) const; // Kiírja az elem részletes adatait a megadott stream-re
};

std::ostream& operator<<(std::ostream& os, const LibraryItem& item); // Operátor a LibraryItem objektum kimeneti stream-re írásához