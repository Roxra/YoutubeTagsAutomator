#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "YoutubeTagsAutomator.h"

int main()
{
    std::cout << "Please enter the game name" << std::endl;
    std::getline(std::cin, GameName);

    std::cout << "Please enter the platform name (Steam,PS5,Switch etc)" << std::endl;
    std::getline(std::cin, PlatformName);

    AttachTagExtensions();
    CopyToClipboard();

    std::cout << "All done! They have been copied to your clipboard! Just paste them into YouTube!" << std::endl;

    Sleep(5000);
    return 0;
}

void AttachTagExtensions()
{
    std::cout << "Generating tags!" << std::endl;

    for (std::string Extension : TagExtensions)
    {
        std::string output = GameName + " " + Extension + ",";
        AddToTagList(output);
    }

    if (!PlatformName.empty())
    {
        std::string output = GameName + " " + PlatformName + ",";
        AddToTagList(output); //adds just game and platform tag (eg "Steam")

        for (std::string Extension : TagExtensions)
        {
            std::string output = GameName + " " + PlatformName + " " + Extension;
            if (Extension != TagExtensions.back())
            {
                output = output + ",";
            }  
            AddToTagList(output);
        }
    }

}

void AddToTagList(std::string& output)
{
    TotalSize += output.length();
    if (TotalSize <= 500)
    {
        Outputs += output;
        std::cout << output << std::endl;
    }
}

void CopyToClipboard()
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