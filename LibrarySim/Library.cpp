#include <vector>
#include <iomanip>
#include <string>
#include "LibraryItem.h"
#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Album.h"
#include "Header.h"

Library::Library() {
    loadInitialItems(); // A könyvtár létrehozásakor a kezdeti elemek betöltése
    loadInitialUsers(); // A könyvtár létrehozásakor a kezdeti felhasználók betöltése
}

Library::~Library() {
    for (std::vector<LibraryItem*>::iterator it = items.begin(); // Végigmegyünk a könyvtári elemek vektorán
        it != items.end();
        ++it)
    {
        delete* it; // Az aktuális LibraryItem* által mutatott objektum törlése a memóriából
    }
    
    for (User* user : users) { // Végigmegyünk a felhasználók vektorán
        delete user; // Az aktuális User* által mutatott objektum törlése a memóriából
    }
}

void Library::loadInitialItems() {
    // Könyvek
    items.push_back(new LibraryItem(new Book("The Lord of the Rings", "J.R.R. Tolkien", 1954, GenreBooks::FANTASY)));
    items.push_back(new LibraryItem(new Book("Pride and Prejudice", "Jane Austen", 1813, GenreBooks::ROMANCE)));
    items.push_back(new LibraryItem(new Book("To Kill a Mockingbird", "Harper Lee", 1960, GenreBooks::DRAMA)));
    items.push_back(new LibraryItem(new Book("1984", "George Orwell", 1949, GenreBooks::SCIENCE_FICTION)));
    items.push_back(new LibraryItem(new Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979, GenreBooks::SCIENCE_FICTION)));
    items.push_back(new LibraryItem(new Book("Jane Eyre", "Charlotte Brontë", 1847, GenreBooks::ROMANCE)));
    items.push_back(new LibraryItem(new Book("The Catcher in the Rye", "J.D. Salinger", 1951, GenreBooks::DRAMA)));
    items.push_back(new LibraryItem(new Book("One Hundred Years of Solitude", "Gabriel García Márquez", 1967, GenreBooks::FANTASY)));
    items.push_back(new LibraryItem(new Book("Moby Dick", "Herman Melville", 1851, GenreBooks::OTHER)));

    // Magazinok
    items.push_back(new LibraryItem(new Magazine("Time", "Various", 2024, "May")));
    items.push_back(new LibraryItem(new Magazine("National Geographic", "Various", 2024, "June")));
    items.push_back(new LibraryItem(new Magazine("The Economist", "Various", 2024, "May")));
    items.push_back(new LibraryItem(new Magazine("Vogue", "Various", 2024, "April")));
    items.push_back(new LibraryItem(new Magazine("Sports Illustrated", "Various", 2024, "May")));
    items.push_back(new LibraryItem(new Magazine("New Yorker", "Various", 2024, "May")));

    // Albumok
    items.push_back(new LibraryItem(new Album("Abbey Road", "The Beatles", 1969, 17, MusicGenre::ROCK)));
    items.push_back(new LibraryItem(new Album("Kind of Blue", "Miles Davis", 1959, 5, MusicGenre::CLASSICAL)));
    items.push_back(new LibraryItem(new Album("Thriller", "Michael Jackson", 1982, 9, MusicGenre::POP)));
    items.push_back(new LibraryItem(new Album("Back in Black", "AC/DC", 1980, 10, MusicGenre::ROCK)));
    items.push_back(new LibraryItem(new Album("Rumours", "Fleetwood Mac", 1977, 11, MusicGenre::ROCK)));

}

void Library::loadInitialUsers() {
    // Kezdeti felhasználók létrehozása és hozzáadása
    users.push_back(new User("Harry Potter"));
    users.push_back(new User("Hermione Granger"));
    users.push_back(new User("Frodo Baggins"));
    users.push_back(new User("Leia Organa"));
    users.push_back(new User("Atticus Finch"));
    users.push_back(new User("Elizabeth Bennet"));
    users.push_back(new User("Sherlock Holmes"));
    users.push_back(new User("Daenerys Targaryen"));
    users.push_back(new User("Walter White"));
    users.push_back(new User("Beyoncé Knowles"));
    users.push_back(new User("Pablo Picasso"));
    users.push_back(new User("Frida Kahlo"));
    users.push_back(new User("Ludwig van Beethoven"));
    users.push_back(new User("Marie Curie"));
    users.push_back(new User("Leonardo da Vinci"));
}

