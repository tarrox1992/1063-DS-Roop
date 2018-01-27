#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb {
	int r;
	int g;
	int b;
	rgb() {
		int r = 0;
		int g = 0;
		int b = 0;
	}
};

/**
* @FunctionName: flipVert
* @Description:
*     Loops through a 2D array and flips an rgb array vertically
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image, int width, int height)
{
	rgb flip;
	for (int i = 0; i < height / 2; i++)
	{
		for (int j = 0; j < width; j++)
		{
			flip = image[i][j];
			image[i][j] = image[height - 1 - i][j];
			image[height - 1 - i][j] = flip;
		}
	}
}

/**
* @FunctionName: flipHorz
* @Description:
*     Loops through a 2D array and flips an rgb array horizontally
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image, int width, int height) {
	rgb flip;
	for (int j = 0; j < width / 2; j++)
	{
		for (int i = 0; i < height; i++)
		{
			flip = image[i][j];
			image[i][j] = image[i][width - 1 - j];
			image[i][width - 1 - j] = flip;
		}
	}
}

/**
* @FunctionName: grayScale
* @Description:
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image, int width, int height) {
	int gray, large, small; // declares variables to hold the gray color, and find
	                        // largest and smallest rgb value for each pixel
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			large = image[i][j].r;
			small = image[i][j].r;
			if (image[i][j].g > large) // finds largest color value for specified pixel
				large = image[i][j].g;
			else if (image[i][j].b > large)
				large = image[i][j].b;
			if (image[i][j].g < small) // finds smallest color value for specified pixel
				small = image[i][j].g;
			else if (image[i][j].b > small)
				small = image[i][j].b;
			gray = (small + large) / 2; // averages largest and smallest value to find gray for pixel
			image[i][j].r = gray; // assigns each color value with the gray value
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}

/**
* @FunctionName: readImage
* @Description:
*     Reads rgb values from a file into an array
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    ifstream ifile - input file
* @Returns:
*    void
*/
void readImage(rgb** image, int &width, int &height, ifstream &ifile)
{
	//Read the color data in from our txt file
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ifile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
		}
	}

}

/**
* @FunctionName: saveImage
* @Description:
*     Saves an array of rgb values to a file
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    ofstream ofile - output file
* @Returns:
*    void
*/
void saveImage(rgb** image, int width, int height, ofstream &ofile)
{
	//Write out our color data to a new file
	ofile << width << " " << height << '\n';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
		}
		ofile << '\n';
	}
}

/**
* @ProgramName: Program-1
* @Author: Tyler Roop
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
*     It then flips an image horizontally, vertically, and turns it grayscale.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 27 01 2018
*/

int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("bot.txt");
	ofile.open("bot2.txt");

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i < height; i++) {
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	readImage(imgArray, width, height, ifile);

	flipVert(imgArray, width, height); // Sends array to function to flip vertically
	flipHorz(imgArray, width, height); // Sends array to function to flip horizontally
	grayScale(imgArray, width, height); // Sends array to function to turn grayscale

	saveImage(imgArray, width, height, ofile);

	ifile.close();
	ofile.close();
	return 0;
}
