#pragma once
#include <iostream>

class Publication {
protected:
    const std::string title; // A publikáció címe (nem módosítható).
    const std::string author; // A publikáció szerzője (nem módosítható).
    const unsigned yearPublication; // A publikáció kiadási éve (nem módosítható).
public:
    Publication(const std::string pname, const std::string pauthor, const unsigned year); // Konstruktor.
    virtual ~Publication(); // Virtuális destruktor.

    virtual std::string getType() const;
    virtual std::string getTitle() const; // Virtuális getter a cím lekérdezéséhez.
    virtual std::string getAuthor() const; // Virtuális getter a szerző lekérdezéséhez.
    virtual unsigned getYearPublication() const; // Virtuális getter a kiadási év lekérdezéséhez.

    virtual void print(std::ostream& os) const; // Virtuális függvény a publikáció adatainak kiírásához.
    friend std::ostream& operator<<(std::ostream& os, const Publication& other); // Barát operátor << a közvetlen kiíráshoz.
};

std::ostream& operator<<(std::ostream& os, const Publication& other); // Az operátor << deklarációja