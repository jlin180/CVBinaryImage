# Histogram Threshold

## Description

This project focuses on using Histogram Threshold technique to clean the noise from a gray-scale image. 
It first computes a histogram of a image, where the histogram of an image is the statistic count of the pixel values in the input image. Then, it performs a binary threshold operation that extracts the foreground objects in a given image. It outputs a binary image.

Note: image header is always on the first line of the .txt file.

## Inputs (command line arguments)
~~~
argv[1] :  inputImage.txt
~~~
Input gray-scale image in form of .txt file that contains a header.

Example Input file:
> ![image](https://user-images.githubusercontent.com/35271372/93838752-cf180180-fc58-11ea-80bd-a2d71cc722ed.png)

~~~
argv[2] : outputFile1.txt 
~~~
Name of the first output file. Always add .txt after the end of the name.
This output file will contain the image header and a list of pairs.
The left side of the pair represents the pixel value, the right side of the pair represents the count of that pixel value within the input image.

Example output file (after computing):
> ![image](https://user-images.githubusercontent.com/35271372/93839198-35e9ea80-fc5a-11ea-9d09-735b2319e002.png)
~~~
argv[3] : outputFile2.txt 
~~~
Name of the second output file. Always add .txt after the end of the name.
This output file will contain the image header and the binary image of the object after it is extracted from the grey-scale image using binary threshold operation.

Example output file (after binary threshold):
>![image](https://user-images.githubusercontent.com/35271372/93839344-aabd2480-fc5a-11ea-9759-e32c433bdf93.png)

~~~
argv[4] : outputFile3.txt 
~~~
Name of the third output file. Always add .txt after the end of the name.
This output file will contain beautified image of the extracted object from the grey-scale image represented by `1`.

Example output file (prettified):
> ![image](https://user-images.githubusercontent.com/35271372/93839401-da6c2c80-fc5a-11ea-94f2-6bfacfd3c208.png)

~~~
argv[5] : outputFile4.txt 
~~~
Name of the fourth output file. Always add .txt after the end of the name.
This output file will contain the image header and the visualization of the histogram in the following format :
` pixel-value (count of the pixel-value): representation of the count using '+'.`

Example output file (visualization):
> ![image](https://user-images.githubusercontent.com/35271372/93839524-2fa83e00-fc5b-11ea-8051-6cb7b42e6a76.png)
~~~
argv[6] : threshold value
~~~
Threshold value is an int.
Example threshold:
> 6

## Algorithm Design
```
Step 0: Open input_file1 (argv[1]), output_file1 (argv[2]), output_file2 (argv[3]), output_file3 (argv[4]), output_file4 (argv[5]) and take threshold value from argv[6]
Step 1: Take in the image information of input_file:
          numRows 
          numCols 
          minVal 
          maxVal
Step 2: Make histogram array
	      histogramArray = new int[maxVal+1]
Step 3: Compute histogram by scanning image pixel by pixel from left to right, top to bottom.
        If we come across a pixel, we increase the count by 1 each time we come across it. ( histogramArray[pixel]++ )
Step 4: Print histogram pairs in output_file1
Step 5: Print histogram in output_file4 and close output_file4
Step 6: Scanning image pixel by pixel from left to right, top to bottom in input_file2 again and 	compare if the values are greater than or equal to threshold value
        if (image[rows * numCols + cols] >= threshold)
          output_file2  -> print 1
        else
          output_file2  -> print 0 
Step 7: Close output_file2, input_file1
Step 8: Read in output_file2 (as input_file2)
Step 9: Scanning image pixel by pixel from left to right, top to bottom in output_file3 
        if (image[rows * numCols + cols] > 0) 
          output_file3 -> print 1
        else 
          output_file3 -> print “ “ (1 space)
Step 10: close output_file3,input_file2
 
```

