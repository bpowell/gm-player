# GM-Player
GM-Player is a standalone application for Google Music. Because Google Music can not have keyboard controls when the browser window is not focused, we needed something better.

## Dependencies
* libwebkit
* libsoup
* python2-notify

### libwebkit
In Ubuntu based distros(including Mint):

```sh
sudo apt-get install python-webkit
```

### libsoup
This is needed for cookie management. In Ubuntu based distros(including Mint) as of June 17th, 2013:

```sh
sudo apt-get install libsoup2.4-1
```

### python2-notify
Because some of the webkit stuff uses gobject, we can't use the libnotify in python.

```sh
sudo apt-get install python2-notify
```

## Configuration
When the program is started for the first time, it will prompt for paths to libwebkit and libsoup. As of June 17th, 2013 in Ubuntu (12.04) and Mint (14) the path for each are:
* /usr/lib/x86_64-linux-gnu/libsoup-2.4.so
* /usr/lib/libwebkitgtk-1.0.so.0

A directory is created in your home folder called .gm-player. It contains a config file containing these paths. Also inside of the folder is the cookie store. 

## How to use it
gm-player.py is the main application. This is what starts up the web interface to music.google.com.
gm-player-client.py is the way to get information from gm-player.py. It connects to the dbus session created by the player. You can bind this command to keyboard shortcuts in your favorite window manager.

The following commands are currently supported:
* play or pp or pause - Plays and pauses the current track
* prev                - Plays the previous track
* next                - Plays the next track
* status	      - Outputs on one line current artist, title and album
* status2	      - Outputs on multiple lines current artist, title and album
* artist	      - Outputs the current artist
* title		      - Outputs the current title
* album 	      - Outputs the current album
