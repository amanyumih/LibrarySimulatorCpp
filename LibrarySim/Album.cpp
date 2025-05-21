#include "Album.h"

Album::Album(const std::string pname, const std::string pauthor, const unsigned year, unsigned pnumTracks, MusicGenre pgenre) :
    Publication(pname, pauthor, year), numTracks(pnumTracks), genre(pgenre) {
} // Konstruktor: inicializálja az alap publikációs adatokat, a számok számát és a zenei m?fajt

Album::~Album() {} // Destruktor

std::string Album::getType() const { return "Album"; }

unsigned Album::getnumTracks() const { return numTracks; } // Getter a számok számának lekérdezéséhez

MusicGenre Album::getGenreEnum() const { return genre; } // Getter a zenei m?faj enum értékének lekérdezéséhez

std::string Album::getGenreString() const { // Függvény a zenei m?faj enum értékének szöveges reprezentációjához
    switch (genre) {
    case MusicGenre::POP: return "Pop";
    case MusicGenre::ROCK: return "Rock";
    case MusicGenre::METAL: return "Metal";
    case MusicGenre::HIPHOP: return "Hip-Hop";
    case MusicGenre::MPB: return "MPB";
    case MusicGenre::INDIE: return "INDIE";
    case MusicGenre::LOFI: return "Lo-fi";
    case MusicGenre::CLASSICAL: return "Classical";
    case MusicGenre::REGGAE: return "Raggae";
    case MusicGenre::OTHER: return "Other";
    default: return "Unknow";
    }
}

void Album::print(std::ostream& os) const { // Felülírt virtuális print függvény az Album specifikus adatainak kiírásához
    Publication::print(os); // Meghívja az ?sosztály print függvényét az alap adatok kiírásához
    os << ". Tracks number: " << numTracks << ". Genre: " << getGenreString(); // Hozzáadja az albumra jellemz? információkat
}

std::ostream& operator<<(std::ostream& os, const Album& other) { // Operátor << felülírása Album objektumokhoz
    other.print(os); // Meghívja az objektum print függvényét
    os << std::endl;
    return os;
}