#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

// Functions
void characters(map<char, pair<int,int>> &characterMap);
void words(map<string, pair<int,int>> &wordMap);
void numbers(map<string, pair<int,int>> &numberMap);

// *****************************************************************
// * Function Name:  main()                                        *
// * Description: Calculate the top words/numbers/characters       *
// * from a standard input text file                               *
// * Parameter Description:  No parameters                         *
// * Date:  03/02/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
int main(){
    // Declare variables
    string word;
    string number;
    char character;
    // Maps that hold the characters/word/number in standard input
    // First int holds the frequency counter
    // Second int holds the priority number
    map<string, pair<int,int>> wordMap;
    map<string, pair<int,int>> numberMap;
    map<char, pair<int,int>> characterMap;

    while(cin.good()) {
        // Increment character count each time the while loop runs
        cin.get(character);
        if(isalpha(character)){ // If character is a letter....
            word += tolower(character); // Concatenate uppercase characters to word

            if(!number.empty()){ // Check if number string has any characters...
                ++numberMap[number].first; // Increment number count for the specific number string
                if(numberMap[number].first == 1) { // Only update the priority if it is a new number
                    numberMap[number].second = numberMap.size();
                }
                number = ""; // Reset number string
            }
        }else if(isdigit(character)){ // If character is a number...
            number += character; // Concatenate character to number

            if(!word.empty()){ // Check if word string has any characters...
                ++wordMap[word].first; // Increment word count for the specific word string
                if(wordMap[word].first == 1) { // Only update the priority if it is a new word
                    wordMap[word].second = wordMap.size();
                }
                word = ""; // Reset word string
            }
        }else{ // Character is not alpha-numeric...
            if(!word.empty()){ // Check if word string has any characters...
                ++wordMap[word].first; // Increment word count for the specific word string
                if(wordMap[word].first == 1) { // Only update the priority if it is a new word
                    wordMap[word].second = wordMap.size();
                }
                word = ""; // Reset word string
            }
            if(!number.empty()){ // Check if number string has any characters...
                ++numberMap[number].first; // Increment number count for the specific number string
                if(numberMap[number].first == 1){ // Only update the priority if it is a new number
                    numberMap[number].second = numberMap.size();
                }
                number = ""; // Reset number string
            }
        }
        ++characterMap[character].first;
        characterMap[character].second = (int)character;
    }
    // Do last check to see if there are any words or numbers that haven't been counted in
    if(!word.empty()){ // Check if word string has any characters...
        ++wordMap[word].first; // Increment word count for the specific word string
        if(wordMap[word].first == 1) { // Only update the priority if it is a new word
            wordMap[word].second = wordMap.size();
        }
    }
    if(!number.empty()){ // Check if number string has any characters...
        ++numberMap[number].first; // Increment number count for the specific number string
        if(numberMap[number].first == 1){ // Only update the priority if it is a new number
            numberMap[number].second = numberMap.size();
        }
    }
    // Call to functions that will display the top words, numbers, and characters respectively
    words(wordMap);
    numbers(numberMap);
    characters(characterMap);

    return 0;
}

