#include "inference.h"

int main() {
    // Create an Inference object
    Inference inference("./ratmodel1.onnx", cv::Size(640, 640), "", true);

    // Load an input image
    cv::Mat inputImage = cv::imread("./photo5.jpg");
    if (inputImage.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // Run inference
    std::vector<Detection> detections = inference.runInference(inputImage);

    // Check if detections are being made
    if (detections.empty()) {
        std::cout << "No detections were made." << std::endl;
    }
    else {
        std::cout << "Detections were made: " << detections.size() << std::endl;
    }

    // Process the detections
    for (const auto& detection : detections) {
        std::cout << "Confidence: " << detection.confidence << std::endl;
        cv::rectangle(inputImage, detection.box, detection.color, 2);
    }

    // Save or display the image with detections
    //cv::imwrite("output.jpg", inputImage);
    cv::imshow("Detections", inputImage);
    cv::waitKey(0);

    return 0;
}
