#!/usr/bin/env python

class Property(object):
	def __init__(self):
		self.d = {}
		pass

	def __parse(self, lines):

		key = []
		value = []

		for line in lines:
			if not line: continue		#empty lines
			if line[0]=='#': continue	#comments
			line = line.strip('\n')
			line = line.split('=')
			key.append(line[0])
			value.append(line[1])

		self.d = dict(zip((key), (value)))

		#Remove to free RAM
		del lines
		del key
		del value

	def getProperty(self, key):
		return self.d.get(key)

	def setProperty(self, key, value):
		self.d[key] = value

	def load(self, stream):
		if type(stream) is not file:
			raise TypeError, 'Not a file'
		
		if stream.mode != 'r':
			raise ValueError, 'Read-only'

		try:
			lines = stream.readlines()
			self.__parse(lines)
		except IOError, e:
			raise

		#clean up
		del lines
		stream.close()

	def store(self, out):
		if out.mode != 'w':
			raise ValueError, 'File needs to be writable'

		try:
			key = self.d.keys()
			value = self.d.values()

			for i in range(len(self.d)):
				out.write(str(key[i])+"="+str(value[i])+"\n")
		except IOError, e:
			raise

		#clean up
		del key
		del value
		out.close()