void Library::addNewUser(User* newUser) {
    // Új felhasználó hozzáadása a felhasználók vektorához
    if (!newUser)
        throw std::invalid_argument("Cannot add a null user.");
    users.push_back(newUser);
}

void Library::addUserFromMenu()
{
    std::string name; // Változó az új felhasználó nevének tárolására
    centerUserResponse("Enter the name of the new user: "); // Keresztnév bekérése
    std::getline(std::cin, name);

    if (name.empty())
    {
        centerText("Error: User name cannot be empty.");
    }

    if (!name.empty()) {
        User* newUser = new User(name); // Új User objektum létrehozása a teljes névvel
        addNewUser(newUser); // Az új felhasználó hozzáadása a könyvtár felhasználóihoz
        centerText("User " + name + " added successfully! User id: " + std::to_string(newUser->getUserId())); // Sikeres hozzáadás üzenetének kiírása
    }
}

void Library::addItem(LibraryItem* item) {
    if (!item) {
        throw std::invalid_argument("Cannot add a null item.");
    }
    items.push_back(item);  // Új könyvtári elem hozzáadása az elemek vektorához
}

void Library::addItemFromMenu()
{
    int type;   // Változó a hozzáadandó elem típusának tárolására
    while (true) {
        centerText("1. Book");
        centerText("2. Magazine");
        centerText("3. Album");
        centerUserResponse("Please select an item: ");
        if (std::cin >> type && (type >= 1 && type <= 3)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; //Kilépés a ciklusból, ha a bemenet érvényes
        }
        else {
            centerText("Invalid input. Please enter a number between 1 and 3.");
            std::cin.clear(); // Cin hibajelzők törlése
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Elveti az érvénytelen bemenetet
        }
    }

    std::string title, author, releaseDate, genreString; // Változók a közös adatok tárolására
    unsigned year, numTracks; // Változók a közös adatok tárolására
    GenreBooks bookGenre; // Változó a könyv műfajának tárolására
    MusicGenre albumGenre; // Változó az album zenei műfajának tárolására
    
    centerUserResponse("Title: ");
    std::getline(std::cin, title);
    centerUserResponse("Author: ");
    std::getline(std::cin, author);
    centerUserResponse("Publication year: ");
    std::cin >> year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (type) {
    case 1: // Könyv hozzáadása
        centerUserResponse("Write the Genre: Fiction, Science Fiction, Romance, Mystery, Thriller, Drama, Comedy, Fantasy, Other: ");
        std::getline(std::cin, genreString);
        // A beolvasott szöveg alapján a megfelelő enum érték beállítása
        if (genreString == "Fiction") bookGenre = GenreBooks::FICTION;
        else if (genreString == "Science Fiction") bookGenre = GenreBooks::SCIENCE_FICTION;
        else if (genreString == "Romance") bookGenre = GenreBooks::ROMANCE;
        else if (genreString == "Mystery") bookGenre = GenreBooks::MYSTERY;
        else if (genreString == "Thriller") bookGenre = GenreBooks::THRILLER;
        else if (genreString == "Drama") bookGenre = GenreBooks::DRAMA;
        else if (genreString == "Comedy") bookGenre = GenreBooks::COMEDY;
        else if (genreString == "Fantasy") bookGenre = GenreBooks::FANTASY;
        else bookGenre = GenreBooks::OTHER;
        // Új könyv objektum létrehozása és hozzáadása
        addItem(new LibraryItem(new Book(title, author, year, bookGenre)));
        centerText("Book added successfully!");
        break;
    case 2: // Magazin hozzáadása
        centerUserResponse("Release Date: ");   // Kiadási dátum bekérése
        std::getline(std::cin, releaseDate);
        addItem(new LibraryItem(new Magazine(title, author, year, releaseDate)));   //Új magazin objektum létrehozása és hozzáadása
        centerText("Magazine added successfully!");
        break;
    case 3: // Album hozzáadása
        centerUserResponse("Number of Tracks: ");
        std::cin >> numTracks;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        centerUserResponse("Musical Genre (Pop, Rock, Classical, Hip-Hop, MPB, Indie, Reggae, Lo-fi, Metal, Other): ");
        std::getline(std::cin, genreString);

        // A beolvasott szöveg alapján a megfelelő enum érték beállítása
        if (genreString == "Pop") albumGenre = MusicGenre::POP;
        else if (genreString == "Rock") albumGenre = MusicGenre::ROCK;
        else if (genreString == "Classical") albumGenre = MusicGenre::CLASSICAL;
        else if (genreString == "Hip-Hop") albumGenre = MusicGenre::HIPHOP;
        else if (genreString == "MPB") albumGenre = MusicGenre::MPB;
        else if (genreString == "Indie") albumGenre = MusicGenre::INDIE;
        else if (genreString == "Reggae") albumGenre = MusicGenre::REGGAE;
        else if (genreString == "Lo-fi") albumGenre = MusicGenre::LOFI;
        else if (genreString == "Metal") albumGenre = MusicGenre::METAL;
        else albumGenre = MusicGenre::OTHER;

        // Új album objektum létrehozása és hozzáadása
        addItem(new LibraryItem(new Album(title, author, year, numTracks, albumGenre)));
        centerText("Album added successfully!");
        break;
    default:
        centerText("Invalid option.");  // Érvénytelen választás üzenet
        break;
    }
}

