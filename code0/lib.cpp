#include <python3.5/Python.h>
#include <cstdio>
PyObject *func(PyObject *self)
{
 //do some stuff
 return PyUnicode_FromFormat("Hello world to python extended C\n");
}
char docs0[] = "this is documentation for func()";
char docs1[] = "this is documentation for module";
PyMethodDef say_hello[] = {
	{
		"myFunc",  //name. func() will become myFunc in python
		(PyCFunction)func, //targeting func
		METH_NOARGS, //func() is doesnt have arguments. so it will NOARGS
		docs0}, //the documentation
		{NULL} //mark its end
};

PyModuleDef module_def = {PyModuleDef_HEAD_INIT, 
	"mymodule"
	, docs1,-1, say_hello, NULL, NULL, NULL, NULL};

PyMODINIT_FUNC PyInit_mymodule(void){
 return PyModule_Create(&module_def);
}
