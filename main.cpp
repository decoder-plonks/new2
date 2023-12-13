#include <iostream>
#include <sstream>
#include <unordered_map>

// Function to count occurrences of each word in a text
std::unordered_map<std::string, int> countWordOccurrences(const std::string& text) {
    std::unordered_map<std::string, int> wordCount;
    std::istringstream iss(text);

    std::string word;
    while (iss >> word) {
        // Remove punctuation from the word (considering only alphabets)
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Convert the word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Increment the count for the word
        wordCount[word]++;
    }

    return wordCount;
}

int main() {
    std::string inputText;

    // Read a text from the user
    std::cout << "Enter a text: ";
    std::getline(std::cin, inputText);

    // Count word occurrences
    std::unordered_map<std::string, int> wordOccurrences = countWordOccurrences(inputText);

    // Displa the word occurrences
    std::cout << "\nWord Occurrences:\n";
    for (const auto& pair : wordOccurrences) {
        std::cout << "\"" << pair.first << "\": " << pair.second << " occurrences\n";
    }

    return 0;
}
