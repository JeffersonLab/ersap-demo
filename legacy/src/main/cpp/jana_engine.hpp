#ifndef ERSAP_DEMO_LEGACY_PUPIL_DETECTOR_HPP_
#define ERSAP_DEMO_LEGACY_PUPIL_DETECTOR_HPP_

#include <string>

//namespace cv {
//
//class Mat;
//
//} // end namespace cv


namespace ersap {
namespace demo {

/**
 * Writes a circle around detected pupils in a given image.
 */
class JanaEngine
{
public:
//    /**
//     * Runs the detector on the given image.
//     *
//     * @param img the input image
//     */
//    void run(cv::Mat& img);
    void process();
};

} // end namespace demo
} // end namespace ersap

#endif
