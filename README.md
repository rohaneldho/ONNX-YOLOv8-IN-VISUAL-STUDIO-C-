# YOLOv8 ONNX Integration with Visual Studio C++ - README

## Overview

This project demonstrates how to integrate a YOLOv8 model, converted to ONNX format, into a Visual Studio C++ application. The application performs object detection on images using the ONNX model.

## Prerequisites

1. **Visual Studio**: Ensure you have Visual Studio installed with C++ development environment.
2. **OPENCV C++ in VS**: Install OPENCV for C++
3. **Python (for model export)**: Ensure you have Python installed to convert the YOLOv8 model to ONNX.

## Steps to Set Up

### 1. Convert YOLOv8 Model to ONNX

First, you need to convert your YOLOv8 model to ONNX format. Use the following Python code snippet:

```python
# Assuming you have the YOLOv8 model loaded as `model`
model.export(format="onnx")
```

This will generate a `.onnx` file for your model. Place this file in the project directory or provide the appropriate path in the `main.cpp` file.

### 2. Set Up Visual Studio Project

1. **Create a New Project**: Open Visual Studio and create a new C++ Console Application project.
2. **Add OPENCV Library**: 
   - Download the OPENCV library from the official website.
   - Make sure you are using MSVC Compiler
   - Include the OPENCV headers and libraries in your project settings.

### 3. Project Directory Structure

Ensure your project directory looks like this:

```
YourProject/
├── models/
│   └── yolov8.onnx
├── images/
│   └── input_image.jpg
├── src/
│   ├── main.cpp
│   └── inference.h
|   |__inference.cpp
|
└── YourProject.sln
```

- **models/**: Contains the YOLOv8 ONNX model.
- **images/**: Contains input images for inference.
- **src/**: Contains the main application source code and inference utility header.

### 4. Modify `main.cpp`

Ensure your `main.cpp` file has the correct paths to the ONNX model and input images:

```cpp
#include "inference_utils.h"

int main() {
    const std::string model_path = "models/yolov8.onnx";
    const std::string image_path = "images/input_image.jpg";

    // Perform inference
    perform_inference(model_path, image_path);

    return 0;
}
```

### 5. Build and Run the Project

1. **Build**: Compile your project in Visual Studio.
2. **Run**: Execute the application. It should load the ONNX model and perform object detection on the input image.

## Notes

- Ensure all dependencies are correctly linked and included.
- Modify `inference.h` and related files only if necessary to adapt to your specific needs.

## Troubleshooting

- **Model Path Issues**: Double-check the model and image paths in `main.cpp`.
- **OPENCV Errors**: Ensure OPENCV is properly installed and configured and also MAKE SURE TO USE MSVC NOT MINGW

## Contributing

Feel free to fork this repository and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.


---

Enjoy building your object detection application with YOLOv8 and ONNX in C++! If you encounter any issues, please refer to the OPENCV documentation and Visual Studio C++ documentation for additional support.
