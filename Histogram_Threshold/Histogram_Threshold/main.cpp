#include <iostream>
#include <string>
#include <fstream>
#include"image.h"
using namespace std;

int main(int argc, char* argv[]) {
	ifstream input_file;
	ofstream output_file1;
	ofstream output_file2;
	ofstream output_file3;
	ofstream output_file4;
	input_file.open(argv[1]);
	output_file1.open(argv[2]);
	output_file2.open(argv[3]);
	output_file3.open(argv[4]);
	output_file4.open(argv[5]);
	long threshold = strtol(argv[6], NULL, 10);
	/* -----------------PART 1 ------------------- */
	/* Part 1: Compute histogram. The histogram of an image is the statistic counting of pixel values in the input image, where hist[i] tells how many pixels having value i in the input image.  */
	//place to store information of the file
		//parameters[0] = rows
		//parameters[1] = cols
		//parameters[2] = min
		//parameters[3] = max
	int parameters[4];
	for (int i = 0; i < 4; i++) {
		//get the information of the input file
		input_file >> parameters[i];
	}
	image image(parameters[0], parameters[1], parameters[2], parameters[3], threshold);
	image.computeHist(input_file, output_file1, output_file4);
	//close output file from argv[2]
	output_file1.close();


	/* -----------------PART 2 ------------------- */
	/*Part 2: Perform binary threshold operation on the input image using the threshold values provide by the user via argv.
	The binary threshold operation is the simplest way to extract foreground objects in a given grey-scale image.
	Given an image and a threshold value, the binary threshold operation is to transform pixels in the input image from grey-scale to binary values.*/
	input_file.clear();
	input_file.seekg(0, ios::beg);
	//dummy method to skip past the information line
	for (int i = 0; i < 4; i++) {
		//get the information of the input file
		input_file >> parameters[i];
	}
	//threshold value must be converted and threshold value is specified in argv[5]
	image.thresholdOp(input_file, output_file2, threshold);
	//close input file from argv[1]
	input_file.close();
	//close output file from argv[3]
	output_file2.close();

	/*-----PART 3 ---------------------------------------------------*/
	/*Display the result of threshold image in a nice visually.  */
	ifstream input_file2;
	input_file2.open(argv[3]);
	//output_file.open(argv[4]);
	image.prettyPrint(input_file2, output_file3);
	//close input file from argv[3]
	input_file2.close();
	//close output file from argv[4]
	output_file3.close();
	output_file4.close();

}