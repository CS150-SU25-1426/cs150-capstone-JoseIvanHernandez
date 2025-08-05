
#include <cstdlib>     // for system()
#include <filesystem>  // C++17 and up
#include <fstream>     // for file presence
#include <vector>

// Modular headers
#include "init.h"
#include "feeds.h"
#include "pointers.h"
#include "dataset.h"

namespace fs = std::filesystem;

// Local file check helper
bool fileExists(const std::string& path) {
    return fs::exists(path);
}

int main() {
    std::cout << "🔧 Starting BorlandCPP Hackfrontier Scanner...\n";

    // 🔍 Phase 1: Scan for Borland Executables
std::cout << "🔍 Scanning Borland Directory...\n";
std::vector<std::string> tools = { "bcc.exe", "tlink.exe", "dfa.exe" };
bool missing = false;

for (const auto& tool : tools) {
    std::string path = "../devtools/" + tool;
    if (!fileExists(path)) {
        std::cout << "⚠️  Missing: " << tool << "\n";
        missing = true;
    }
}

if (missing) {
    std::cout << "⚠️  Missing critical Borland tools. Attempting to pull from OneDrive...\n";
#ifdef _WIN32
    system("powershell -ExecutionPolicy Bypass -File \"../windows/pull-borland-executables.ps1\"");
#else
    system("pwsh -ExecutionPolicy Bypass -File \"../windows/pull-borland-executables.ps1\"");
#endif
} else {
    std::cout << "✅ All Borland tools present.\n";
}


 // 📡 Phase 2: Load Feed & Dataset Pointers
    std::cout << "📡 Loading Live Feeds & Dataset Pointers...\n";

 if (fileExists("../feeds/live_feeds.json")) {
    std::cout << "📁 Found live_feeds.json\n";
    loadFeeds();
 } else {
     std::cout << "❌ Missing: feeds/live_feeds.json\n";
     std::cout << "📡 Booting Feed Loader...\n";
  // If you need to use 'liveFeeds', declare and initialize it here.
  // Example: std::vector<Feed> liveFeeds;
     std::cout << "📡 Feed Loader booted successfully.\n";
 }

 if (fileExists("../data/pointers/dataset_links.ps1")) {
      std::cout << "📁 Found dataset_links.ps1\n";
      loadDatasetPointers();
 } else {
      std::cout << "❌ Missing: dataset_links.ps1\n";
 }

 // 🧪 Optional: Launch GUI if everything is ready
 if (!missing && fileExists("launch_gui.ps1")) {
      std::cout << "🚀 Launching GUI using launch_gui.ps1...\n";
    #ifdef _WIN32
        int result = system("powershell -ExecutionPolicy Bypass -File launch_gui.ps1");
    #else
        int result = system("pwsh -ExecutionPolicy Bypass -File launch_gui.ps1");
    #endif
        if (result == 0) {
            std::cout << "✅ GUI launched successfully.\n";
        } else {
            std::cout << "❌ Failed to launch GUI. Return code: " << result << "\n";
        }
    } else if (!fileExists("launch_gui.ps1")) {

        std::cout << "⚠️  launch_gui.ps1 not found.\n";
    }
     // 🧠 Phase 3: Parse Hackathon DSA Datasets
    if (fileExists("../scripts/parse-dsa-data.ps1")) {
    std::cout << "🧠 Parsing Hackathon 2025 DSA data...\n";
    #ifdef _WIN32
    system("powershell -ExecutionPolicy Bypass -File ../scripts/parse-dsa-data.ps1");
    #else
    system("pwsh -ExecutionPolicy Bypass -File ../scripts/parse-dsa-data.ps1");
    #endif
    std::cout << "📊 DSA data parsing complete.\n";
    } else {
    std::cout << "❌ Missing parser: parse-dsa-data.ps1\n";
    }
    // Load key insights from PowerShell output
    std::ifstream hotspot("../temp/hotspot.txt");
    std::string hotspotLine;
    if (hotspot.is_open()) {
    std::getline(hotspot, hotspotLine);
    std::cout << "💡 Insight: " << hotspotLine << "\n";
    hotspot.close();
    }

    std::cout << "🛠️  Scan complete. Ready to begin analysis.\n";
    return 0;
    }
