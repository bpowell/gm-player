#!/usr/bin/env python

import webkit
import gtk
import ctypes
import pynotify

class Browser:
	def __init__(self, config):
		self.config = config

		libsoup = ctypes.CDLL(self.config.getProperty("path_libsoup"))
		libwebkit = ctypes.CDLL(self.config.getProperty("path_libwebkit"))
		session = libwebkit.webkit_get_default_session()
		cookiejar = libsoup.soup_cookie_jar_text_new(self.config.getProperty("cookie"), False)
		libsoup.soup_session_add_feature(session, cookiejar)

		self.scroll = gtk.ScrolledWindow()

		self.browser = webkit.WebView()
		self.browser.open("https://music.google.com")
		self.browser.connect("console-message", self.console)
		self.notifysignal = self.browser.connect("title-changed", self.notify)
		self.browser.connect("load-finished", self.webapploaded)
		
		self.scroll.add(self.browser)


	def get_window(self):
		return self.scroll

	def console(self, webview, message, lineno, fileurl):
		return True

	def notify(self, webview, webframe, title):
		if title=="change":
			self.browser.disconnect(self.notifysignal)
			pynotify.init("Track change")
			display = pynotify.Notification("Track Change", self.get_artist()+" - "+self.get_title()+" - "+self.get_album())
			display.show()
			self.notifysignal = self.browser.connect("title-changed", self.notify)


	def webapploaded(self, webview, webframe):
		self.browser.execute_script("SJBaddListener('nextSong', function qxz(){document.title='change';})")
		self.browser.execute_script("SJBaddListener('prevSong', function qxz(){document.title='change';})")
		self.browser.execute_script("SJBaddListener('playPause', function qxz(){document.title='change';})")

	def get_title(self):
		self.browser.execute_script("var a=document.getElementById('playerSongTitle').firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()

	def get_artist(self):
		self.browser.execute_script("var a=document.getElementById('player-artist').firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()

	def get_album(self):
		self.browser.execute_script("var a=document.getElementById('player-artist').nextSibling.nextSibling.firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()

	def play_pause(self):
		self.browser.execute_script('SJBpost("playPause")')

	def next(self):
		self.browser.execute_script('SJBpost("nextSong")')

	def prev(self):
		self.browser.execute_script('SJBpost("prevSong")')
