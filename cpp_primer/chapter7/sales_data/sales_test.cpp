#include "Sales_data.h"
int main() {
    Sales_data total, item;
    std::string null_book = "9-999-99999-9";
    Sales_data item2 = null_book;
    item.combine(null_book);
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data ?!" << std::endl;
    }
    return 0;
}