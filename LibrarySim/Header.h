#ifndef _HEADER_LIB_SIM
#define _HEADER_LIB_SIM

/*======================= Includes ========================*/
#include "Library.h"

/*======================= Global Variable ========================*/
const unsigned int MENU_WIDTH = 100;

/*======================= függvények ========================*/
//Középre igazított szöveg függvényei
void centerText(const std::string& text);
void centerUserResponse(const std::string& text);

//Művészetek a menüválasztások díszítéséhez
void booksArt();
void menuArt();
void AddArt();
void userArt();

//Fő funkció a könyvtárkezeléshez a főmenüben keresztül
void MenuSelect(unsigned select, Library& lib);

//Lehetséges opciók a menüben
enum { EXIT, ADD_PUB, USER_REGISTER, BOOK_BORROW, RETURN_BOOK, SEARCH, BOOKS_LIST, USERS_LIST };

#endif