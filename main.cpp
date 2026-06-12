#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <cstdint>
#include "engine.h"

#include <boost/asio.hpp>

#include <functional>

using namespace std;


int add(int a, int b){
    return a+b;
}


int main() {

    int i = 3;

    auto burmalda = [&i](int stepen){
        int zero = 1;
        int a = i;
        while(stepen != zero){
            i = i * a;
            zero++;
        }
    };

    burmalda(4);
    cout << i << endl;


    // eng::engine w("burmalda",1,1);
    // w.run();


    std::function <int(int,int)> baran;
    baran = add;
    int b = baran(5,0);
    cout << b;





    return 0;
}


// // В твоём будущем Warp
// void onMessage(std::function<void(const std::string&)> callback) {
//     // Получили сообщение — вызвали колбэк
//     callback("ping");
// }

// int main() {
//     // Лямбда прямо в аргументе
//     onMessage([](const std::string& msg) {
//         std::cout << "Получено: " << msg << std::endl;
//     });
//     return 0;
// }



// #include <iostream>
// #include <map>
// #include <functional>
// #include <string>
// #include <vector>

// class Commander {
// private:
//     // Хранилище команд: имя → функция
//     std::map<std::string, std::function<void(const std::vector<std::string>&)>> commands;

// public:
//     // Регистрация команды
//     void add(const std::string& name, std::function<void(const std::vector<std::string>&)> action) {
//         commands[name] = action;
//     }

//     // Выполнение команды
//     void execute(const std::string& name, const std::vector<std::string>& args) {
//         if (commands.find(name) != commands.end()) {
//             commands[name](args);  // Вызвали функцию
//         } else {
//             std::cout << "Неизвестная команда: " << name << std::endl;
//         }
//     }
// };


// int main() {
//     Commander cmd;

//     // Регистрируем команды
//     cmd.add("say", [](const std::vector<std::string>& args) {
//         std::cout << "Вы сказали: ";
//         for (auto& word : args) std::cout << word << " ";
//         std::cout << std::endl;
//     });

//     cmd.add("ping", [](const std::vector<std::string>& args) {
//         std::cout << "pong" << std::endl;
//     });

//     cmd.add("pidor", [](const std::vector<std::string>& args) {
//         std::cout << "Сам такой" << std::endl;
//     });

//     // Вызываем команды
//     cmd.execute("ping", {});                        // pong
//     cmd.execute("say", {"привет", "мир"});          // Вы сказали: привет мир
//     cmd.execute("pidor", {});                       // Сам такой
//     cmd.execute("unknown", {});                     // Неизвестная команда: unknown

//     return 0;
// }








