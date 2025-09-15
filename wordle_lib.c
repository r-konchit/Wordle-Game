#include "wordle_lib.h"
#include <stdlib.h>

// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)


char get_respective_char(char *secret, char guess, int pos){
  // goes through secret and compares to guess
  // 'x' if that character is not in 'hello'
  // 'y' if that character is in 'hello' but in the wrong slot
  // 'g' if that character is in the right place with respect to the current character in 'hello'
  if (guess == secret[pos]) return 'g';
  for (int i = 0; i < (int)strlen(secret); i++){
      if (guess == secret[i]) return 'y';
  }
  return 'x';
}

bool score_guess(char *secret, char *guess, char *result) {

  if (strlen(secret) != strlen(guess)) return false;
//  int c = 0;
  for (int i = 0; i < (int)strlen(guess); i++){
     char t =  get_respective_char(secret, guess[i], i);
     result[i] = t;
//     c++;
  }

  return strcmp(guess, secret) == 0;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?


bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  for (int i = 0; i < (int)num_words; i++){
//      if (strlen(vocabulary[i]) != strlen(guess)) return false;
      if(strcmp(vocabulary[i], guess) == 0) return true;
  }
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  char **out = NULL;
  size_t words_count = 0; // increment this counter each time reading a word and num_words equal to this counter
  size_t c = 1;
  FILE *file = fopen(filename, "r");
  // using realloc for each word added to out


  out = (char**)malloc(1 * sizeof(char*));

  char buffer[256];
  while (fgets(buffer, sizeof(buffer), file)){
    buffer[strcspn(buffer, "\n")] = '\0';
    out = realloc(out, (c++) * sizeof(char*));
    out[words_count] = strdup(buffer);
    words_count++;
  }

  *num_words = words_count;
  fclose(file);
  return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for (size_t i = 0; i < num_words; i++){
    free(vocabulary[i]);
  }
  free(vocabulary);
}
