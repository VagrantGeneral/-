#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void speak(const std::string& text)
{
    std::ofstream file("voice.vbs");
    if (file.is_open()) {
        file << "CreateObject(\"SAPI.SpVoice\").Speak(\"" << text << "\")";
        file.close();
        system("voice.vbs");
    }
    else {
        std::cout << "无法打开文件 voice.vbs" << std::endl;
    }
}