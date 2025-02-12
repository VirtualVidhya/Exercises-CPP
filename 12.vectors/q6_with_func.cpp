#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void displayMenu()
{
    std::cout << "\n----------------\n"
              << "# Options:\n"
              << "\n1. Create a new playlist\n"
              << "2. Add a song to a playlist\n"
              << "3. Remove a song from a playlist\n"
              << "4. View all playlists\n"
              << "5. Exit\n"
              << "----------------\n"
              << "Enter your choice: ";
}

void createPlaylist(std::vector<std::vector<std::string>> &playlists, std::vector<std::string> &genres)
{
    std::string genre;
    std::cout << "\nEnter genre: ";
    std::getline(std::cin >> std::ws, genre);
    genres.push_back(genre);
    playlists.emplace_back();
    std::cout << "\nPlaylist \"" << genre << "\" created!\n";
}

void addSong(std::vector<std::vector<std::string>> &playlists, std::vector<std::string> &genres)
{
    std::string genre, song;
    std::cout << "\nEnter playlist genre: ";
    std::getline(std::cin >> std::ws, genre);

    auto it = std::find(genres.begin(), genres.end(), genre);
    if (it == genres.end())
    {
        std::cout << "\nPlaylist \"" << genre << "\" does not exist!\n";
        return;
    }

    int index = std::distance(genres.begin(), it);
    std::cout << "\nEnter song name: ";
    std::getline(std::cin >> std::ws, song);
    playlists[index].push_back(song);
    std::cout << "\n\"" << song << "\" added to " << genre << " playlist!\n";
}

void removeSong(std::vector<std::vector<std::string>> &playlists, std::vector<std::string> &genres)
{
    std::string genre, song;
    std::cout << "\nEnter playlist genre: ";
    std::getline(std::cin >> std::ws, genre);

    auto it = std::find(genres.begin(), genres.end(), genre);
    if (it == genres.end())
    {
        std::cout << "\nPlaylist \"" << genre << "\" does not exist!\n";
        return;
    }

    int index = std::distance(genres.begin(), it);
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

void viewPlaylists(const std::vector<std::vector<std::string>> &playlists, const std::vector<std::string> &genres)
{
    std::cout << "\nYour Playlists:\n";
    int maxSongs = 0;
    std::string maxGenre;

    for (size_t i = 0; i < genres.size(); ++i)
    {
        if (!playlists[i].empty())
        {
            std::cout << genres[i] << "\n";
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

    std::cout << "\nSummary:\n"
              << "- Total Playlists: " << playlists.size() << "\n";
    if (!maxGenre.empty())
    {
        std::cout << "- Playlist with the most songs: " << maxGenre << "\n";
    }
}

int main()
{
    std::vector<std::vector<std::string>> playlists;
    std::vector<std::string> genres;
    int choice;

    std::cout << "Music Playlist Organizer\n";

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        if (!(std::cin >> choice))
        {
            std::cout << "\nInvalid input! Please enter a number.\n";
            std::cin.clear();              // Clear error flag
            std::cin.ignore(10000, '\n');  // Discard incorrect input
            continue;                      // Restart the loop
        }

        switch (choice)
        {
        case 1:
            createPlaylist(playlists, genres);
            break;
        case 2:
            addSong(playlists, genres);
            break;
        case 3:
            removeSong(playlists, genres);
            break;
        case 4:
            viewPlaylists(playlists, genres);
            break;
        case 5:
            std::cout << "\nGoodbye! Keep enjoying your music!\n";
            return 0;
        default:
            std::cout << "\nInvalid choice, try again!\n";
        }
    }
}
