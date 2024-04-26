#pragma once

#include "hash_table.h"
#include <string>

class Chat {
public:
    Chat();
    ~Chat(); // ��������� ����������
    void reg(const std::string& login, const std::string& pass);
    bool login(const std::string& login, const std::string& pass);

private:
    HashTable table; // ������� ��������� ������ HashTable
};
