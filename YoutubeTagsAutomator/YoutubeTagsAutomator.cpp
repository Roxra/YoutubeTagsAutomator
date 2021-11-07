#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "YoutubeTagsAutomator.h"

int main()
{
    std::cout << "Please enter the game name" << std::endl;
    std::string GameName;
    std::getline(std::cin, GameName);

    std::vector<std::string> TagExtensions{ "Review", "Gameplay", "Steam", "PC", "60fps", "60fps Review", "game", "Steam gameplay", "Steam 60fps," "PC gameplay", "Walkthrough", "first impressions", 
        "60fps gameplay", "steam gameplay", "lets play", "steam lets play", "lets play 60fps"};

    //todo add platform modifier
    
    std::string Outputs;

    AttachTagExtensions(TagExtensions, GameName, Outputs);
    CopyToClipboard(Outputs);

    std::cout << "All done! They have been copied to your clipboard! Just paste them into YouTube!" << std::endl;

    Sleep(5000);
    return 0;
}

void AttachTagExtensions(std::vector<std::string>& TagExtensions, std::string& GameName, std::string& Outputs)
{
    std::cout << "Generating tags!" << std::endl;

    for (std::string Extension : TagExtensions)
    {
        std::string output = GameName + " " + Extension + ",";
        Outputs += output;
        std::cout << output << std::endl;
    }
}

void CopyToClipboard(std::string& Outputs)
{
    const size_t len = strlen(Outputs.c_str()) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), Outputs.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}
