#!/usr/bin/python3
"""Prints tuples of square position'"""


class Square:
    """A class that defines a square"""

    def __init__(self, size=0, position=(0, 0)):
        """Initializes the square with position and size"""
        self.size = size
        try:
            self.position = position
        except TypeError as typ:
            print(typ)

    @property
    def position(self):
        """Defines the position of the square and return the value"""
        return self.__position

    @position.setter
    def position(self, value):
        """Check type, length, and value and raise error accordingly"""
        if type(value) is not tuple:
            self.__position = None
            raise TypeError("position must be a tuple of 2 positive integers")
        elif len(value) != 2:
            self.__position = None
            raise TypeError("position must be a tuple of 2 positive integers")
        elif type(value[0]) is not int or type(value[1]) is not int:
            self.__position = None
            raise TypeError("position must be a tuple of 2 positive integers")
        elif value[0] < 0 or value[1] < 0:
            self.__position = None
            raise TypeError("position must be a tuple of 2 positive integers")
        else:
            self.__position = value

    @property
    def size(self):
        """Defines the size of square and returns its value"""
        return self.__size

    @size.setter
    def size(self, value):
        """Check type and value and raise error accordingly"""
        self.__size = value
        if type(value) is not int:
            raise TypeError('size must be an integer')
        if value < 0:
            raise ValueError('size must be >= 0')

    def area(self):
        """Defines the area of a square and return the value"""
        return self.__size ** 2

    def my_print(self):
        """Prints in stdout the square with character #"""
        if self.position:
            if self.size > 0:
                print('\n' * self.position[1], end="")
                for _ in range(self.__size):
                    print(' ' * self.position[0], end="")
                    print('#' * self.size)
        if self.__size == 0:
            print()
