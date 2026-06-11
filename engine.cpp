#include "engine.h"
#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>
using namespace eng;

engine::engine(const std::string& title, int width, int height)
    : winT(title), winH(height), winW(width)
{
    std::cout << "[WARP]: warp engine has initialized: " << std::endl;
    std::cout << "title: " << this->winT << std::endl;
    std::cout << "scales (H,W): " << this->winH << ", " << this->winW << std::endl; 
    running = true;
}

engine::~engine(){
    std::cout << "[WARP]: engine is shutting down..." << std::endl;
}

void engine::run(){
    std::cout << "[WARP]: main loop starting..." << std::endl;

    auto lastTime = std::chrono::steady_clock::now();

    while (running){
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<float> delta = now - lastTime;
        float deltaTime = delta.count();
        lastTime = now;

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void engine::stop(){
    running = false;
}

bool engine::isrunning() const {
    return running;
}


