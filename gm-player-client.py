#!/usr/bin/env python

import dbus
import argparse

parser = argparse.ArgumentParser(description='Client library for gm-player.')
parser.add_argument('action', type=str, default='status', nargs='?')

args = parser.parse_args()
action = args.action


bus = dbus.SessionBus()
gm_player_service = bus.get_object('com.github.bpowell.gm_player', '/com/github/bpowell/gm_player')

if action=='title':
	status = gm_player_service.get_dbus_method('get_title', 'com.github.bpowell.gm_player')
	print status()
