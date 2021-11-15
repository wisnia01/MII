
#include <stdio.h>
using namespace std;

#include <iostream>

// OpenCV includes
#include <opencv2/opencv.hpp>
using namespace cv;

Mat grayImage;

int threshold_value = 100;
#define max_value 255
#define histSize 256
#define hist_w 256
#define hist_h 256

Mat binarizedImage;

void Threshold(int pos, void* userdata)
{
	threshold(grayImage, binarizedImage, threshold_value, max_value, THRESH_BINARY);
	imshow("Binaryzation", binarizedImage);
}

int main()
{
	// reading source file srcImage
	Mat srcImage;


	srcImage = imread( "Samples/ryba.jpg" );
	if ( !srcImage.data )
	{
		cout << "Error! Cannot read source file. Press ENTER.";
		waitKey();
		return( -1 );
	}
	namedWindow("Jakub Wasniewski"); 
	moveWindow("Jakub Wasniewski",0, 0); //stworzenie okna

	cvtColor(srcImage, grayImage,  COLOR_BGR2GRAY);
	namedWindow("Gray image");
	moveWindow("Gray image", 300, 0); //stworzenie okna
	imwrite("Samples/Gray_image.jpg", grayImage);

	Mat resizedImage(100, 100, srcImage.type());
	namedWindow("Resized image");
	moveWindow("Resized image", 600, 0); //stworzenie okna
	resize(srcImage, resizedImage, resizedImage.size());

	Mat blurImage;
	blur(srcImage, blurImage, Size(5,5));
	namedWindow("Blurred image");
	moveWindow("Blurred image", 900, 0); //stworzenie okna

	Mat CannyImage;
	Canny(srcImage, CannyImage, 80, 80);
	namedWindow("Canny image");
	moveWindow("Canny image", 1200, 0); //stworzenie okna

	Mat LaplacianImage;
	Laplacian(grayImage, LaplacianImage, CV_16S, 3);

	Mat scaledLaplacianImage;
	convertScaleAbs(LaplacianImage, scaledLaplacianImage); //nie wiem co to robi
	namedWindow("Laplacian image");
	moveWindow("Laplacian image", 300, 300); //stworzenie okna

	//KONIEC CHAPTERU 1
	//essa
	Mat brightImage;
	srcImage.copyTo(brightImage);
	for (int i = 0; i < brightImage.cols; i++)
	{
		for (int j = 0; j < brightImage.rows; j++)
		{
			Vec3b pixelColor;
			pixelColor = brightImage.at<Vec3b>(Point(j,i));
			for (int k = 0; k < 3; k++)
			{

				if (pixelColor[k] > 155)
					pixelColor[k] = 255;
				else
					pixelColor[k] += 100;

			}
			brightImage.at<Vec3b>(Point(j, i)) = pixelColor;
		}
	}
	namedWindow("Bright image");
	moveWindow("Bright image", 600, 300); //stworzenie okna

	//CHAPTER 2 
	//essa essa

	//metoda zrobiona
	namedWindow("Binaryzation");
	moveWindow("Binaryzation", 900, 300); //stworzenie okna
	createTrackbar("uga uga", "Binaryzation", &threshold_value, max_value, Threshold);


	//LVL 3 COMPLETE
 	//aiouwdgvjahkuywfdguyaikwfikay essa




	imshow("Resized image", resizedImage);
	imshow("Bright image", brightImage);
	imshow("Laplacian image", scaledLaplacianImage);
	imshow("Canny image", CannyImage);
	imshow("Blurred image", blurImage);
	imshow("Gray image", grayImage);
	imshow("Jakub Wasniewski", srcImage);
	waitKey();

	namedWindow("Src video");
	namedWindow("Dst video");
	moveWindow("Src video", 300, 600); //stworzenie okna
	moveWindow("Dst video", 600, 600); //stworzenie okna

	Mat srcFrame;
	Mat dstFrame;
	VideoCapture capture("Samples/Dino.avi");
	capture >> srcFrame;
	VideoWriter writer("Samples/Dino2.avi", -1, 25, srcFrame.size());

	while (!srcFrame.empty() && waitKey(4) != 27)
	{

		blur(srcFrame, dstFrame, Size(5, 5));
		imshow("Src video", srcFrame);
		imshow("Dst video", dstFrame);
		capture >> srcFrame;
	}
	//CZESC 4  SKONCZONA
	float range[2] = { 0, 256 };
	const float* histRange;


	

}
