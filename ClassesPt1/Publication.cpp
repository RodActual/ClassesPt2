// Anthony Rodriguez
// CIS 1202 101
// November 1, 2023

#include "Publication.h"

void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

void Publication::displayInfo() {
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: " << price << endl;
    cout << "Year of Publication: " << year << endl;
    cout << "Publication Type: " << type << endl;
    cout << "Stock: " << stock << endl;
}

void Publication::checkOut() {
    if (stock > 0) {
        stock--;
    }
    else {
        cout << "No copies in stock." << endl;
    }
}

void Publication::checkIn() {
    stock++;
}

string Publication::getTitle() {
    return title;
}

int Publication::getStock() {
    return stock;
}
