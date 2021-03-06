# McOfee_Simulation
This demo is mainly related to C++ and Python binding using SWIG. This simulates a computer being infected by various threats(C++) and a shell which allows a user to defend himself by getting rid of threats from the computer(Python).
<br/><br/>
The purpose of this demo is also to use different C++ concepts in order to check wheter these are properly managed by SWIG:<br/>
_ Template function<br/>
_ Virtual functions<br/>
_ Inheritance<br/>
_ Overloaded operators<br/>
_ Multi-threading<br/>
_ Using external libraries such as Boost<br/>
_ Pure virtual functions<br/>
_ Static variables (class)<br/>
_ Abstract class ...<br/>
<br/><br/>
This project simulates a computer being infected. A main class Computer will act as the local computer, receive threats generated by the ThreatGenerator. The main simulation class will manage all of the components, including the MySQL Logger, and will be the main bridge between C++ and Python, using SWIG.

The Python side will be a custom Python shell, which will allow the user to perform several actions such as list the current threats, remove, placing in quarantine or even rename a threat.
<br/><br/>
<b>How does this work?</b><br/>
Once the C++ code done, SWIG will require an interface file(.i) to be done in order to prepare a wrapper between C++ and Python.
Then, the second step is to use the Python module DistUtils which will build the Python module that will be included in the Python script.
Once the module generated (Distutils will use GCC/G++ with the different flags set by the developer), it will be possible to import it
in any Python script (import). Then, the module will have to instanciate a Simulation object and call functions available from it.
Notice that the Python shell of this demo is custom, which means that the user will be able to have its own shell with its own
functions with auto-completion. In order to do that, the function has to start by "do_" + functionName.

<br/><br/>
<b>To install and run:</b><br/>
This demo runs on GNU/Linux Ubuntu 16.04LTS and requires the MySQL/Boost and SWIG libraries.<br/><br/>

<b>To compile the basic C++ demo (with full debug symbols):</b><br/>
g++ -g3 -std=c++11 -I/usr/include/python2.7 -Wall Computer.cpp MySQLLogger/MySQLLogger.cpp ThreatGenerator/ThreatGenerator.cpp Threats/Virus.cpp Threats/TrojanHorse.cpp Threats/Rootkit.cpp Simulation.cpp testDemo.cpp -o Simulation -lpython2.7 -pthread -lboost_thread -lboost_system -lboost_filesystem -lboost_regex -lmysqlcppconn
<br/><br/>
<b>To generate the SWIG interface:</b><br/>
swig -c++ -python mcofee.i
<br/><br/>
<b>Build the Python module:</b><br/>
python setup.py build_ext --inplace
<br/><br/>
<b>Launch the demo:</b><br/>
python testDemo.py
<br/><br/>
The UML directory contains UML classes and sequence diagrams that can be opened with UMLet for GNU/Linux.
And the Doxygen directory contains all of the files for the documentation of the project (JavaDoc) like.
