#include <stdio.h>
#include <string.h>
#define max 100

char pattern[max];
char text[max];


// Function to compute the Longest Prefix Suffix (LPS) array
// LPS[i] = the length of the longest proper prefix which is also a suffix for pattern[0..i]
void computeLPSArray(char pattern[], int M, int lps[]) {
	int len = 0;        // Length of the previous longest prefix suffix
	lps[0] = 0;         // LPS for the first character is always 0

	int i = 1;
	while (i < M) {
		if (pattern[i] == pattern[len]) {
			// Characters match, extend current LPS length
			len++;
			lps[i] = len;
			i++;
		} else {
			// Mismatch after len matches
			if (len != 0) {
				// Try shortening the current LPS length using previous LPS
				len = lps[len - 1];
			} else {
				// No prefix matches, set LPS to 0
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Function to perform KMP pattern searching algorithm
void KMPSearch(char pattern[], char text[], int M, int N) {
	int lps[M];  // Create LPS array for the pattern

	// Step 1: Preprocess the pattern to fill the LPS array
	computeLPSArray(pattern, M, lps);

	int i = 0;  // Index for text[]
	int j = 0;  // Index for pattern[]

	// Step 2: Search the pattern in the text using the LPS array
	while (i < N) {
		if (pattern[j] == text[i]) {
			// Characters match, move both indices
			i++;
			j++;
		}

		if (j == M) {
			// Full pattern matched
			printf("Pattern found at index %d\n", i - j);
			// Use LPS to skip unnecessary comparisons
			j = lps[j - 1];
		} else if (i < N && pattern[j] != text[i]) {
			// Mismatch after j matches
			if (j != 0) {
				// Shift the pattern using LPS
				j = lps[j - 1];
			} else {
				// No prefix matched yet, move to next character in text
				i++;
			}
		}
	}
}

// Main driver function
int main() {
	strcpy(text, "ABABDABACDABABCABAB");
	strcpy(pattern, "ABABCABAB");

	// Call KMP search with pattern and text lengths
	KMPSearch(pattern, text, strlen(pattern), strlen(text));

	return 0;
}
