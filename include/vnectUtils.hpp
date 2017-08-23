#ifndef VNECT_UTILS
#define VNECT_UTILS
#include "mCaffePredictor.hpp"

class mVNectUtils: public mCaffePredictor {
protected:
    virtual void preprocess(const cv::Mat & img, std::vector<cv::Mat> * input_data);
    virtual void wrapInputLayer(std::vector<cv::Mat> * input_data);
private:
    bool _is_tracking;
    std::vector<float> _scales;
    cv::Size _box_size;   
    int _crop_size;
    float _crop_scale;
    // The scale of the input and the output. Now it's 8.
    float _hm_factor; 
    std::vector<std::vector<int> > joints_2d;
    std::vector<std::vector<int> > joints_3d; 
    cv::Mat padImage(const cv::Mat &img, cv::Size box_size);
public:
    mVNectUtils(const std::string &model_path, const std::string &deploy_path, const std::string &mean_path="");
    std::vector<std::vector<int> > predict(const cv::Mat &img);
};
#endif
