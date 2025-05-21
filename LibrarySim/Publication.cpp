#include "Publication.h"

Publication::Publication(const std::string pname, const std::string pauthor, const unsigned pyear) :
    title(pname), author(pauthor), yearPublication(pyear) {
} // Konstruktor: inicializálja a címet, a szerzőt és a kiadási évet.

Publication::~Publication() {} // Virtuális destruktor: biztosítja a megfelelő erőforrás-felszabadítást a származtatott osztályokban is.

std::string Publication::getType() const { return "Publication"; }
std::string Publication::getTitle() const { return title; } // Getter a cím lekérdezéséhez.
std::string Publication::getAuthor() const { return author; } // Getter a szerző lekérdezéséhez.
unsigned Publication::getYearPublication() const { return yearPublication; } // Getter a kiadási év lekérdezéséhez.

void Publication::print(std::ostream& os) const { // Virtuális függvény a publikáció adatainak kiírásához egy output stream-re.
    os << getType() << std::endl << title << " by " << author
        << ". Publication year: " << yearPublication;
}

std::ostream& operator<<(std::ostream& os, const Publication& other) // Operátor << felülírása: lehetővé teszi a Publication objektumok közvetlen kiírását.
{
    other.print(os); // Meghívja a virtuális print függvényt az objektum tényleges típusának megfelelő kiíráshoz.
    os << std::endl; // Új sor a kiírás végén.
    return os; // Visszaadja az output stream-et a láncolt kiíráshoz.
}