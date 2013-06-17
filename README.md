# GM-Player
GM-Player is a standalone application for Google Music. Because Google Music can not have keyboard controls when the browser window is not focused, we needed something better.

## Dependencies
* libwebkit
* libsoup

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

## Configuration
When the program is started for the first time, it will prompt for paths to libwebkit and libsoup. As of June 17th, 2013 in Ubuntu (12.04) and Mint (14) the path for each are:
* /usr/lib/x86_64-linux-gnu/libsoup-2.4.so
* /usr/lib/libwebkitgtk-1.0.so.0

A directory is created in your home folder called .gm-player. It contains a config file containing these paths. Also inside of the folder is the cookie store. 
