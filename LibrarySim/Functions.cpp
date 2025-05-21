#include "Header.h"
#include <iomanip>
#include "LibraryItem.h"

void centerText(const std::string& text)
{
    int length = text.length(); // A szöveg hossza
    if (length >= MENU_WIDTH) // Ha a szöveg hossza nagyobb vagy egyenlő a menü szélességével
        std::cout << text << std::endl; // Egyszerűen kiírja a szöveget egy új sorban
    else {
        int leftSpaces = (MENU_WIDTH - length) / 2; // A bal oldali üres helyek száma a középre igazításhoz
        int rightSpaces = MENU_WIDTH - length - leftSpaces; // A jobb oldali üres helyek száma

        std::cout << std::setw(leftSpaces) << std::setfill(' ') << ""   // Bal oldali üres helyek beállítása
            << text << std::setw(rightSpaces) << std::setfill(' ') << "" // Szöveg kiírása, majd jobb oldali üres helyek beállítása
            << std::endl;
    }
}

void centerUserResponse(const std::string& text) {
    int length = text.length(); // A szöveg hossza
   
    if (length >= MENU_WIDTH) // Ha a szöveg hossza nagyobb vagy egyenlő a menü szélességével
        std::cout << text; // Egyszerűen kiírja a szöveget egy új sorban
    else {
        int leftSpaces = (MENU_WIDTH - length) / 2; // A bal oldali üres helyek száma
        int rightSpaces = MENU_WIDTH - length - leftSpaces; // A jobb oldali üres helyek száma

        std::cout << std::setw(leftSpaces) << std::setfill(' ') << ""   // Bal oldali üres helyek
            << text << "";  // a jobb oldali üres helyek nem kerülnek ide nyomtatásra, mivel ide írja be a felhasználó a kívánt szöveget   
    }
}

void menuArt()
{
    centerText(" _     _ _                                                       ");
    centerText("| |   (_) |__  _ __ __ _ _ __ _   _   _ __ ___   ___ _ __  _   _ ");
    centerText("| |   | | '_ \\| '__/ _` | '__| | | | | '_ ` _ \\ / _ \\ '_ \\| | | |");
    centerText("| |___| | |_) | | | (_| | |  | |_| | | | | | | |  __/ | | | |_| |");
    centerText("|_____|_|_.__/|_|  \\__,_|_|   \\__, | |_| |_| |_|\\___|_| |_|\\__,_|");
    centerText("                               |___/                              ");
    std::cout << "\n\n";

    centerText("1. Add Item");  // Elem hozzáadása
    centerText("2. Register User"); // Felhasználó regisztrálása
    centerText("3. Borrow Item"); // Elem kölcsönzése
    centerText("4. Return Item"); // Elem visszavétele
    centerText("5. Search Item by ID/Title");   // Elem keresése ID vagy cím alapján
    centerText("6. List Collection");   // Gyűjtemény listázása
    centerText("7. List Users"); // Felhasználók listázása
    centerText("0. Exit");  // Kilépés
    std::cout << "\n";

    std::cout << std::setw(MENU_WIDTH / 2 + 10) << std::right << "Enter your choice: "; // Felhasználói választás bekérése

}

void booksArt()
{
    std::system("cls"); // Képernyő törlése
    std::cout << std::endl;
    centerText("  _      _ _                            _____ _                     ");
    centerText(" | |    (_) |                          |_   _| |                    ");
    centerText(" | |     _| |__  _ __ __ _ _ __ _   _    | | | |_ ___ _ __ ___  ___ ");
    centerText(" | |    | | '_ \\| '__/ _` | '__| | | |   | | | __/ _ \\ '_ ` _ \\/ __|");
    centerText(" | |____| | |_) | | | (_| | |  | |_| |  _| |_| ||  __/ | | | | \\__ \\");
    centerText(" |______|_|_.__/|_|  \\__,_|_|   \\__, | |_____|\\__\\___|_| |_| |_|___/");
    centerText("                                 __/ |                              ");
    centerText("                                |___/                               ");
    std::cout << "\n\n";
}

void AddArt()
{
    std::cout << std::endl;
    centerText("              _     _   _____ _                     ");
    centerText("     /\\      | |   | | |_   _| |                    ");
    centerText("    /  \\   __| | __| |   | | | |_ ___ _ __ ___  ___ ");
    centerText("   / /\ \\ / _` |/ _` |   | | | __/ _ \\ '_ ` _ \\/ __|");
    centerText("  / ____ \\ (_| | (_| |  _| |_| ||  __/ | | | | \\__ \\");
    centerText(" /_/    \\_\\__,_|\\__,_| |_____|\\__\\___|_| |_| |_|___/");
    centerText("                                                    ");
    centerText("                                                    ");
}

void userArt()
{
    std::system("cls");
    std::cout << std::endl;
    centerText("  _    _                   ");
    centerText(" | |  | |                  ");
    centerText(" | |  | |___  ___ _ __ ___ ");
    centerText(" | |  | / __|/ _ \\ '__/ __|");
    centerText(" | |__| \\__ \\  __/ |  \\__ \\");
    centerText("  \\____/|___/\\___|_|  |___/");
    centerText("                           ");
}

void MenuSelect(unsigned select, Library& lib)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Beolvasási puffer ürítése
    switch (select)
    {
    case ADD_PUB: // Ha a felhasználó az elem hozzáadását választotta
        std::system("cls");
        AddArt();
        lib.addItemFromMenu(); 
        break;
    case USER_REGISTER: // Ha a felhasználó a felhasználó regisztrációt választotta
        lib.addUserFromMenu();
        break;
    case BOOK_BORROW: // Ha a felhasználó a könyv kölcsönzést választotta
        lib.borrowItemFromTerminal();
        break;
    case SEARCH: // Ha a felhasználó a keresést választotta
        lib.findItemFromMenu();
        break;
    case RETURN_BOOK: // Ha a felhasználó a könyv visszavételét választotta
        lib.returnItemFromTerminal();
        break;
    case BOOKS_LIST: // Ha a felhasználó a könyvek listázását választotta
        lib.printAllItems(std::cout);
        break;
    case USERS_LIST: // Ha a felhasználó a felhasználók listázását választotta
        lib.printAllUsers(std::cout);
        break;
    case EXIT: // Ha a felhasználó a kilépést választotta
        break; // Nincs teendő, a ciklus a main függvényben fog leállni
    default: // Ha a felhasználó érvénytelen számot adott meg
        centerText("Please select a number between 0-6."); // Hibaüzenet kiírása
        break;
    }
}
