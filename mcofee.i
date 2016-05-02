/*
* File: mcofee.i
* Author: David Docteur
* Company: Undefined
* Date: XX/XX/XXXX
* 
* This file is a SWIG interface
* necessary to bind the C++ and Python
* programming languages.
*/

/* Module name */
%module mcofee

/* Includes */
%include "std_list.i"
%include "std_string.i"

/* Refers to */
%{
#include "Simulation.h"
%}

/* Include header's data */
%include "Simulation.h"

