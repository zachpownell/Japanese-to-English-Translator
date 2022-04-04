#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/*
    Word DFA:

    Regular Expression:
    ( (a | i | u | e | o | I | E) |
    (a | i | u | e | o | I | E) n |
    (b | d | g | h | j | k | m | n | p | r | s | t | w | y | z) (a | i | u | e | o | I | E) |
    (b | d | g | h | j | k | m | n | p | r | s | t | w | y | z) (a | i | u | e | o | I | E) n |
    (by | gy | hy | ky | my | ny | py | ry | ch | sh ) (a | i | u | e | o | I | E) |
    (by | gy | hy | ky | my | ny | py | ry | ch | sh ) (a | i | u | e | o | I | E) n)^+

 */

// word() function to check if our given word in the language is valid. This function is called every time we have a
// next word in our language.
bool word (string s) {

    /*
        0 = q0 (final state)
        1 = qsa
        2 = qt
        3 = qs
        4 = qy
        5 = q0qy (final state)
        6 = qc
        7 = q0q1 (final state)
    */

    // Assign the start state to be 0 (q0) and assign charpos to be 0.
    int state = 0;
    int charpos = 0;

    // Iterate through each character in given string s.
    while (s[charpos] != '\0') {

        // If-else statements to check which state we are in and move to the next state based on the given character.

        // From state 0 (q0), go to corresponding state based on the character at charpos.
        if (state == 0 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;
        } else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')){
            state = 1;
        } else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'
                                  || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')){
            state = 4;
        } else if (state == 0 && s[charpos] == 'c'){
            state = 6;
        } else if (state == 0 && s[charpos] == 't'){
            state = 2;
        } else if (state == 0 && s[charpos] == 's'){
            state = 3;

            // From state 1 (qsa), go to corresponding state based on the character at charpos.
        } else if (state == 1 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;

            // From state 2 (qt), go to corresponding state based on the character at charpos.
        } else if (state == 2 && s[charpos] == 's'){
            state = 1;
        } else if (state == 2 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;

            // From state 3 (qs), go to corresponding state based on the character at charpos.
        } else if (state == 3 && s[charpos] == 'h'){
            state = 1;
        } else if (state == 3 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;

            // From state 4 (qy), go to corresponding state based on the character at charpos.
        } else if (state == 4 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;
        } else if (state == 4 && s[charpos] == 'y'){
            state = 1;

            // From state 5 (q0qy), go to corresponding state based on the character at charpos.
        } else if (state == 5 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;
        } else if (state == 5 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')){
            state = 1;
        } else if (state == 5 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'
                                  || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')){
            state = 4;
        } else if (state == 5 && s[charpos] == 'c'){
            state = 6;
        } else if (state == 5 && s[charpos] == 't'){
            state = 2;
        } else if (state == 5 && s[charpos] == 's'){
            state = 3;

            // From state 6 (qc), go to corresponding state based on the character at charpos.
        } else if (state == 6 && s[charpos] == 'h'){
            state = 1;

            // From state 7 (q0q1), go to corresponding state based on the character at charpos.
        } else if (state == 7 && (s[charpos] == 'I' || s[charpos] == 'E' || s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s[charpos] == 'u')){
            state = 7;
        } else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'
                                  || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r')){
            state = 5;
        } else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j')){
            state = 1;
        } else if (state == 7 && s[charpos] == 'c'){
            state = 6;
        } else if (state == 7 && s[charpos] == 't'){
            state = 2;
        } else if (state == 7 && s[charpos] == 's') {
            state = 3;

            // Invalid state or character at charpos in string s. Return false.
        } else {
            return false;
        }

        charpos++; // Increment our charpos to get the next character in string s.

    } // End of while loop.

    // Check to see if we are in a final state or 0, 5, or 7 (q0, q0qy, or q0q1). If so, return true (valid word).
    if (state == 0 || state == 5 || state == 7) return true;

    return false; // We are not in a final state. Return false (invalid word).

}

/*
    Period DFA:
 */
bool period (string s) {

    // Check to see if given string s's size is greater than 1. If so, return false.
    if (s.size() > 1) {
        return false;
        // If the given string is not a period '.', return false.
    } else if(s != ".") {
        return false;
    }

    // It is a period.
    return true;

}

// ------ Three Tables -------------------------------------

// TABLES Done by: Zach Pownell

// Dumping ALL token types from documentation here
enum tokentype {WORD, WORD1, WORD2, PERIOD, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM, ERROR};
// Per instructions: this list of strings directly matches the above. I think We have freedom to change but for now i left it.
string tokenName[30] = {"WORD", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM", "ERROR"};

// ** Need the reservedwords table to be set up here.

/* I am setting this up like above:
 * reservedWords and reservedTokens will be of identical length. I plan to traverse the Words list for a match
 * grab the index of the match (if applicable) and then use that to access the corresponding token from the tokens list
*/
const int reservedWordCount = 18;
string reservedWords[reservedWordCount]= {"masu", "masen", "mashita", "masendeshita", "desu", "deshita", "o", "wa", "ni", "watashi",
                                          "anata", "kare", "anojo", "sore", "mata", "soshite", "shikashi", "dakara"};
tokentype reservedTokens[reservedWordCount] = {VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN,
                                               PRONOUN, PRONOUN, PRONOUN, PRONOUN, CONNECTOR, CONNECTOR, CONNECTOR, CONNECTOR};

// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// ------------ Scanner and Driver -----------------------

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Zach Pownell and Larry Haskel
int scanner(tokentype& tt, string& w)
{
    // ** Grab the next word from the file via fin
    // 1. If it is eofm, return right now.

    /*  **
    2. Call the token functions (word and period)
       one after another (if-then-else).
       Generate a lexical error message if both DFAs failed.
       Let the tokentype be ERROR in that case.
    3. If it was a word,
       check against the reservedwords list.
       If not reserved, tokentype is WORD1 or WORD2
       decided based on the last character.
    4. Return the token type & string  (pass by reference)
    */

    fin >> w;  // grab next word from input file
    if (w == "eofm"){                 // Check for EOF -> return if EOF
        tt = EOFM;
    }else if(word(w)){                // Check for WORD
        tt = WORD;
    } else if (period(w)){            // Check for PERIOD
        tt = PERIOD;
    } else //none of the FAs returned TRUE
    { cout << "Lexical error: " << w << " is not a valid token" << endl;
        tt = ERROR; }

    // If word check for word1 or word2
    if (tt == WORD){
        if(w[w.size()-1] == 'I' || w[w.size()-1] == 'E'){
            tt = WORD2;
        }else if(w[w.size()-1] == 'n' || w[w.size()-1] == 'a' || w[w.size()-1] == 'e' || w[w.size()-1] == 'i' || w[w.size()-1] == 'o' || w[w.size()-1] == 'u'){
            tt = WORD1;
        }
        // Capture token for reserved word if present
        for(int i = 0; i < reservedWordCount; i++){
            if (w == reservedWords[i]){
                tt = reservedTokens[i];
            }
        }
    }
    if (tt == WORD){
        cout << "Lexical error: " << w << " is not a valid token" << endl;
        tt = ERROR;
    }
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly.
int main() {

    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename.c_str());

    // the loop continues until eofm is returned.
    while (true) {

        scanner(thetype, theword);  // call the scanner which sets
        // the arguments
        if (theword == "eofm") break;  // stop now

        cout << "Type is:" << tokenName[thetype] << endl;
        cout << "Word is:" << theword << endl;
        cout << endl; // added this to space out each word

    }

    cout << "End of file is encountered." << endl;
    fin.close();

}// end