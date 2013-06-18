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

def main():
	global config
	setup()

	systray = gtk.StatusIcon()
	systray.set_from_stock(gtk.STOCK_MEDIA_NEXT)

	gm_player = browser.Browser(config)
	DBusGMainLoop(set_as_default=True)
	service = GMPlayerService(gm_player)

	gtk.main()

if __name__ == "__main__":
	main()
