#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//		min		minimum
//		max		maximum
//		avg		average
//		std		standard
//		temp	temporary (try not to use "temp" by itself as a variable name.  Say what the temporary holds.)
//		num		number of (when used as a prefix only.  Used as a suffix, it indicates an index or ID number.
//					       for example, numFiles is the number of files you have.  fileNum is the ID number
//						   of one particular file.)
//
//	Some people, notably people who learned to use C-style in C++, also use "in" as a prefix for "input",
//  and "out" as a prefix for "output".  My preference is to not use these prefixes.
//
//  In general, except in the case of the standard prefixes, I advocate writing words out fully.  Don't use
//  "rng" for "range", for instance.  As another example, it would be disastrous to abbreviate "comparisons"
//  in the following main() function as "comp".  When the brain sees "comp" it has to sort out what that
//  means--it could be "computer" or "comprehensive" or "complete" or "computation", etc.--so writing it
//  out is essential.  Most of the comments in the code are meant to help out students and could be eliminated
//  in professional code.


class FileOpeningException {
private:
	string errorMessage;
public:
	FileOpeningException(string message) {
		errorMessage = message;
	}
	string getMessage() {
		return errorMessage;
	}
};


int isInAlphabeticalOrder(string s);
string* readWords(string filename, int & arraySize);
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException);

int main (void) {
	int numWords;
	string wordListFilename = "wordlist";
	string outputFilename = "average_comps.txt";

	// This reads the words from wordListFilename.
	// numWords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wordListFilename, numWords);



	// Print out the list.
	/*
	for (int i=0; i<numWords; i++) {
		cout << words[i] << endl;
	}
*/

	// TO DO:: You should compute these values.
	float avgWordLength;
	float avgNumComparisons;
	int maxWordLength=0;
	float *avgComparisonsForLength;  // avgComparisonsForLength[i] is the average number of comparisons for a word of length i.
	int i = 0;
 	float total_word_count = 0.0;
 	float total_char_count = 0.0;

	// TO DO:: Insert your code here.

		while(i < numWords)
	{
		if(maxWordLength <  int(words[i].length()))
		{
			maxWordLength = words[i].size();
		}

		total_char_count += isInAlphabeticalOrder(words[i]);
		total_word_count += words[i].size();
		i++;
	}

	//avgWordLength =  float(total_word_count/numWords);
	//avgNumComparisons = float(total_char_count/numWords);
	//cout << "average word length:" << avgWordLength << endl;
	//cout << "total char count:" << avgNumComparisons << endl;


	/* storing the total word compares and char compares into 2 differant arrays*/

	float word_size[maxWordLength] = {};
	float char_compare[maxWordLength]= {};
	int word_comp_sum = 0;
	int size = 0;
/*computing the lengths of x for each word and storing into an array */
	for(int i = 0 ; i < numWords ; i++)
	{
		size = words[i].size();
		word_size[size]++;
	}

/*computing the sum of comparrisons on each word and storig it into the array */

for(int i = 0; i < numWords; i++)
{
	word_comp_sum = words[i].size();
	char_compare[word_comp_sum] += isInAlphabeticalOrder(words[i]);
}
/* now we store the avg into our dynammixally allocated array of avgComparisonsForLength*/
avgComparisonsForLength = new float[maxWordLength];

for(int i = 0 ; i < maxWordLength ; i++)
{
 		avgComparisonsForLength[i]= float(char_compare[i] / word_size[i]);
}

//printing the list;


	for(int i = 0; i < maxWordLength ; i++)
	{
		cout << avgComparisonsForLength[i] << endl;
	}

	// Print average number of comparisons for each length to a file for plotting.
	writeArray(outputFilename, avgComparisonsForLength, maxWordLength);

	// Clean up memory and return.
	delete[] words;
	delete[] avgComparisonsForLength;
	return 0;
}



// Writes the array arr in text format to a file named filename.
// each element of the array has its own line in the file,
// which contains the element's index and value, separated by a space.
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException) {
	ofstream outputStream(filename.c_str());

	if (outputStream.fail()) {
		throw new FileOpeningException("Error opening " + filename);
	}

	for (int i = 0; i<arraySize; i++) {
		outputStream << i << " " << arr[i] << endl;
	}
	outputStream.close();
}

int numLinesInStream(ifstream& stream) {
	int numLines = 0;
	string tempLine;

	// getline returns 0 at end of file.
	while (getline(stream, tempLine)) {
		numLines++;
	}
	return numLines;
}

// note how the following function is all about one thing:
// the handling of the ifstream called inputStream().
// the exact computation done using inputStream() is abstracted
// to a single call (to numLinesInStream).
// Here, I don't declare the thrown object with a "throw ()" on the
// first line.  It's optional, so I'm leaving it off this time.
int numLinesInFile(string filename) {
	ifstream inputStream(filename.c_str());

	if (inputStream.fail()) {
		throw new FileOpeningException(filename + "... file not found ...");
	}

	int numLines = numLinesInStream(inputStream);

	inputStream.close();
	return numLines;
}

// Reads lines from a file named filename.
// Returns an array of strings, one per line of the file filename,
// and places the size of the array in the reference parameter (output parameter) arraySize
string* readWords(string filename, int & arraySize) {
	string* result = NULL;
	arraySize = numLinesInFile(filename);
	ifstream inputStream(filename.c_str());

	// Read file contents into result, now that size is known
	result = new string[arraySize];			//create results array
	for (int i=0; i < arraySize; i++){
		getline(inputStream, result[i]);
	}
	inputStream.close(); //don't forget to close file

    return result;
}



int isInAlphabeticalOrder(string s)
{
	int len = s.size();
	int count = 0;

	for(int i = 0 ; i < len-1; i++)
	{
		if(s[i] > s[i+1])
		{
			count++;
			return count;
		}
		count++;

	}
		return count;
}
