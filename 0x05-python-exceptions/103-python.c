#include "Python.h"
#include <stdio.h>
#include <stdlib.h>

void print_char(const char *str, int n);
void print_python_float(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_list(PyObject *p);

/**
 * print_python_list - loops over string and prints every character.
 * @str: the string.
 * @n: counter.
 * Return: void.
 */
void print_char(const char *str, int n)
{
    int i = 0;
    for (; i < n - 1; ++i)
    {
        printf("%02x ", (unsigned char)str[i]);
    }

    printf("%02x", str[i]);
    fflush(stdout);
}

/**
 * print_python_list - prints information about Python lists.
 * @p: python object.
 * Return: void.
 */
void print_python_list(PyObject *p)
{
    int list_length = 0, i = 0;
    PyObject *item;
    PyListObject *clone = (PyListObject *)p;

    printf("[*] Python list info\n");
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list_length = PyList_GET_SIZE(p);

    printf("[*] Size of the Python List = %d\n", list_length);
    printf("[*] Allocated = %d\n", (int)clone->allocated);

    for (; i < list_length; ++i)
    {
        item = PyList_GET_ITEM(p, i);
        printf("Element %d: %s\n", i, item->ob_type->tp_name);

        if (PyBytes_Check(item))
        {
            print_python_bytes(item);
        }
        else if (PyFloat_Check(item))
        {
            print_python_float(item);
        }
    }

    fflush(stdout);
}

/**
 * print_python_bytes - prints information about Python bytes.
 * @p: python object.
 * Return: void.
 */
void print_python_bytes(PyObject *p)
{
    PyBytesObject *clone = (PyBytesObject *)p;
    int calc_bytes, clone_size = 0;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    clone_size = PyBytes_Size(p);
    calc_bytes = clone_size + 1;

    if (calc_bytes >= 10)
    {
        calc_bytes = 10;
    }

    printf("  size: %d\n", clone_size);
    printf("  trying string: %s\n", clone->ob_sval);
    printf("  first %d bytes: ", calc_bytes);
    print_char(clone->ob_sval, calc_bytes);
    printf("\n");

    fflush(stdout);
}

/**
 * print_python_float - prints information about Python floats.
 * @p: python object.
 * Return: void.
 */
void print_python_float(PyObject *p)
{
    PyFloatObject *clone = (PyFloatObject *)p;
    float number = 0;

    printf("[.] float object info\n");

    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    number = clone->ob_fval;

    if ((int)number == number)
    {
        printf("  value: %0.1f\n", clone->ob_fval);
    }
    else
    {
        printf("  value: %0.16g\n", clone->ob_fval);
    }

    fflush(stdout);
}
