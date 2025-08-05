# 📦 Borland C++ 5.02 Setup (Legacy Dev Tools)

This folder documents the setup, environment, and integration path for the Borland C++ 5.02 IDE and OWL (ObjectWindows Library 5.0), preserved for use in this hybrid file auditing project.

---

## 🔗 ISO Source

- **Borland C++ 5.02 ISO (WinWorld)**  
  📎 https://winworldpc.com/download/35c2be17-78c3-8cc3-8e11-c3a6c2bb2a52  
  *(Educational/archival use only – not included in repo)*

---

## 📦 Full Environment Backup

To streamline setup across lab or virtual machines, this repo includes a ZIP archive (`bcc_bc5.zip`) of the **entire working Borland IDE** environment. While the original ISO is ~175MB across floppies, this snapshot ensures:

- No missing tools or headers
- OWL library and Help files intact
- Fast deployment without manual installs

> This archive is synced from a working lab machine where Borland was fully installed and tested.

---

## 🧱 Folder Contents

| Folder        | Purpose                                        |
|---------------|------------------------------------------------|
| `config/`     | Scripts to mimic Borland toolchain environment |
| `notes/`      | ISO references, setup logs, path plans         |
| `samples/`    | Future OWL GUI stubs and retro test projects   |

---

## 🧰 Local Windows Setup (Optional)

If setting up on a VM or Windows host:

```plaintext
Target Folder: C:\DevTools\BorlandCPP
Extracted ISO contents:
  - BIN\
  - INCLUDE\
  - LIB\
  - OWL\
  - HELP\
