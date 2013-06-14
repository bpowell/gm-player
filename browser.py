#!/usr/bin/env python

import webkit
import gtk

class Browser:

	def __init__(self):
		self.window = gtk.Window()
		self.window.resize(1024,768)
		
		self.browser = webkit.WebView()
		self.browser.open("https://music.google.com")
		
		self.window.add(self.browser)
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
