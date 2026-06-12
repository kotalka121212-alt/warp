#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;


namespace eng{
class engine{
public:
engine(const std::string& title, int width, int height);
~engine();

void run();
void stop();
bool isrunning() const;

private:
boost::asio::io_context io;
tcp::acceptor acceptor;

bool running = false;
std::string winT;
int winW, winH;

void NetworkLoop();
std::thread networkThread;

};


};




