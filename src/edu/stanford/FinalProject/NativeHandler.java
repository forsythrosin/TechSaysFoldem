package edu.stanford.FinalProject;

import org.opencv.core.Mat;

public class NativeHandler {

	public static Mat Filter(Mat imgIn)
	{
		Mat ret = imgIn.clone();
		Filter(ret.getNativeObjAddr(), imgIn.getNativeObjAddr());
		return ret;
	}
	
	private static native void Filter(long ret, long image);
}