LibraryItem* Library::findItemById(const unsigned itemId) const
{
    for (std::vector<LibraryItem*>::const_iterator it = items.begin();
        it != items.end();
        ++it)
    {
        if ((*it)->getItemId() == itemId)// Ha az aktuális elem azonosítója megegyezik a keresettel
            return *it; // Visszaadjuk az elemre mutató pointert
    }
    return nullptr; // Ha nem található elem a megadott azonosítóval
}

LibraryItem* Library::findItemByTitle(const std::string itemTitle) const
{
    for (std::vector<LibraryItem*>::const_iterator it = items.begin(); // Végigmegyünk az elemek vektorán
        it != items.end();
        ++it)
    {
        Publication* pub = (*it)->getPublication(); // Az aktuális elem Publication részének lekérése
        if (pub->getTitle() == itemTitle) // Ha a Publication címe megegyezik a keresettel
            return *it; // Visszaadjuk az elemre mutató pointert
    }
    return nullptr; // Ha nem található elem a megadott címmel
}

void Library::findItemFromMenu() {
    unsigned searchOption; // Változó a keresési opció tárolására
    centerText("1. Search by ID"); // Keresési opciók kiírása
    centerText("2. Search by title");
    centerUserResponse("Select search criteria: "); // Felhasználói választás bekérése
    std::cin >> searchOption;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése

    LibraryItem* foundItem = nullptr; // Változó a megtalált elem tárolására

    switch (searchOption) {
    case 1: { // Keresés ID alapján
        unsigned id; // Változó a keresett ID tárolására
        centerUserResponse("Please enter the item ID: "); // ID bekérése
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése
        foundItem = findItemById(id); // Elem keresése ID alapján
        if (foundItem) // Ha az elem megtalálható
            std::cout << *foundItem; // Az elem adatainak kiírása
        else
            centerText("Item not found."); // Ha az elem nem található
        break;
    }
    case 2: { // Keresés cím alapján
        std::string searchTitle; // Változó a keresett cím tárolására
        centerUserResponse("Enter the title of the item you are looking for: "); // Cím bekérése
        std::getline(std::cin, searchTitle);
        foundItem = findItemByTitle(searchTitle); // Elem keresése cím alapján
        if (foundItem) { // Ha az elem megtalálható
            std::cout << *foundItem; // Az elem adatainak kiírása
        }
        else {
            centerText(("No items found with the title: ") + searchTitle); // Ha az elem nem található
        }
        break;
    }
    default:
        centerText("Invalid option."); // Érvénytelen választás üzenet
        break;
    }
}

User* Library::findUserById(const unsigned userId) const
{
    for (std::vector<User*>::const_iterator it = users.begin(); it != users.end(); ++it)
    {
        if ((*it)->getUserId() == userId) { // Ha az aktuális felhasználó azonosítója megegyezik a keresettel
            return *it; // Visszaadjuk a felhasználóra mutató pointert
        }
    }
    return nullptr; // Ha nem található felhasználó a megadott azonosítóval
}

