#!/usr/bin/env python

import browser
from gm_service import GMPlayerService
from Property import Property

from dbus.mainloop.glib import DBusGMainLoop
import gtk
import os

configdir=os.path.expanduser("~")+'/.gm-player'
configfile='config'
config = None

def create_config():
	p = Property()
	path_libwebkit = raw_input("Path to libwebkit: ")
	path_libsoup = raw_input("Path to libsoup: ")
	p.setProperty("path_libwebkit", path_libwebkit)
	p.setProperty("path_libsoup", path_libsoup)
	p.setProperty("path_config", configdir)
	p.setProperty("cookie", configdir+'/cookie')
	p.store(open(configdir+'/'+configfile, 'w'))

def setup():
	if not os.path.isdir(configdir):
		os.mkdir(configdir)

	if not os.path.isfile(configdir+'/'+configfile):
		create_config()

	global config
	config = Property()
	config.load(open(configdir+'/'+configfile))

def right_click_systray(icon, button, time):
	menu = gtk.Menu()
	quit = gtk.MenuItem("Quit")
	quit.connect("activate", gtk.main_quit)
	menu.append(quit)
	menu.show_all()
	global systray
	menu.popup(None, None, gtk.status_icon_position_menu, button, time, systray)

def main():
	global config
	global systray
	setup()

	systray = gtk.StatusIcon()
	systray.set_from_stock(gtk.STOCK_MEDIA_NEXT)
	systray.connect("popup-menu", right_click_systray)

	gm_player = browser.Browser(config)
	DBusGMainLoop(set_as_default=True)
	service = GMPlayerService(gm_player)

	gtk.main()

if __name__ == "__main__":
	main()
