#include "engine.h"
#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <chrono>
#include <thread>
#include <stdexcept>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace eng;

engine::engine(const std::string& title, int width, int height)
    : winT(title), winH(height), winW(width), 
    acceptor(io, tcp::endpoint(tcp::v4(), 5555))
{
    std::cout << "[WARP]: warp engine has initialized: " << std::endl;
    std::cout << "title: " << this->winT << std::endl;
    std::cout << "scales (H,W): " << this->winH << ", " << this->winW << std::endl; 
    running = true;

    networkThread = std::thread(&engine::NetworkLoop, this);

}

void engine::NetworkLoop(){
    std::cout << "[WARP]: network thread is starting on port 5555... " << std::endl;
    while(running)
    {
    try{
        tcp::socket socket(io);
        acceptor.accept(socket);

        char data[1024];
        size_t len = socket.read_some(boost::asio::buffer(data));
        std::string msg(data,len);

        std::cout << "[WARP]: received msg = " << msg << std::endl;

        std::string reply = "Echo: " + msg;
        boost::asio::write(socket,boost::asio::buffer(reply));

    }catch(std::exception& e){std::cerr << "[WARP]: NETWORK ERROR: " << e.what() << std::endl;}
    }


}

engine::~engine(){
    stop();
    if(networkThread.joinable()){
        networkThread.join();
    }
    std::cout << "[WARP]: engine is shutting down..." << std::endl;


}

void engine::run(){
    std::cout << "[WARP]: main loop starting..." << std::endl;
    auto lastTime = std::chrono::steady_clock::now();

        int frame = 0;
    
        while (running){
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<float> delta = now - lastTime;
        float deltaTime = delta.count();
        lastTime = now;

        frame++;
        std::cout << frame << "\t";
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void engine::stop(){
    running = false;
    io.stop();
}

bool engine::isrunning() const {
    return running;
}


