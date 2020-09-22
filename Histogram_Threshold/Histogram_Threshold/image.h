#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class image
{
	private:
		int numRows;
		int numCols;
		int minVal;
		int maxVal;
		int* histogramArray;
		long thresholdValue;


		//constructor
	public:
		image(int rows, int cols, int min, int max, long threshold);
		void prettyPrint(ifstream& input_file, ofstream& output_file); 
		void thresholdOp(ifstream& input_file, ofstream& output_file, long threshold);
		void printHist(ofstream& output_file, int* histogram);
		void printHistParan(ofstream& output_file, int* histogram);
		void computeHist(ifstream& input_file, ofstream& output_file, ofstream& output_file2);
};

#endif