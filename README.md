# MorseTranslator

# Morse Code Translator

A menu-driven Morse Code Translator built in C++ that converts text into Morse code and Morse code back into text. The project supports alphabets (A-Z), numbers (0-9), translation history, and file handling for saving previous translations.

## Features

* Convert Text to Morse Code
* Convert Morse Code to Text
* Supports A-Z and 0-9
* Translation History Tracking
* Save History to `history.txt`
* Load Previous History Automatically
* User-Friendly Menu Interface

## Technologies Used

* C++
* STL (`unordered_map`, `vector`, `stringstream`)
* File Handling (`fstream`)

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/morse-code-translator.git
   ```

2. Navigate to the project folder:

   ```bash
   cd morse-code-translator
   ```

3. Compile the program:

   ```bash
   g++ MorseToText.cpp -o MorseToText
   ```

4. Run the executable:

   ```bash
   ./MorseToText
   ```

## Example

### Text to Morse

Input:

```text
HELLO 123
```

Output:

```text
.... . .-.. .-.. --- / .---- ..--- ...--
```

### Morse to Text

Input:

```text
.... . .-.. .-.. --- / .---- ..--- ...--
```

Output:

```text
HELLO 123
```

## Concepts Used

* Functions
* Loops
* Conditional Statements
* Switch Case
* Unordered Maps
* Vectors
* String Manipulation
* File Handling
* Data Persistence

## Future Improvements

* Morse Code Sound Effects
* GUI Version
* File Encryption
* Real-Time Translation
* Web-Based Version

## Author

**Vedant Bisht**

