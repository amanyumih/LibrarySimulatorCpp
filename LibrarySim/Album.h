#pragma once
#include <iostream>
#include "Publication.h"

enum class MusicGenre { // Zenei műfajokat felsoroló enum
    POP,
    ROCK,
    CLASSICAL,
    HIPHOP,
    MPB,
    INDIE,
    REGGAE,
    LOFI,
    METAL,
    OTHER
};

class Album : public Publication // Az Album osztály a Publication osztályból származik
{
private:
    unsigned numTracks; // Az albumon lévő zeneszámok száma
    MusicGenre genre; // Az album zenei műfaja
public:
    Album(const std::string pname, const std::string pauthor, const unsigned year, unsigned pnumTracks, MusicGenre pgenre); // Konstruktor
    ~Album() override; // Felülírt destruktor

    std::string getType() const override;
    unsigned getnumTracks() const; // Getter a számok számának lekérdezéséhez
    MusicGenre getGenreEnum() const; // Getter a zenei műfaj enum értékének lekérdezéséhez
    std::string getGenreString() const; // Függvény a zenei műfaj szöveges formájának lekérdezéséhez

    void print(std::ostream& os) const override; // Felülírt virtuális függvény az album adatainak kiírásához
    //friend std::ostream& operator<<(std::ostream& os, const Album& other); // Barát operátor << az albumok közvetlen kiíráshoz
};

std::ostream& operator<<(std::ostream& os, const Album& other); // Az Album operátor << deklarációja
