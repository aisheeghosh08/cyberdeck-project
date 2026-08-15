# DIY Media Cyberdeck 🎧

My first attempt at building a portable cyberdeck designed for music and video playback.

## Version 2 — Interactive Menu Prototype

Version 2 builds upon the basic navigation system from Version 1.

The prototype now has **selectable menu items and separate screens** for Music, Movies, Files, and Settings.

### Components

* Arduino Uno
* SSD1306 OLED display
* 4 push buttons

### Features

* OLED menu interface
* Up/down menu navigation
* Selectable menu items
* Music screen
* Movies screen
* Files screen
* Settings screen
* Back navigation to the main menu

### Controls

| Button   | Function  |
| -------- | --------- |
| Button 1 | Move up   |
| Button 2 | Move down |
| Button 3 | Select    |
| Button 4 | Back      |

### Menu Structure

```text
CYBERDECK
│
├── MUSIC
│   └── No music loaded
│
├── MOVIES
│   └── No movies loaded
│
├── FILES
│   └── Storage empty
│
└── SETTINGS
    └── Volume: 70%
```

## Current Status

* [x] OLED display working
* [x] Menu navigation working
* [x] Menu selection working
* [x] Music screen
* [x] Movies screen
* [x] Files screen
* [x] Settings screen
* [x] Back navigation
* [ ] Actual music playback
* [ ] Actual video playback
* [ ] Physical hardware
* [ ] Battery system
* [ ] Enclosure

## Goal

Build a physical portable media cyberdeck capable of playing music and videos while maintaining a unique personal aesthetic.

## Development History

### Version 1

Basic OLED menu with up/down navigation.

### Version 2

Added selectable menu items, individual screens, and back navigation.

### Next — Version 3

Rotary encoder navigation and volume-control interface.
