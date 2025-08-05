// dfa_gui.cpp
#include <cstdlib>   // for system()
#include <iostream>  // for output

int main() {
    std::cout << "🚀 Launching Borland Tool GUI via PowerShell...\n";

#ifdef _WIN32
    int result = system("powershell -ExecutionPolicy Bypass -File scripts\\launch_gui.ps1");
#else
    int result = system("pwsh -File scripts/launch_gui.ps1");
#endif

    if (result == 0) {
        std::cout << "✅ GUI launched successfully.\n";
    } else {
        std::cerr << "❌ Failed to launch GUI. Return code: " << result << "\n";
        std::cerr << "💡 Tip: On Linux, try installing PowerShell Core with: sudo apt install powershell\n";
    }

    return result;
}
