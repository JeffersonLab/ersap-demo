#ifndef ERSAP_DEMO_LEGACY_IMAGE_HPP_
#define ERSAP_DEMO_LEGACY_IMAGE_HPP_

#include <opencv2/core/mat.hpp>

#include <string>

namespace ersap {
namespace demo {

struct Image
{
    cv::Mat mat;
    std::string name;
};

} // end namespace demo
} // end namespace ersap

#endif
