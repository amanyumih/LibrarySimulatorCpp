#include "Book.h"

Book::Book(const std::string pname, const std::string pauthor, const unsigned year, const GenreBooks pgenre) :
    Publication(pname, pauthor, year), genre(pgenre) {} // Konstruktor: inicializálja az alap publikációs adatokat és a könyv műfaját

Book::~Book() {} // Destruktor

std::string Book::getType() const { return "Book"; }

GenreBooks Book::getGenreEnum() const { return genre; } // Getter a könyv műfajának enum értékéhez

std::string Book::getGenreString() const // Függvény a könyv műfajának szöveges reprezentációjához
{
    switch (genre) {
    case GenreBooks::FICTION: return "Fiction";
    case GenreBooks::SCIENCE_FICTION: return "Science Fiction";
    case GenreBooks::ROMANCE: return "Romance";
    case GenreBooks::MYSTERY: return "Mystery";
    case GenreBooks::THRILLER: return "Thriller";
    case GenreBooks::DRAMA: return "Drama";
    case GenreBooks::COMEDY: return "Comedy";
    case GenreBooks::FANTASY: return "Fantasy";
    case GenreBooks::OTHER: return "Other";
    default: return "Unknown";
    }
}

void Book::print(std::ostream& os) const { // Felülírt virtuális print függvény a könyv specifikus adatainak kiírásához
    Publication::print(os); // Meghívja az ősosztály print függvényét az alap adatok kiírásához
    os << ". Genre: " << getGenreString(); // Hozzáadja a könyvre jellemző információt
}

std::ostream& operator<<(std::ostream& os, const Book& other) { // Operátor << felülírása Book objektumokhoz
    other.print(os); // Meghívja az objektum print függvényét
    os << std::endl;
    return os;
}