void Library::borrowItem(const unsigned itemId, const unsigned userId)
{
    LibraryItem* item = findItemById(itemId); // Elem keresése ID alapján
    User* user = findUserById(userId); // Felhasználó keresése ID alapján

    if (item && user && !item->isItemBorrowed()) // Ha az elem és a felhasználó létezik, és az elem nincs kikölcsönözve
    {
        user->borrowItem(item); // Az elem hozzáadása a felhasználó kölcsönzött elemeihez
        item->setBorrowed(true); // Az elem állapotának beállítása "kikölcsönözve"
        centerText("Item borrowed successfully!"); // Sikeres kölcsönzés üzenet
    }
    else {
        if (!item) { centerText("This item was not found."); }
        else if (item->isItemBorrowed()) { centerText("This item  is already borrowed."); }
        if (!user) { centerText("User not found."); }
    }
}

void Library::returnItem(const unsigned itemId, const unsigned userId)
{
    LibraryItem* item = findItemById(itemId); // Elem keresése ID alapján
    User* user = findUserById(userId); // Felhasználó keresése ID alapján

    if (item && user && user->isBorrowing(itemId) && item->isItemBorrowed()) { // Ha az elem és a felhasználó létezik, a felhasználó kölcsönözte az elemet, és az elem ki van kölcsönözve
        user->returnItem(itemId); // Az elem eltávolítása a felhasználó kölcsönzött elemei közül
        item->setBorrowed(false); // Az elem állapotának beállítása "nincs kikölcsönözve"
        centerText("Item returned successfully!"); // Sikeres visszavétel üzenet
    } else {
        if (!item) centerText("Item not found"); // Ha az elem nem található
        else if (!item->isItemBorrowed()) centerText("Item was not borrowed."); // Ha az elem nem volt kikölcsönözve
        if (!user) centerText("User not found."); // Ha a felhasználó nem található
        else if (!user->isBorrowing(itemId)) centerText("User did not borrowed this item"); // Ha a felhasználó nem kölcsönözte az elemet
    }
}

void Library::borrowItemFromTerminal() {
    unsigned itemId, userId; // Változók a kölcsönzendő elem és a kölcsönző felhasználó azonosítójának tárolására

    centerUserResponse("Enter the ID of the item to be borrowed: "); // Kölcsönzendő elem ID-jének bekérése
    std::cin >> itemId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése

    centerUserResponse("Enter the ID of the user who is borrowing the item: "); // Kölcsönző felhasználó ID-jének bekérése
    std::cin >> userId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése

    borrowItem(itemId, userId); // A kölcsönzés végrehajtása a megadott ID-k alapján

}

void Library::returnItemFromTerminal() {
     unsigned itemId, userId; // Változók a visszavételre váró elem és a visszavevő felhasználó azonosítójának tárolására

    centerUserResponse("Enter the ID of the item to be returned:"); // Visszavételre váró elem ID-jének bekérése
    std::cin >> itemId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése

    centerUserResponse("Enter the ID of the user returning the item:"); // Visszavevő felhasználó ID-jének bekérése
    std::cin >> userId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Beolvasási puffer ürítése

    returnItem(itemId, userId); // A visszavétel végrehajtása a megadott ID-k alapján
}

void Library::printAllItems(std::ostream& os) const
{
    booksArt(); // A könyvek listázásához tartozó grafikus elem kiírása
    for (std::vector<LibraryItem*>::const_iterator it = items.begin(); // Végigmegyünk a könyvtári elemek vektorán
        it != items.end();
        ++it)
    {
        os << **it; // Dupla pointer dereferálás:
                    // *it: az aktuális elemre mutató pointert adja vissza (LibraryItem*)
                    // **it: a pointer által mutatott tényleges LibraryItem objektumot adja vissza,
                    //       amelynek a << operátora felül van definiálva a tartalom kiírásához.
                    // Ha csak *it-t használnánk, akkor a LibraryItem objektum memóriacímét írnánk ki.
    }
}

void Library::printAllUsers(std::ostream& os) const
{
    userArt(); // A felhasználók listázásához tartozó grafikus elem kiírása
    for (std::vector<User*>::const_iterator it = users.begin(); it != users.end(); ++it)
    {
        os << **it; // Dupla pointer dereferálás:
                    // *it: az aktuális felhasználóra mutató pointert adja vissza (User*)
                    // **it: a pointer által mutatott tényleges User objektumot adja vissza,
                    //       amelynek a << operátora felül van definiálva a tartalom kiírásához.
                    // Ha csak *it-t használnánk, akkor a User objektum memóriacímét írnánk ki.
    }
}