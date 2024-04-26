
#include "sha1.h" // Подключаем правильный файл заголовка для sha1
#include <string>


Chat::Chat() {}

Chat::~Chat() {}

void Chat::reg(const std::string& login, const std::string& pass) {
    uint* pass_hash = sha1((char*)pass.c_str(), pass.length());
    table.add(login, pass_hash); // Проблема здесь
}

bool Chat::login(const std::string& login, const std::string& pass) {
    uint* stored_pass_hash = table.find(login); // Проблема здесь

    if (stored_pass_hash != nullptr) {
        uint* input_pass_hash = sha1((char*)pass.c_str(), pass.length());
        for (int i = 0; i < SHA1HASHLENGTHUINTS; ++i) {
            if (stored_pass_hash[i] != input_pass_hash[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
