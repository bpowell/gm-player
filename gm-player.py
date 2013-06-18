#!/usr/bin/env python

import browser
from gm_service import GMPlayerService
from Property import Property

from dbus.mainloop.glib import DBusGMainLoop
import gtk
import os

class GMPlayer:
	def __init__(self):
		self.config = Property()
		self.configdir=os.path.expanduser("~")+'/.gm-player'
		self.configfile='config'

		if not os.path.isdir(self.configdir):
			os.mkdir(self.configdir)

		if not os.path.isfile(self.configdir+'/'+self.configfile):
			self.create_config()

		self.config.load(open(self.configdir+'/'+self.configfile))

		self.systray = gtk.StatusIcon()
		self.systray.set_from_stock(gtk.STOCK_MEDIA_NEXT)
		self.systray.connect("popup-menu", self.right_click_systray)

	def create_config(self):
		p = Property()
		path_libwebkit = raw_input("Path to libwebkit: ")
		path_libsoup = raw_input("Path to libsoup: ")
		p.setProperty("path_libwebkit", path_libwebkit)
		p.setProperty("path_libsoup", path_libsoup)
		p.setProperty("path_config", self.configdir)
		p.setProperty("cookie", self.configdir+'/cookie')
		p.store(open(configdir+'/'+self.configfile, 'w'))

	def right_click_systray(self, icon, button, time):
		menu = gtk.Menu()
		quit = gtk.MenuItem("Quit")
		quit.connect("activate", gtk.main_quit)
		menu.append(quit)
		menu.show_all()
		menu.popup(None, None, gtk.status_icon_position_menu, button, time, self.systray)

	def main(self):
		gm_player = browser.Browser(self.config)
		DBusGMainLoop(set_as_default=True)
		service = GMPlayerService(gm_player)

if __name__ == "__main__":
	gmplayer = GMPlayer()
	gmplayer.main()
	gtk.main()
