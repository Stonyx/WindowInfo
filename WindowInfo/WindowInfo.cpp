#include <cstring>
#include <iostream>
#include <regex>
#include <Windows.h>

// Use std namespace
using namespace std;

// Main function
int main(int argc, char* argv[])
{
  // Make sure we have two arguments
  if (argc != 3)
  {
    cout << "Usage: WindowInfo window_handle_in_hex { win_ltrb | client_ltrb | style | exstyle | "
      "status | xborder | yborder | type | version }" << endl;
    return 1;
  }

  // Make sure the first argument is correctly specified
  if (!regex_match(string(argv[1]), regex("^(0x)?[0-9a-f]{1,8}$", regex_constants::icase)))
  {
    cout << "Usage: WindowInfo window_handle_in_hex { win_ltrb | client_ltrb | style | exstyle | "
      "status | xborder | yborder | type | version }" << endl;
    return 1;
  }

  // Make sure the second argument is correctly specified
  if (!regex_match(string(argv[2]), regex("^(win_ltrb|client_ltrb|style|exstyle|status|xborder|"
    "yborder|type|version)$", regex_constants::icase)))
  {
    cout << "Usage: WindowInfo window_handle_in_hex { win_ltrb | client_ltrb | style | exstyle | "
      "status | xborder | yborder | type | version }" << endl;
    return 1;
  }

  // Call the GetWindowInfo function
  WINDOWINFO windowInfo;
  windowInfo.cbSize = sizeof(WINDOWINFO);
  if (!GetWindowInfo((HWND)strtoull(argv[1], NULL, 16), &windowInfo))
  {
    cout << "Failed to retrieve specified value." << endl;
    return 2;
  }

  // Check which value was specified and print it
  if (_stricmp(argv[2], "win_ltrb") == 0)
  {
    cout << windowInfo.rcWindow.left << " " << windowInfo.rcWindow.top << " " <<
      windowInfo.rcWindow.right << " " << windowInfo.rcWindow.bottom;
  }
  else if (_stricmp(argv[2], "client_ltrb") == 0)
  {
    cout << windowInfo.rcClient.left << " " << windowInfo.rcClient.top << " " <<
      windowInfo.rcClient.right << " " << windowInfo.rcClient.bottom;
  }
  else if (_stricmp(argv[2], "style") == 0)
  {
    cout << "0x" << hex << windowInfo.dwStyle;
  }
  else if (_stricmp(argv[2], "exstyle") == 0)
  {
    cout << "0x" << hex << windowInfo.dwExStyle;
  }
  else if (_stricmp(argv[2], "status") == 0)
  {
    cout << "0x" << hex << windowInfo.dwWindowStatus;
  }
  else if (_stricmp(argv[2], "xborder") == 0)
  {
    cout << windowInfo.cxWindowBorders;
  }
  else if (_stricmp(argv[2], "yborder") == 0)
  {
    cout << windowInfo.cyWindowBorders;
  }
  else if (_stricmp(argv[2], "type") == 0)
  {
    cout << "0x" << hex << windowInfo.atomWindowType;
  }
  else // if (_stricmp(argv[2], "version") == 0)
  {
    cout << windowInfo.wCreatorVersion;
  }

  return 0;
}