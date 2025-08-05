# launch_gui.ps1 - Simple Borland-style GUI mockup using local HTML
$dashboard = @"
<!DOCTYPE html>
<html>
<head>
  <title>Hackfrontier Scanner</title>
  <style>
    body { background-color: #111; color: #0f0; font-family: 'Courier New'; padding: 20px; }
    .box { border: 2px solid #0f0; padding: 20px; margin: 10px; }
    h1 { color: #0ff; }
  </style>
</head>
<body>
  <h1>🚀 Hackfrontier Retro Dashboard</h1>
  <div class='box'>✅ Tools Verified: bcc.exe, tlink.exe, dfa.exe</div>
  <div class='box'>📡 Live Feeds Loaded: OK</div>
  <div class='box'>🧠 Next Step: Data Scan Ready</div>
</body>
</html>
"@

$tempPath = "$env:TEMP\hackfrontier_gui.html"
$dashboard | Set-Content -Path $tempPath
Start-Process $tempPath

# After scanning tools and loading feeds...

# 📊 Dataset Status
$statusFile = "../feeds/dataset_status.json"
if (Test-Path $statusFile) {
    $statuses = Get-Content $statusFile | ConvertFrom-Json
    "<div class='card'><h2>📊 Dataset Scan</h2>" | Out-File $outputHtml -Append

    foreach ($ds in $statuses) {
        " <p>📁 $($ds.name): $($ds.status)</p>" | Out-File $outputHtml -Append
    }

    "</div>" | Out-File $outputHtml -Append
}

<<<<<<< Updated upstream
$hotspot = Get-Content ../temp/hotspot.txt

Add-Type -AssemblyName PresentationFramework
[System.Windows.MessageBox]::Show("🔥 DAT Insight:\n$hotspot")

<div class="box">
  <span>📊 DSA Insights Loaded:</span> Map-ready ✅
</div>

=======
int main() {
    std::cout << "🔧 Starting HackfrontierCPP Diagnostic Scanner...\n";

    // 🔍 Phase 1: Scan for Borland Executables
    std::cout << "🔍 Scanning DevTools Directory...\n";
    std::vector<std::string> tools = { "../devtools/bcc.exe", "../devtools/tlink.exe", "../devtools/dfa.exe" };
    bool missing = false;

    for (const auto& path : tools) {
        if (!fileExists(path)) {
            std::cout << "⚠️  Missing: " << fs::path(path).filename().string() << "\n";
            missing = true;
        }
    }

    if (missing) {
        std::cout << "⚠️  Missing critical Borland tools. Attempting to fetch...\n";
    #ifdef _WIN32
        system("powershell -ExecutionPolicy Bypass -File ../devtools/fetchBorlandTools.ps1");
    #else
        system("pwsh -ExecutionPolicy Bypass -File ../devtools/fetchBorlandTools.ps1");
    #endif
    } else {
        std::cout << "✅ All Borland tools present.\n";
    }
>>>>>>> Stashed changes

# 🌍 EarthCam Feeds
$feedsRaw = Get-Content "../feeds/live_feeds.json" -Raw | ConvertFrom-Json
$webcams = $feedsRaw.PSObject.Properties | Where-Object { $_.Name -ne "datasets" }

"<div class='card'><h2>🌐 EarthCam Live Feeds</h2>" | Out-File $outputHtml -Append
foreach ($cam in $webcams) {
    $label = $cam.Name -replace '_', ' '
    " <p>📷 <a href='$($cam.Value)' target='_blank'>$label</a></p>" | Out-File $outputHtml -Append
}
"</div>" | Out-File $outputHtml -Append


