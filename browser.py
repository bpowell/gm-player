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

		gtk.main()
