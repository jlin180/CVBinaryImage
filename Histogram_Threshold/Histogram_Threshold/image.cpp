#include "image.h"

	image::image(int rows, int cols, int min, int max, long threshold) {
		numRows = rows;
		numCols = cols;
		minVal = min;
		maxVal = max;
		histogramArray = new int[maxVal + 1];
		thresholdValue = threshold;
	}
	void image::prettyPrint(ifstream& input_file, ofstream& output_file) {
		//place to store information of the file
		//parameters[0] = rows
		//parameters[1] = cols
		//parameters[2] = min
		//parameters[3] = max
		int parameters[4];
		for (int i = 0; i < 4; i++) {
			input_file >> parameters[i];
		}
		//make 2d image array
		int* image = new int[numRows * numCols];

		//iterate through the image in inputfile element by element
		//add these elements into the array
		for (int rows = 0; rows < numRows; rows++) {
			for (int cols = 0; cols < numCols; cols++) {
				input_file >> image[rows * numCols + cols];
			}
		}

		//print output in output file
		for (int rows = 0; rows < numRows; rows++) {
			string line;
			for (int cols = 0; cols < numCols; cols++) {
				//compare if the value is greater than 0, if it is, print 1 else print " "
				if (image[rows * numCols + cols] > 0) {
					line += '1';
				}
				else {
					line += ' ';
				}
				line += ' ';
			}
			output_file << endl << line;
		}
		delete[] image;
	}

	void image::thresholdOp(ifstream& input_file, ofstream& output_file, long threshold) {

		//put information of the image in first line of output file
		output_file << numRows << ' ' << numCols << " 0 1 ";

		//make 2d array of image
		int* image = new int[numRows * numCols];
		//initialization of image array
		for (int i = 0; i < numRows * numCols; i++) {
			image[i] = 0;
		}

		//iterate through the image in the input file element by element and put it into the 2d image array
		for (int rows = 0; rows < numRows; rows++) {
			for (int cols = 0; cols < numCols; cols++) {
				input_file >> image[rows * numCols + cols];
			}
		}
		//iterate through the image array and print output in output file
		for (int rows = 0; rows < numRows; rows++) {
			string line1;
			for (int cols = 0; cols < numCols; cols++) {
				//compare it to threshold value, if element in image is greater than or equal to threshold, print 1 else, print 0
				if (image[rows * numCols + cols] >= threshold) {
					line1 += '1';
				}
				else {
					line1 += '0';
				}
				line1 += ' ';
			}
			output_file << endl << line1;
		}
		delete[] image;
	}

	void image::printHist(ofstream& output_file, int* histogram) {
		//display it in file like:
		//greyScale (numpixels): number of +’s
		for (int i = 0; i <= maxVal; i++) {
			string line;
			line += to_string(i);
			//line += " (" + to_string(histogram[i]) + "):";
			line += " " + to_string(histogram[i]);
			for (int frequency = 0; frequency < histogram[i]; frequency++) {
				if (frequency >= 60) {
					break;
				}
				else {
					//	line += '+';
				}
			}
			output_file << endl << line;
		}
	}
	void image::printHistParan(ofstream& output_file, int* histogram) {
		//display it in file like:
		//greyScale (numpixels): number of +’s
		for (int i = 0; i <= maxVal; i++) {
			string line;
			line += to_string(i);
			line += " (" + to_string(histogram[i]) + "):";
			//line += " " + to_string(histogram[i]);
			for (int frequency = 0; frequency < histogram[i]; frequency++) {
				if (frequency >= 60) {
					break;
				}
				else {
					line += '+';
				}
			}
			output_file << endl << line;
		}
	}

	void image::computeHist(ifstream& input_file, ofstream& output_file, ofstream& output_file2) {
		//put the information in the output file
		output_file << numRows << " " << numCols << " " << minVal << " " << maxVal;
		output_file2 << numRows << " " << numCols << " " << minVal << " " << maxVal;


		for (int i = 0; i <= maxVal; i++) {
			//initialize values in histogram to be zero;
			histogramArray[i] = 0;
		}
		//go through the image and count the # of times a pixel shows up and then put it in the histogram
		for (int rows = 0; rows < numRows; rows++) {
			cout << endl;
			for (int cols = 0; cols < numCols; cols++) {
				int pixel;
				input_file >> pixel;
				cout << pixel << ' ';
				histogramArray[pixel] ++;
			}
		}
		//print histogram in output file
		printHist(output_file, histogramArray);
		printHistParan(output_file2, histogramArray);
		delete[] histogramArray;

	}