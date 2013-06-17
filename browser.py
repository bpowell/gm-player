#!/usr/bin/env python

import webkit
import gtk

import ctypes

class Browser:
	def __init__(self, config):
		self.config = config
		self.window = gtk.Window()
		self.window.resize(1024,768)

		libsoup = ctypes.CDLL(self.config.getProperty("path_libsoup"))
		libwebkit = ctypes.CDLL(self.config.getProperty("path_libwebkit"))
		session = libwebkit.webkit_get_default_session()
		cookiejar = libsoup.soup_cookie_jar_text_new(self.config.getProperty("cookie"), False)
		libsoup.soup_session_add_feature(session, cookiejar)

		self.scroll = gtk.ScrolledWindow()

		self.browser = webkit.WebView()
		self.browser.open("https://music.google.com")
		
		self.scroll.add(self.browser)
		self.window.add(self.scroll)
		self.window.show_all()

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
