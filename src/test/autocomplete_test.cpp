#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "autocomplete/autocomplete.hpp"
#include <vector>

using namespace std;

TEST_CASE( "Basic function of AutoComplete class", "[AutoComplete]") {
    AutoComplete uut("The quick brown fox jumped over the lazy dog");
    auto result = uut.complete("t");
    for(auto it = result.begin(); it < result.end(); it++) {
        cout << *it << "\n";
    }
}
