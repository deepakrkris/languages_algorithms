/**
 * @file 03_play_media_sharedptr.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <array>

using namespace std;

class MediaAsset {
    protected: 
    string artist;
    string title;

    public :
    MediaAsset(string a, string b) : artist(a), title(b) {}
    virtual void play() = 0;
};

class Song : public MediaAsset {
    public:
    Song(string a, string b) : MediaAsset(a , b) {}

    void play() {
        cout << " playing song " << title << " from " << artist << endl << endl; 
    }
};

class Video : public MediaAsset {
    public:
    Video(string a, string b) : MediaAsset(a , b) {}

    void play() {
        cout << " playing video " << title << " from " << artist << endl << endl;
    }
};

class PlayList {
    vector<shared_ptr<MediaAsset>> assets;
    
    public :
    void add_to_playlist(shared_ptr<MediaAsset> a) {
        assets.push_back(a);
    }

    vector<shared_ptr<MediaAsset>> get_list() {
        return assets;
    }
};

class VideoPlayer {
    public:
    static void repeat(PlayList list) {
        vector<shared_ptr<MediaAsset>> original_list = list.get_list();
        vector<shared_ptr<MediaAsset>> filtered_list;
        copy_if(original_list.begin(), original_list.end(), back_inserter(filtered_list), [] (shared_ptr<MediaAsset> m) {
            shared_ptr<Video> temp = dynamic_pointer_cast<Video>(m);
            return temp.get() != nullptr;
        });

        for (auto video : filtered_list) {
            video->play();
        }

        cout << string(20, '_') << endl << endl;
    }
};

class SongPlayer {
    public:
    static void repeat(PlayList list) {
        vector<shared_ptr<MediaAsset>> original_list = list.get_list();
        vector<shared_ptr<MediaAsset>> filtered_list;
        copy_if(original_list.begin(), original_list.end(), back_inserter(filtered_list), [] (shared_ptr<MediaAsset> m) {
            shared_ptr<Song> temp = dynamic_pointer_cast<Song>(m);
            return temp.get() != nullptr;
        });

        for (auto song : filtered_list) {
            song->play();
        }

        cout << string(20, '_') << endl << endl;
    }
};


vector<array<string, 2>> list = { 
    { "Ed Sheerean", "Bad habits" },
    { "Britney Spears", "Hit me baby" },
    { "Aqua", "Barbie girl" },
    { "Michael Jackson MJ", "Just Beat It" }
};

int main() {
    PlayList play_list;

    for (auto input : list) {
        shared_ptr<Song> song =  make_shared<Song>(input[0], input[1]);
        shared_ptr<Video> video =  make_shared<Video>(input[0], input[1]);
        play_list.add_to_playlist(song);
        play_list.add_to_playlist(video);
    }

    SongPlayer song_player;
    song_player.repeat(play_list);

    VideoPlayer video_player;
    video_player.repeat(play_list);
}
