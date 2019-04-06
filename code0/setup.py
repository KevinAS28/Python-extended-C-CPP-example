#!/usr/bin/env python3

from distutils.core import setup, Extension

setup(name="mymodule", #in python we will import this mymodule
	version="1.0", ext_modules = [Extension("mymodule", ["lib.cpp"])])
