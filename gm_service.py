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

	@dbus.service.method('com.github.bpowell.gm_player')
	def get_title(self):
		return self.browser.get_title()

	@dbus.service.method('com.github.bpowell.gm_player')
	def get_artist(self):
		return self.browser.get_artist()

	@dbus.service.method('com.github.bpowell.gm_player')
	def get_album(self):
		return self.browser.get_album()

	@dbus.service.method('com.github.bpowell.gm_player')
	def status(self):
		output = ""
		output += self.get_artist()
		output += " - " + self.get_title()
		output += " - " + self.get_album()

		return output

	@dbus.service.method('com.github.bpowell.gm_player')
	def status2(self):
		output = ""
		output += "Artist: " + self.get_artist() + "\n"
		output += "Title : " + self.get_title() + "\n"
		output += "Album : " + self.get_album() + "\n"

		return output