// **********************************************************************************************
// * Function Name:  words()                                                                    *
// * Description: Calculate the top words from wordMap                                          *
// * Parameter Description:  map<string, int> wordMap, holds                                    *
// * all of the words from the standard input                                                   *
// * Date:  03/02/2022                                                                          *
// * Author:   Peyton J. Smith                                                                  *
// * References:  https://stackoverflow.com/questions/26281979/c-loop-through-map               *
// * Used to iterate/traverse through map to find the max value                                 *
// **********************************************************************************************
void words(map<string, pair<int,int>> &wordMap){
    int numberOfWords;
    // Check if there are less than 10 words available
    // If so, display only those limited number of words
    // If greater than 10, only display the top 10 words
    if(wordMap.size() <= 10){
        numberOfWords = wordMap.size();
    }else{
        numberOfWords = 10;
    }
    cout << endl;
    cout << "There are " << wordMap.size() << " Unique Words, The Top " << numberOfWords << " Words:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;

    map<string, pair<int,int>>::iterator it;
    // Iterate to find the top 10 or less words.
    for(int i = 0; i<numberOfWords; i++){
        // Taken from Stack Overflow on iterating through map
        auto best = wordMap.begin(); // Initialize best iterator
        for(it = wordMap.begin(); it != wordMap.end(); it++){ // Traverse through the map
            // If iterator's frequency is greater than best's frequency, update best
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ // If the frequencies are the same...
                // Check their priority, if iterator's priority is lower than best's priority, update best
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
        // Display values
        cout << "[  " << i << "] " << setw(12) << best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        wordMap.erase(best); // Erase max value in map to use for next iteration
    }
}

// **********************************************************************************************
// * Function Name:  numbers()                                                                  *
// * Description: Calculate the top numbers from numberMap                                      *
// * Parameter Description:  map<string, int> numberMap, holds                                  *
// * all of the numbers from the standard input                                                 *
// * Date:  03/02/2022                                                                          *
// * Author:   Peyton J. Smith                                                                  *
// * References:  https://stackoverflow.com/questions/26281979/c-loop-through-map               *
// * Used to iterate/traverse through map to find the max value                                 *
// **********************************************************************************************
void numbers(map<string, pair<int,int>> &numberMap){
    int numberOfNumbers;
    // Check if there are less than 10 numbers available
    // If so, display only those limited number of numbers
    // If greater than 10, only display the top 10 numbers
    if(numberMap.size() <= 10){
        numberOfNumbers = numberMap.size();
    }else{
        numberOfNumbers = 10;
    }
    cout << endl;
    cout << "There are " << numberMap.size() << " Unique Numbers, The Top " << numberOfNumbers << " Numbers:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;

    map<string, pair<int,int>>::iterator it;
    // Iterate to find the top 10 or less numbers.
    for(int i = 0; i<numberOfNumbers; i++){
        // Taken from Stack Overflow on iterating through map
        auto best = numberMap.begin(); // Initialize best iterator
        for(it = numberMap.begin(); it != numberMap.end(); it++){ // Traverse through the map
            // If iterator's frequency is greater than best's frequency, update best
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ // If the frequencies are the same...
                // Check their priority, if iterator's priority is lower than best's priority, update best
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
        // Display values
        cout << "[  " << i << "] " << setw(12) << best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        numberMap.erase(best); // Erase max value in map to use for next iteration
    }
}

// **********************************************************************************************
// * Function Name:  characters()                                                               *
// * Description: Calculate the top characters from characterMap                                *
// * Parameter Description:  map<char, int> characterMap, holds                                 *
// * all of the characters from the standard input                                              *
// * Date:  03/02/2022                                                                          *
// * Author:   Peyton J. Smith                                                                  *
// * References:  https://stackoverflow.com/questions/26281979/c-loop-through-map               *
// * Used to iterate/traverse through map to find the max value                                 *
// **********************************************************************************************
void characters(map<char, pair<int,int>> &characterMap){
    int numberOfCharacters;
    // Check if there are less than 10 characters available
    // If so, display only those limited number of characters
    // If greater than 10, only display the top 10 characters
    if(characterMap.size() <= 10){
        numberOfCharacters = characterMap.size();
    }else{
        numberOfCharacters = 10;
    }
    cout << endl;
    cout << "There are " << characterMap.size() << " Unique Words, The Top " << numberOfCharacters << " Characters:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;

    map<char, pair<int,int>>::iterator it;
    // Iterate to find the top 10 or less characters.
    for(int i = 0; i<numberOfCharacters; i++){
        // Taken from Stack Overflow on iterating through map
        auto best = characterMap.begin(); // Initialize best iterator
        for(it = characterMap.begin(); it != characterMap.end(); it++){ // Traverse through the map
            // If iterator's frequency is greater than best's frequency, update best
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ // If the frequencies are the same...
                // Check their priority, if iterator's priority is lower than best's priority, update best
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
        // Display values
        if(best->first == '\n'){ // If character is a newline character...
            cout << "[  " << i << "] " << setw(12) << "Newline" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else if(best->first == '\t'){ // If character is a tab character...
            cout << "[  " << i << "] " << setw(12) << "Tab" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else if(best->first == ' '){ // If character is a space character...
            cout << "[  " << i << "] " << setw(12) << "Space" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else{ // If none of the above...
            cout << "[  " << i << "] " << setw(12) <<best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }
        characterMap.erase(best); // Erase max value in map to use for next iteration
    }
}
