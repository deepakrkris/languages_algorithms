/**
 * @file 02_uniqueptr.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-10
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * 
 * A unique_ptr does not share its pointer. It cannot be copied to another unique_ptr, passed by value to a function
 * or used in any C++ Standard Library algorithm that requires copies to be made.
 * A unique_ptr can only be moved. This means that the ownership of the memory resource is transferred to another unique_ptr
 * and the original unique_ptr no longer owns it. We recommend that you restrict an object to one owner,
 * because multiple ownership adds complexity to the program logic. Therefore,
 * when you need a smart pointer for a plain C++ object, use unique_ptr,
 * and when you construct a unique_ptr, use the make_unique helper function.
 * 
 * Reference : https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances
 * 
*/
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Song {
    public :
    string artist;
    string title;

    Song (const string& a, const string& b) : artist(a) , title(b) {};
};

unique_ptr<Song> SongFactory(const string& artist, const string& title) {
    return make_unique<Song>(artist, title);
}

vector<array<string, 2>> song_list = { 
    { "Ed Sheerean", "Bad habits" },
    { "Britney Spears", "Hit me baby" },
    { "Aqua", "Barbie girl" },
    { "Michael Jackson MJ", "Just Beat It" }
};

int main() {
    cout << endl << endl << " START " <<  " array iterator " << endl;
    cout << std::string(20, '_') << endl;

    vector<unique_ptr<Song>> play_list;

    for (auto song : song_list) {
        unique_ptr<Song> play =  make_unique<Song>(song[0], song[1]);
        cout << " adding to playlist .. " << play->title << " from " << play->artist << endl;
        play_list.push_back(std::move(play));
    }

    for (const auto& play : play_list) {
        cout << endl << " playing.. " << play->title << " from " << play->artist << endl;
    }

    for (auto it = play_list.begin(); it != play_list.end(); ++it) {
        cout << endl << " replay.. " << (*it)->title << " from " << (*it)->artist << endl;
    }

    cout << endl << std::string(20, '_') << endl;
}
