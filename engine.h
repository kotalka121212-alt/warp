#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>


namespace eng{
class engine{
public:
engine(const std::string& title, int width, int height);
~engine();

void run();
void stop();
bool isrunning() const;

private:
bool running = false;
std::string winT;
int winW, winH;

};


};




