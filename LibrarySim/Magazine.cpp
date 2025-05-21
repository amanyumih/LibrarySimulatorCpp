#include "Magazine.h"

Magazine::Magazine(const std::string pname, const std::string pauthor, const unsigned year, std::string preleaseDate) :
    Publication(pname, pauthor, year), releaseDate(preleaseDate) {
} // Konstruktor: inicializálja az alap publikációs adatokat és a megjelenési dátumot
Magazine::~Magazine() {} // Destruktor

std::string Magazine::getReleaseDate() const { return releaseDate; } // Getter a megjelenési dátum lekérdezéséhez

std::string Magazine::getType() const { return "Magazine"; }

void Magazine::print(std::ostream& os) const { // Felülírt virtuális print függvény a magazin specifikus adatainak kiírásához
    Publication::print(os); // Meghívja az ősosztály print függvényét az alap adatok kiírásához
    os << ". Release Date: " << getReleaseDate(); // Hozzáadja a magazinra jellemző információt
}

std::ostream& operator<<(std::ostream& os, const Magazine& other) { // Operátor << felülírása Magazine objektumokhoz
    other.print(os); // Meghívja az objektum print függvényét
    os << std::endl;
    return os;
}