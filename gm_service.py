#!/usr/bin/env python

import gtk
import dbus
import dbus.service

class GMPlayerService(dbus.service.Object):
	def __init__(self, browser):
		bus_name = dbus.service.BusName('com.github.bpowell.gm_player', bus=dbus.SessionBus())
		dbus.service.Object.__init__(self, bus_name, '/com/github/bpowell/gm_player')
		self.browser = browser

	@dbus.service.method('com.github.bpowell.gm_player')
	def play_pause(self):
		self.browser.play_pause()
		return

	@dbus.service.method('com.github.bpowell.gm_player')
	def next_song(self):
		self.browser.next()
		return

	@dbus.service.method('com.github.bpowell.gm_player')
	def prev_song(self):
		self.browser.prev()
		return
