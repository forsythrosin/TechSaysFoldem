#include <jni.h>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C" JNIEXPORT void JNICALL Java_edu_stanford_FinalProject_NativeHandler_Filter
  (JNIEnv * env, jclass thiz, jlong retLong, jlong imageLong) {
	Mat ret = *((Mat*)retLong);
	Mat im = *((Mat*)imageLong);
	Mat imGr;
	cvtColor(im,imGr,CV_RGB2GRAY);
	Mat imOtsu;
	threshold(imGr, imOtsu, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	vector<KeyPoint> keypoints;
	ORB orbDetector(500);
	orbDetector(imGr, Mat(), keypoints, cv::noArray(), false);
	for(unsigned int i = 0; i < keypoints.size(); ++i)
	{
	    const KeyPoint& kp = keypoints[i];
	    circle(ret, Point(kp.pt.x, kp.pt.y), 10, Scalar(0,255,0,255), 1);
	}
}

void getBlobs(Mat ret, Mat bwIm)
{
	ret = Mat::zeros(bwIm.size().height, bwIm.size().width, CV_16S); //stores ints
	vector<int> baseBlobs;
	//TreeMap<int, vector<int>> labelCorrespondance;
	int i, j;
	for(i =1; i < bwIm.size().width; ++i) {
		for(j=1; j < bwIm.size().height; ++j) {
			if(bwIm.at<unsigned char>(j,i) == 255)
			{
				if(i > 1 && j > 1 && bwIm.at<unsigned char>(j-1,i) == 255 && bwIm.at<unsigned char>(j,i-1) == 255)
				{
					//ret(i,j) = 1;
				}
			}
		}
	}
}
