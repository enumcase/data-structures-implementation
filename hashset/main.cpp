#include <random>
#include <iostream>
#include <sstream>

#include "set.h"

std::string create(std::string str, int x) {

    std::stringstream ss;
    ss << str << x;
    return ss.str();
}

int main() {

    set kaz;

    kaz.insert("Kazuya");
    kaz.insert("Mizuhara");

    std::cout << kaz.contains("kazUYa") << "\n";
    std::cout << kaz.contains("mIzuHArA") << "\n";
    // Or not to be, that's the question.

    kaz.insert("Chizuru");
    std::cout << kaz.contains("Chiziri") << "\n";
    
    
    kaz.insert("Yukinoshita");
    kaz.insert("Yukino");
    kaz.insert("Mami");
    kaz.insert("Kanojo");
    kaz.insert("Sunset");
    

    kaz.insert("Horikita");
    kaz.insert("Alice");
    kaz.insert("Ellen");
    kaz.insert("Suzune");
    kaz.insert("Liza");

//    kaz.insert("London");
    
//    {"Yukinoshita","Yukino","Mami","Kanojo","Sunset","Horikita","Alice","Ellen","Suzune","Liza", "kazuya", "mark", "man"};


    std::cout << "Before remove:\n";
    std::cout << kaz << "\n";
    std::cout << kaz.size() << "\n";
    
    kaz.remove("Kanojo");
    
    std::cout << "After remove:\n";
    std::cout << kaz << "\n";
    std::cout << kaz.size() << "\n";

    auto kaz2 = kaz; // Copy constructor.
    
    std::cout << kaz2 << "\n";
    std::cout << kaz2.size() << "\n";
    
    kaz2 = kaz; // Assignment.
    kaz = kaz;  // Self assignment.
    
    std::cout << kaz << "\n";
    std::cout << kaz.size() << "\n";
    std::cout << kaz2 << "\n";
    std::cout << kaz2.size() << "\n";
    
    
    
    set initset1 = {"Canada", "Kazakhstan", "Russia", "USA", "Australia", "Japan", "South Korea", "Brazil", "Sweden", "Germany", "Switzerland", "UK", "France"};

    set initset2 = {"Canada", "Kazakhstan", "Russia"};

    std::cout << initset1 << "\n";
    std::cout << initset1.size() << "\n";

    std::cout << initset2 << "\n";
    std::cout << initset2.size() << "\n";
    
    initset1.clear();
    
    initset1={"Yukinoshita","Yukino","Mami","Kanojo","Sunset","Horikita","Alice","Ellen","Suzune","Liza"};//, "Kazuya", "Mark", "Man"};
    
//    initset1.insert("Canada");
//    initset1.insert("Kazakhstan");
//    initset1.insert("Russia");
//    initset1.insert("USA");
//    initset1.insert("Austria");
//    initset1.insert("Germany");
//    initset1.insert("Sweden");
//    initset1.insert("UK");
//    initset1.insert("France");
//    initset1.insert("Ukraine");
//    initset1.insert("Japan");
//    initset1.insert("Brazil");
//    initset1.insert("ARIGATO");
//
    std::cout << initset1 << "\n";
    
    set someset1;
    
    for (size_t k = 0; k != 8000; ++k) {
        someset1.insert(create("aa", rand()));
        someset1.insert(create("bb", rand()));
    }

    auto someset2 = someset1;

    std::cout << someset1.standarddev() << std::endl;
    std::cout << someset2.standarddev() << std::endl;

    return 0;
}

