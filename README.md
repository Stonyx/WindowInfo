# WindowInfo

Simple command line application that retrieves information about a window via the `GetWindowInfo` Windows API function.

The following information can be retrieved:

- the coordinates of the window
- the coordinates of the client area
- the window styles (see [Window Styles](https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles))
- the extended window styles (see [Extended Window Styles](https://learn.microsoft.com/en-us/windows/win32/winmsg/extended-window-styles))
- the window status
- the width of the window border (in pixels)
- the height of the window border (in pixels)
- the Windows version of the application that created the window

Using the application requires knowing the window handle of a window which can be retrieved with several other applications, including [cmdow](https://ritchielawrence.github.io/cmdow/).
