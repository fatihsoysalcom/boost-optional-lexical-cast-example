#include <iostream>
#include <string>
#include <boost/optional.hpp> // For boost::optional
#include <boost/lexical_cast.hpp> // For boost::lexical_cast

// Function that might return a value or not, demonstrating boost::optional
boost::optional<int> parse_integer(const std::string& s) {
    try {
        // Boost.Lexical_Cast: Conveniently converts a string to an integer.
        // If the string is not a valid integer, it throws boost::bad_lexical_cast.
        return boost::lexical_cast<int>(s);
    } catch (const boost::bad_lexical_cast& e) {
        std::cerr << "Error parsing '" << s << "': " << e.what() << std::endl;
        // Boost.Optional: Returns an empty optional to indicate no value is present.
        return boost::none;
    }
}

int main() {
    std::cout << "Boost C++ Kütüphaneleri Örneği (Boost C++ Libraries Example)\n";
    std::cout << "---------------------------------------------------------\n\n";

    // --- Demonstrating Boost.Optional ---
    std::cout << "1. Boost.Optional Kullanımı (Usage of Boost.Optional):\n";

    // Example 1: Successful parsing
    boost::optional<int> result1 = parse_integer("123");
    if (result1) { // Boost.Optional: Check if a value is present
        std::cout << "Geçerli sayı: " << *result1 << std::endl; // Boost.Optional: Access the contained value
    } else {
        std::cout << "Sayı ayrıştırılamadı.\n";
    }

    // Example 2: Failed parsing
    boost::optional<int> result2 = parse_integer("abc");
    if (result2) {
        std::cout << "Geçerli sayı: " << *result2 << std::endl;
    } else {
        std::cout << "Sayı ayrıştırılamadı.\n";
    }

    // Boost.Optional: Providing a default value if the optional is empty
    int value_or_default = result2.get_value_or(-1);
    std::cout << "Ayrıştırılamayan değer için varsayılan: " << value_or_default << "\n\n";


    // --- Demonstrating Boost.Lexical_Cast ---
    std::cout << "2. Boost.Lexical_Cast Kullanımı (Usage of Boost.Lexical_Cast):\n";

    // Convert int to string
    int num = 456;
    std::string s_num = boost::lexical_cast<std::string>(num); // Boost.Lexical_Cast: Converts int to string
    std::cout << "Sayıdan string'e dönüştürme: " << num << " -> \"" << s_num << "\"\n";

    // Convert double to string
    double pi = 3.14159;
    std::string s_pi = boost::lexical_cast<std::string>(pi); // Boost.Lexical_Cast: Converts double to string
    std::cout << "Double'dan string'e dönüştürme: " << pi << " -> \"" << s_pi << "\"\n";

    // Convert string to double
    std::string s_val = "78.9";
    try {
        double d_val = boost::lexical_cast<double>(s_val); // Boost.Lexical_Cast: Converts string to double
        std::cout << "String'den double'a dönüştürme: \"" << s_val << "\" -> " << d_val << "\n";
    } catch (const boost::bad_lexical_cast& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    std::cout << "\nÖrnek tamamlandı.\n";

    return 0;
}
