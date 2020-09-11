#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <vector>
#include <string>
#include <algorithm>

using namespace boost;
using namespace boost::algorithm;

int main() {

    // >> sudo apt-get install libboost-all-dev

    // -------------------------------------------------------------------------------------------------
    // Dzielenie napisu na wyrazy
    // -------------------------------------------------------------------------------------------------
    // >> gcc -o app.out main.cpp -lstdc++

    std::cout << "----------------------------- 1 -----------------------------" << std::endl;
    std::string expression_1 = "aaa bbb ccc";
    std::vector<std::string> words_1;
    split(words_1, expression_1, is_any_of(" "));
    std::for_each(words_1.begin(), words_1.end(), [](const std::string& w){std::cout << w << std::endl;});

    std::cout << "----------------------------- 2 -----------------------------" << std::endl;
    std::string expression_2 = "aaa,bbb;ccc'ddd.eee";
    std::vector<std::string> words_2;
    std::string delimeters = ",;'.";
    split(words_2, expression_2, is_any_of(delimeters));
    std::for_each(words_2.begin(), words_2.end(), [](const std::string& w){std::cout << w << std::endl;});

    // -------------------------------------------------------------------------------------------------
    // Podmienianie pasujacego napisu
    // -------------------------------------------------------------------------------------------------
    // >> gcc -o app.out main.cpp -lstdc++ -lboost_regex

    std::cout << "----------------------------- 3 -----------------------------" << std::endl;
    std::string expression_3 = "aaa 12 bbb 13 ccc 14 ddd 15";
    std::string new_expression_3 = "NUMBER";
    regex regex_expression_3("\\d+");
    std::string result_3 = boost::regex_replace(expression_3, regex_expression_3, new_expression_3);
    std::cout << result_3 << std::endl;

    std::string expression_33 = "ala ma kota";
    std::cout << replace_first_copy(expression_33, "a", "*") << std::endl;
    std::cout << replace_nth_copy(expression_33, "a", 0, "*") << std::endl;
    std::cout << replace_last_copy(expression_33, "a", "*") << std::endl;
    std::cout << replace_all_copy(expression_33, "a", "*") << std::endl;
    std::cout << replace_head_copy(expression_33, 3, "*") << std::endl;
    std::cout << replace_tail_copy(expression_33, 3, "*") << std::endl;

    // -------------------------------------------------------------------------------------------------
    // Usuwanie wybranych znakow
    // -------------------------------------------------------------------------------------------------

    std::cout << "----------------------------- 4 -----------------------------" << std::endl;
    std::string expression_4 = "ala ma kota";
    std::cout << erase_first_copy(expression_4, "a") << std::endl;
    std::cout << erase_nth_copy(expression_4, "a", 1) << std::endl;
    std::cout << erase_last_copy(expression_4, "a") << std::endl;
    std::cout << erase_all_copy(expression_4, "a") << std::endl;
    std::cout << erase_head_copy(expression_4, 3) << std::endl; // skrocenie napisu o 5 znakow od poczatku
    std::cout << erase_tail_copy(expression_4, 3) << std::endl; // skrocenie napisu o 9 znakow od tylu

    // -------------------------------------------------------------------------------------------------
    // Sprawdzanie zawartosci napisow
    // -------------------------------------------------------------------------------------------------
    std::cout << "----------------------------- 5 -----------------------------" << std::endl;
    std::string expression_5 = "ala ma kota";
    std::cout << starts_with(expression_5, "ala") << std::endl;
    std::cout << ends_with(expression_5, "kota") << std::endl;
    std::cout << contains(expression_5, "ma") << std::endl;


    return 0;
}