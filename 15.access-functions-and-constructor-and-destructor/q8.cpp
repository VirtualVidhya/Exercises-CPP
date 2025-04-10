#include <iostream>
#include <string>

class TextEditor
{
private:
    std::string documentName;
    std::string content;
    bool isSaved;

public:
    TextEditor(const std::string &name) : documentName(name), isSaved(false)
    {
        std::cout << "Document '" << documentName << "' created.\n";
        std::cout << "Editing document...\n";
    }

    void write(const std::string &text)
    {
        content += text + "\n";
        isSaved = false;
    }

    void exitEditor()
    {
        std::cout << "User exits the editor.\n";
        char choice;
        std::cout << "Do you want to save manually? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            save();
        }
        else
        {
            createBackup();
        }

        std::cout << "Closing the text editor...\n";
        std::cout << "System exited.\n";
    }

    void save()
    {
        std::cout << "Document saved successfully!\n";
        isSaved = true;
        createBackup(); // Always create a backup
    }

    void createBackup()
    {
        std::cout << "Backup save created.\n";
    }

    ~TextEditor()
    {
        if (!isSaved)
        {
            std::cout << "Unexpected shutdown detected!\n";
            std::cout << "Auto-saving unsaved changes...\n";
            createBackup();
            std::cout << "System exited.\n";
        }
    }
};

int main()
{
    // Simulating Case 1: User manually saves
    {
        TextEditor editor1("ProjectNotes.txt");
        editor1.write("Some important notes...");
        editor1.exitEditor();
    }

    std::cout << "\n";

    // Simulating Case 2: User chooses not to save
    {
        TextEditor editor2("ProjectNotes.txt");
        editor2.write("Some important notes...");
        // Simulating exit without saving
        editor2.exitEditor();
    }

    std::cout << "\n";

    // Simulating Case 3: Unexpected shutdown (Destructor will handle it)
    {
        TextEditor editor3("ProjectNotes.txt");
        editor3.write("Some important notes...");
        // No manual exit, so destructor will be called unexpectedly
    }

    return 0;
}
