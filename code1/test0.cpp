#include <python3.5/Python.h>
#include <unistd.h>


static int checkPass(int x)
{
 return (x>=100?1:0);
}

PyObject *hello(PyObject * self)
{
 return PyUnicode_FromFormat("Hell what, you again?\n");
}

char hello_docs[] = "I can see you now\n";

PyObject *kevin_API(PyObject *self, PyObject *args )
{
 int pass;
 char *str;
 if (!PyArg_ParseTuple(args, "is", &pass, &str)){return NULL;}
 if (checkPass(pass))
 {
  printf("kevin API is working...");
  usleep(3000000);
  printf("[DONE]\n");
  return Py_BuildValue("i", 1000);
 }else{
  printf("THREAT DETECTED\n");
  return NULL;
 }
}
char kevin_API_docs[] = "But you cant see me";
PyObject *the_API(PyObject *self, PyObject *args)
{
 int kev;
 if (!(PyArg_ParseTuple(args, "i", &kev))){return NULL;}
 return Py_BuildValue("s", kev>999?"Success":"THREAT DETECTED");
}
char the_API_docs[] = "And now you see me";

PyMethodDef allfunc[] = {
{"hello", (PyCFunction)hello, METH_NOARGS, hello_docs},

{"the_API", (PyCFunction)the_API, METH_VARARGS, the_API_docs},

{"kevin_API", (PyCFunction)kevin_API, METH_VARARGS, kevin_API_docs},

{NULL, NULL, NULL, NULL}
};

char mod_docs[] = "JK, Just Kidding";
PyModuleDef mymod = {
PyModuleDef_HEAD_INIT,
"test_API",
mod_docs,
-1,
allfunc,
NULL,
NULL,
NULL,
NULL
};

PyMODINIT_FUNC PyInit_test_API()
{
 PyModule_Create(&mymod);
}



