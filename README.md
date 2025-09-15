## author: *Ron Konchitsky*

## introduction

This project is essentially a copy of the Wordle game.

## function 1:score_guess(char *secret, char *guess, char *result)

Returns true if the guess matches the secret--false otherwise. This will also change the given result string (x if the corresponding character is not in the given string, y if it is there somewhere, and g if it is the correct character in the correct spot). This uses a helper function get_respective_char() which returns the corresponding char by iterating through the given string.

## function 2: bool valid_guess(char *guess, char **vocabulary, size_t num_words) 

Returns true if guess is within the list of strings (**vocabulary). Iterates through every word in vocab and uses the helper function in_vocab() to see if the guess is in every vocab word.

## function 3: char **load_vocabulary(char *filename, size_t *num_words)

This will return a list of strings from the given file. The file is a list of words --seperated by a line. This will use the pointer *num_words to keep track of the current string that the pointer is on, it helps keep track of the amount of strings scanned. This is important as this function has to expand the memory allocated for each new word.

## function 4: void free_vocabulary(char **vocabulary, size_t num_words)

Given an array of strings (**vocabulary), this will free every string in the list, including the pointer to each of the strings.
