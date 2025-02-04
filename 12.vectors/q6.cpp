#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::vector<std::string>> playlists;
    std::vector<std::string> genres;
    std::string genre, song;
    int choice;

    std::cout << "Music Playlist Organizer\n";

    while (true)
    {
        std::cout << "\n----------------\n";
        std::cout << "# Options:\n";
        std::cout << "\n1. Create a new playlist\n"
                  << "2. Add a song to a playlist\n"
                  << "3. Remove a song from a playlist\n"
                  << "4. View all playlists\n"
                  << "5. Exit\n";
        std::cout << "----------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        // std::cin.ignore(); // Ignore newline after choice input

        if (choice == 1)
        {
            std::cout << "\nEnter genre: ";
            std::getline(std::cin >> std::ws, genre);
            genres.push_back(genre); // Store genre name
            playlists.push_back({}); // Create a new empty playlist for the genre
            std::cout << "\nPlaylist \"" << genre << "\" created!\n";
        }
        else if (choice == 2)
        {
            std::cout << "\nEnter playlist genre: ";
            std::getline(std::cin >> std::ws, genre);

            auto it = std::find(genres.begin(), genres.end(), genre);
            if (it == genres.end())
            {
                std::cout << "\nPlaylist \"" << genre << "\" does not exist!\n";
                continue;
            }

            int index = std::distance(genres.begin(), it); // Find the index of the genre in the genres vector
            std::cout << "\nEnter song name: ";
            std::getline(std::cin >> std::ws, song);
            playlists[index].push_back(song);
            std::cout << "\n\"" << song << "\" added to " << genre << " playlist!\n";
        }
        else if (choice == 3)
        {
            std::cout << "\nEnter playlist genre: ";
            std::getline(std::cin >> std::ws, genre);

            auto it = std::find(genres.begin(), genres.end(), genre);
            if (it == genres.end() || playlists[std::distance(genres.begin(), it)].empty())
            {
                std::cout << "\nPlaylist \"" << genre << "\" does not exist or is empty!\n";
                continue;
            }

            int index = std::distance(genres.begin(), it); // Find the index of the genre
            std::cout << "\nEnter song name to remove: ";
            std::getline(std::cin >> std::ws, song);

            auto &songs = playlists[index];
            auto songIt = std::find(songs.begin(), songs.end(), song);
            if (songIt != songs.end())
            {
                songs.erase(songIt);
                std::cout << "\n\"" << song << "\" removed from " << genre << " playlist!\n";
            }
            else
            {
                std::cout << "\nSong \"" << song << "\" not found in " << genre << " playlist!\n";
            }
        }
        else if (choice == 4)
        {
            std::cout << "\nYour Playlists:\n";
            int maxSongs = 0;
            std::string maxGenre;

            for (size_t i = 0; i < genres.size(); ++i)
            {
                if (!playlists[i].empty())
                {
                    std::cout << "" << genres[i] << "\n";
                    for (const auto &s : playlists[i])
                    {
                        std::cout << "   - " << s << "\n";
                    }
                    if (playlists[i].size() > maxSongs)
                    {
                        maxSongs = playlists[i].size();
                        maxGenre = genres[i];
                    }
                }
            }

            std::cout << "\nSummary:\n";
            std::cout << "- Total Playlists: " << playlists.size() << "\n";
            if (!maxGenre.empty())
            {
                std::cout << "- Playlist with the most songs: " << maxGenre << "\n";
            }
        }
        else if (choice == 5)
        {
            std::cout << "\nGoodbye! Keep enjoying your music!\n";
            break;
        }
        else
        {
            std::cout << "\nInvalid choice, try again!\n";
        }
    }

    return 0;
}
