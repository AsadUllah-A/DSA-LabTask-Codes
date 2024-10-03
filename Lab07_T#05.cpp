#include <iostream>
#include <string>

using namespace std;

// Node structure for the doubly linked list
class Song
{
public:
    string title;  // Song title
    string artist; // Artist name
    Song *next;    // Pointer to the next song
    Song *prev;    // Pointer to the previous song

    // Constructor
    Song(string t, string a) : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

// Playlist class managing the doubly linked list
class Playlist
{
private:
    Song *head; // Pointer to the head of the list
    Song *tail; // Pointer to the tail of the list

public:
    Playlist() : head(nullptr), tail(nullptr) {}

    ~Playlist()
    {
        while (head != nullptr)
        {
            Song *temp = head;
            head = head->next;
            delete temp; // Free memory
        }
    }

    // Add a new song to the end of the playlist
    void addSong(const string &title, const string &artist)
    {
        Song *newSong = new Song(title, artist);
        if (head == nullptr)
        {
            head = newSong; // If the playlist is empty, set head to new song
            tail = newSong; // Set tail to new song as well
        }
        else
        {
            tail->next = newSong; // Link new song at the end
            newSong->prev = tail; // Set previous pointer
            tail = newSong;       // Update tail
        }
        cout << "Added: " << title << " by " << artist << "\n";
    }

    // Traverse the playlist forwards
    void traverseForward() const
    {
        Song *current = head;
        cout << "Playlist (Forward):\n";
        while (current != nullptr)
        {
            cout << current->title << " by " << current->artist << "\n";
            current = current->next; // Move to the next song
        }
    }

    // Traverse the playlist backwards
    void traverseBackward() const
    {
        Song *current = tail;
        cout << "Playlist (Backward):\n";
        while (current != nullptr)
        {
            cout << current->title << " by " << current->artist << "\n";
            current = current->prev; // Move to the previous song
        }
    }

    // Delete a song from the playlist by title
    void deleteSong(const string &title)
    {
        Song *current = head;

        while (current != nullptr)
        {
            if (current->title == title)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next; // Link previous to next
                }
                else
                {
                    head = current->next; // Deleting head
                }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev; // Link next to previous
                }
                else
                {
                    tail = current->prev; // Deleting tail
                }

                delete current; // Free the memory
                cout << "Deleted: " << title << "\n";
                return;
            }
            current = current->next; // Move to the next song
        }
        cout << "Song not found: " << title << "\n";
    }
};

int main()
{
    Playlist playlist;
    int choice;
    string title, artist;

    do
    {
        cout << "\n1. Add Song\n2. Traverse Forward\n3. Traverse Backward\n4. Delete Song\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter artist name: ";
            getline(cin, artist);
            playlist.addSong(title, artist);
            break;

        case 2:
            playlist.traverseForward();
            break;

        case 3:
            playlist.traverseBackward();
            break;

        case 4:
            cout << "Enter song title to delete: ";
            cin.ignore();
            getline(cin, title);
            playlist.deleteSong(title);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}