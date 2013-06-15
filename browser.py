#!/usr/bin/env python

import webkit
import gtk

import ctypes

class Browser:

	def __init__(self):
		self.window = gtk.Window()
		self.window.resize(1024,768)

		libsoup = ctypes.CDLL('/usr/lib/x86_64-linux-gnu/libsoup-2.4.so')
		libwebkit = ctypes.CDLL('/usr/lib/libwebkitgtk-1.0.so.0')
		session = libwebkit.webkit_get_default_session()
		cookiejar = libsoup.soup_cookie_jar_text_new('./my_cookie', False)
		libsoup.soup_session_add_feature(session, cookiejar)

		self.browser = webkit.WebView()
		self.browser.open("https://music.google.com")
		
		self.window.add(self.browser)
		self.window.show_all()

		gtk.main()

	def get_title(self):
		self.browser.execute_script("var a=document.getElementById('playerSongTitle').firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()

	def get_artist(self):
		self.browser.execute_script("var a=document.getElementById('player-artist').firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()

	def get_album(self):
		self.browser.execute_script("var a=document.getElementById('player-artist').nextSibling.nextSibling.firstChild;document.title=a.innerText||a.textContent")
		return self.browser.get_main_frame().get_title()
