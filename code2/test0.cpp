#include <python3.5/Python.h>
#include <cstdio>
#include "lib.h"
PyObject *myinteger(PyObject *self)
{
 return Py_BuildValue("i", 100);
}
PyObject *testfunc(PyObject *self)
{
 return Py_BuildValue("i", func());
}
char docs[] = "This is for dream and hope\n";
PyMethodDef allfunc[]  = {
{"myinteger", (PyCFunction)testfunc, METH_VARARGS, docs},
{NULL, NULL, NULL, NULL}
};

char moddocs[] = "did you know? walle eat iron\n";
PyModuleDef mymod = {PyModuleDef_HEAD_INIT, "test_API", moddocs, -1, allfunc, NULL, NULL, NULL, NULL};

PyMODINIT_FUNC PyInit_test_API()
{
 PyModule_Create(&mymod);
}

int main()
{
 PyObject *a = Py_BuildValue("i", 100);
 return 0;
}
