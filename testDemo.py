"""
" Filename: testDemo.py
" Author: David Docteur
" Company: Undefined
" Date: XX/XX/XXXX
"
" This file is a simple test file to launch a simulation.
"""

# Import launcher\
import mcofee
import cmd, sys, os
from ctypes import *

class McOfeeShell(cmd.Cmd):

	intro = 	"Welcome to the McOfee shell.   Type help or ? to list commands.\n"
	prompt = 	"McOfee> "
	file = 		None
	inst = 		None
	running = False

	def do_startSim(self, args):
		'''
		Launches a simulation
		'''
		print "Simulation launched !"
		
		if self.running is False:
			# Initialize and run simulation
			self.inst = mcofee.Simulation()
			self.running = True
		else:
			print "The simulation is already running."

	def do_stopSim(self, args):
		"""
			Stops a simulation
		"""
		if self.running is True:
			print "Simulation stopped !"
			self.inst.stop()
			self.running = False
		else:
			print "The simulation has already been stopped."

	def do_sendThreats(self, args):
		"""
		Starts the thread 
		"""
		if self.inst is not None and self.running:
			self.inst.start()
		else:
			print "You should first start the simulation"

	def do_getThreats(self, args):
		"""
		See the active threats on the computer
		"""
		if self.inst is not None:
			for threat in self.inst.getThreatsList():
				print str(threat)
		else:
			print "You should first start the simulation"

	def do_deleteThreat(self, args):
		"""
		Deletes a threat.
		"""
		if self.inst is not None:
			if len(args) != 0:
				parsed = parse(args)
				self.inst.deleteThreat(int(parsed[0]))
			else:
				print "You should specify a threat id."
		else:
			print "You should first start the simulation"

	def do_quarantineThreat(self, args):
		"""
		Places a threat in quarantine
		"""
		if self.inst is not None:
			if len(args) != 0:
				parsed = parse(args)
				self.inst.quarantineThreat(int(parsed[0]));
			else:
				print "You should specify a threat id."
		else:
			print "You should first start the simulation"

	def do_renameThreat(self, args):
		"""
			Renames a threat
		"""
		if self.inst is not None:
			parsed = parse(args)
			if len(parsed) >= 2:
				threatId = parsed[0]
				threatName = parsed[1]
				self.inst.renameThreat(int(threatId), threatName)
			else:
				print "You should specify a threat id AND a new name."
		else:
			print "You should first start the simulation"

	def do_cleanDatabase(self, args):
		"""
			Flushes the table
		"""
		if self.inst is not None:
			self.inst.flushLogs()
		else:
			"You should first start the simulation."

	def do_checkArgs(self, arg):
		"""
			Checks passed args
		"""
		print arg

	def do_cls(self, arg):
		"""
			Clears the interpreter
		"""
		os.system('clear')

	def do_quit(self, arg):
		"""
			Quits the application
		"""
		print "Bye bye!!!"
		sys.exit()

def parse(arg):
	"""
		Convert a series of zero or more numbers to an argument tuple
	"""
	return tuple(map(str, arg.split()))

if __name__ == '__main__':
	McOfeeShell().cmdloop()
