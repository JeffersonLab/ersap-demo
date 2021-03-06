#include <image_data_type.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>

#include <gmock/gmock.h>

using namespace ersap;
using namespace ersap::demo;
using namespace testing;


auto data(const cv::Mat& img)
{
    auto size = img.total() * img.elemSize();
    return std::vector<uchar>(img.data, img.data + size);
}


TEST(SerializeImageType, Data)
{
    auto name = "lena.png";
    auto image = cv::imread(name, CV_LOAD_IMAGE_COLOR);

    auto orig = any{Image{image, name}};

    auto* serializer = IMAGE_TYPE.serializer();
    auto copy = serializer->read(serializer->write(orig));

    auto& orig_img = any_cast<Image&>(orig);
    auto& copy_img = any_cast<Image&>(copy);

    ASSERT_THAT(copy_img.name, Eq(orig_img.name));
    ASSERT_THAT(copy_img.mat.size(), Eq(orig_img.mat.size()));
    ASSERT_THAT(copy_img.mat.type(), Eq(orig_img.mat.type()));

    ASSERT_THAT(data(copy_img.mat), Eq(data(orig_img.mat)));
}


int main(int argc, char* argv[])
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
