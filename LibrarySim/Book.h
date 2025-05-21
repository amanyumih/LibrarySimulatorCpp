#pragma once
#include "Publication.h"

enum class GenreBooks { // Könyvek műfajait felsoroló enum
    FICTION,
    SCIENCE_FICTION,
    ROMANCE,
    MYSTERY,
    THRILLER,
    DRAMA,
    COMEDY,
    FANTASY,
    OTHER
};


class Book : public Publication { // A Book osztály a Publication osztályból származik
private:
    GenreBooks genre; // A könyv műfaja
public:
    Book(const std::string pname, const std::string pauthor, const unsigned year, const GenreBooks pgenre); // Konstruktor
    ~Book() override; // Felülírt destruktor

    std::string getType() const override;
    GenreBooks getGenreEnum() const; // Getter a könyv műfajának enum értékéhez
    std::string getGenreString() const; // Függvény a könyv műfajának szöveges formájának lekérdezéséhez

    void print(std::ostream& os) const override; // Felülírt virtuális függvény a könyv adatainak kiírásához
    //friend std::ostream& operator<<(std::ostream& os, const Book& other); // Barát operátor << a könyvek közvetlen kiíráshoz
};

std::ostream& operator<<(std::ostream& os, const Book& other); // A Book operátor << deklarációja