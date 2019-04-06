from distutils.core import setup, Extension

setup(name="test_API",  version="1.0", ext_modules=[Extension("test_API", ["test0.cpp"])]);
