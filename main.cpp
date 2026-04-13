#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

// I don't understand how to access the variables within the tuple as I
// have never worked with them. So I am cutting my losses for the night.
// Love the animal crossing reference!

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerInfo;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerInfo["Audie"] = {0, "Wolf", "foxtrot"};
    villagerInfo["Raymond"] = {8, "Cat", "crisp"};
    villagerInfo.insert({"Marshal", {10, "Squirrel", "sulky"}});

    // access the map using a range-based for loop
    cout << "Villagers and their catchphrases (range-based for loop):" << endl;
    for (auto pair : villagerInfo) {
        cout << pair.first <<" ";
        for (const auto& [level , species, phrase] : pair.second) {
            cout << "[" << level << ", " << species << ", " << phrase << endl;
        }
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerInfo.begin();
                                                    it != villagerInfo.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerInfo.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerInfo.find(searchKey);
    if (it != villagerInfo.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s info: ";
        for (auto info : it->second)  // range loop to traverse the value/vector
            cout << info << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerInfo.size() << endl;
    villagerInfo.clear();
    cout << "Size after clear: " << villagerInfo.size() << endl;

    return 0;
}