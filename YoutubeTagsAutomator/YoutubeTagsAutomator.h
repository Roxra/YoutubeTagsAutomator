#pragma once

void AttachTagExtensions();
void CopyToClipboard();
void AddToTagList(std::string& output);

std::string PlatformName;
std::string GameName;
std::string Outputs;

std::vector<std::string> TagExtensions{ "Review", "Gameplay", "60fps", "60fps Review", "game", "Walkthrough", "first impressions",
    "60fps gameplay", "lets play", "lets play 60fps" };
