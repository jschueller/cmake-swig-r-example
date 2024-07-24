%module(package="agrum", docstring="base module") base

%{
#include "Variable.h"
#include <cstdint>
%}

%include <std_string.i>
%include <std_vector.i>
%include <std_pair.i>

%include Variable.h

