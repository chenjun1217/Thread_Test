#include <opencv2/opencv.hpp>  // 包含OpenCV库
#include <thread>  // 包含线程库

void cameraThread() {  // 摄像头线程函数
    cv::VideoCapture cap(0);  // 打开摄像头
    if (!cap.isOpened()) {  // 如果摄像头未成功打开
        std::cerr << "Error opening camera" << std::endl;  // 输出错误信息
        return;  // 返回
    }

    cv::Mat frame;  // 定义图像帧
    while (true) {  // 循环
        cap >> frame;  // 读取摄像头帧
        if (frame.empty()) {  // 如果帧为空
            std::cerr << "End of camera feed" << std::endl;  // 输出结束信息
            break;  // 退出循环
        }
        cv::imshow("Camera Feed", frame);  // 显示摄像头帧
        if (cv::waitKey(1) == 27) break; // ESC键退出
    }
}

void videoThread() {  // 视频线程函数
    cv::VideoCapture cap("/home/cj/chaintwork/pcl/code_c++/Thread_Test/sample.mp4");  // 打开视频文件
    if (!cap.isOpened()) {  // 如果视频文件未成功打开
        std::cerr << "Error opening video file" << std::endl;  // 输出错误信息
        return;  // 返回
    }

    cv::Mat frame;  // 定义图像帧
    while (true) {  // 循环
        cap >> frame;  // 读取视频帧
        if (frame.empty()) {  // 如果帧为空
            std::cerr << "End of video" << std::endl;  // 输出结束信息
            break;  // 退出循环
        }
        cv::imshow("Video Feed", frame);  // 显示视频帧
        if (cv::waitKey(1) == 27) break; // ESC键退出
    }
}

int main() {  // 主函数
    std::thread camera(cameraThread);  // 创建摄像头线程
    std::thread video(videoThread);  // 创建视频线程

    camera.join();  // 等待摄像头线程结束
    video.join();  // 等待视频线程结束

    return 0;  // 返回
}
