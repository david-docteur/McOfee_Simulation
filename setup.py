'''
' File: setup.py
' Author: David Docteur
' Company: Undefined
' Date: XX/XX/XXXX
'
' This is where all of the magic happens. This file is going to
' work with DistUtils (which creates Python modules) and deals
' with all of the includes/librairies required by the project
' to be compiled.
'''

# Import building tools
import distutils.sysconfig
from distutils.core import setup, Extension

# Get rid of the Wstrict-prototypes flag
cfg_vars = distutils.sysconfig.get_config_vars()
for key, value in cfg_vars.items():
    if type(value) == str:
        cfg_vars[key] = value.replace("-Wstrict-prototypes", "")

# Defining module's requirements
mcofee_module = Extension('_mcofee',
                            include_dirs = ['/usr/local/include'],
                            libraries = ['pthread', 'boost_thread', 'boost_system',
                                         'boost_filesystem', 'boost_regex', 'mysqlcppconn'],
                            library_dirs = ['/usr/local/lib'],
                            extra_compile_args=['-g3','-std=c++11'],
                            sources=['mcofee_wrap.cxx', 'MySQLLogger/MySQLLogger.cpp',
                                     'ThreatGenerator/ThreatGenerator.cpp', 'Threats/Virus.cpp', 'Threats/TrojanHorse.cpp',
                                     'Threats/Rootkit.cpp', 'Computer.cpp', 'Simulation.cpp']
                         )

# Setup options
setup (name = 'mcofee',
       version = '1.1',
       author      = "David Docteur",
       description = """McOfee - Simulation of a computer being infected.""",
       ext_modules = [mcofee_module],
       py_modules = ["mcofee"],
)
