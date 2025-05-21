#pragma once
#include <iostream>
#include "Publication.h"

class Magazine : public Publication { // A Magazine osztály a Publication osztályból származik
private:
    std::string releaseDate; // A magazin megjelenési dátuma
public:
    Magazine(const std::string pname, const std::string pauthor, const unsigned year, std::string releaseDate); // Konstruktor
    ~Magazine() override; // Destruktor.

    std::string getType() const override;

    std::string getReleaseDate() const; // Getter a megjelenési dátum lekérdezéséhez

    void print(std::ostream& os) const override; // Felülírt virtuális függvény a magazin adatainak kiírásához
    //friend std::ostream& operator<<(std::ostream& os, const Magazine& other); // Barát operátor << a magazinok közvetlen kiíráshoz
};

std::ostream& operator<<(std::ostream& os, const Magazine& other); // A Magazine operátor << deklarációja