#!/usr/bin/env python

import dbus
import argparse
import sys

object_path = "/com/github/bpowell/gm_player"
name = "com.github.bpowell.gm_player"

parser = argparse.ArgumentParser(description='Client library for gm-player.')
parser.add_argument('action', type=str, default='status', nargs='?')

args = parser.parse_args()
action = args.action


try:
	bus = dbus.SessionBus()
	gm_player_service = bus.get_object(name, object_path)
except:
	print "gm-player.py not running."
	sys.exit()	

if action=='title':
	title = gm_player_service.get_dbus_method('get_title', name)
	print title()

if action=="artist":
	artist = gm_player_service.get_dbus_method('get_artist', name)
	print artist()

if action=="album":
	album = gm_player_service.get_dbus_method('get_album', name)
	print album()

if action=="status":
	status = gm_player_service.get_dbus_method('status', name)
	print status()

if action=="pp" or action=="play" or action=="pause":
	pp = gm_player_service.get_dbus_method('play_pause', name)
	pp()

if action=="prev":
	prev = gm_player_service.get_dbus_method('prev_song', name)
	prev()

if action=="next":
	nextt = gm_player_service.get_dbus_method('next_song', name)
	nextt()

if action=="status2":
	status2 = gm_player_service.get_dbus_method('status2', name)
	print status2()
