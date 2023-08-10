#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>
using namespace std;
using namespace cv;
int track_process() {
    // declares all required variables
    Rect roi;
    Mat frame;
    frame = imread("./auto/0.jpg");
    // create a tracker object
    Ptr<Tracker> tracker = TrackerCSRT::create();
    // get bounding box
    roi = selectROI("tracker", frame);
    //quit if ROI was not selected
    if (roi.width == 0 || roi.height == 0)
        return 0;
    // initialize the tracker
    tracker->init(frame, roi);
    // perform the tracking process
    printf("Start the tracking process, press ESC to quit.\n");
    for (int i = 1; i < 13; i++)
    {
        frame = imread("./auto/"+to_string(i)+".jpg");
        // stop the program if no more images
        if (frame.rows == 0 || frame.cols == 0)
            break;
        // update the tracking result
        tracker->update(frame, roi);
        // draw the tracked object
        rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);
        // show image with the tracked object
        imshow("tracker", frame);
        //quit on ESC button
        if (waitKey(1) == 27)break;
        waitKey(500);
    }
    return 0;
}
