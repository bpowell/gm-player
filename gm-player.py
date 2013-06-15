#!/usr/bin/env python

import browser
from gm_service import GMPlayerService
from dbus.mainloop.glib import DBusGMainLoop

import gtk

def main():
	gm_player = browser.Browser()
	DBusGMainLoop(set_as_default=True)
	service = GMPlayerService(gm_player)

	gtk.main()

if __name__ == "__main__":
	main()
