#include <iostream>
#include <map>
#include <vector>
#include <string>

class DirectoryManager {
public:
    void createFolder(const std::string& folderName) {
        if (directories.find(folderName) == directories.end()) {
            directories[folderName] = std::vector<std::string>();
        } else {
            std::cout << "Folder already exists.\n";
        }
    }

    void addFileToFolder(const std::string& folderName, const std::string& fileName) {
        if (directories.find(folderName) != directories.end()) {
            directories[folderName].push_back(fileName);
        } else {
            std::cout << "Folder not found.\n";
        }
    }

    void displayDirectoryStructure() const {
        std::cout << "Directory Structure:\n";
        for (const auto& folder : directories) {
            std::cout << folder.first << ":\n";
            for (size_t i = 0; i < folder.second.size(); ++i) {
                std::cout << "  " << folder.second[i] << "\n";
            }
        }
    }

private:
    std::map<std::string, std::vector<std::string>> directories;
};

int main() {
    DirectoryManager dirManager;

    dirManager.createFolder("Documents");
    dirManager.createFolder("Images");
    dirManager.createFolder("Projects");

    dirManager.addFileToFolder("Documents", "file1.txt");
    dirManager.addFileToFolder("Documents", "file2.docx");
    dirManager.addFileToFolder("Images", "image1.jpg");
    dirManager.addFileToFolder("Projects", "project1.cpp");

    dirManager.displayDirectoryStructure();

    return 0;
}
