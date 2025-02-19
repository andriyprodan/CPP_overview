## What is the correct syntax for catching any type of exception in C++?
- catch(...)  
  
In C++, the syntax 'catch(...)' is used to catch any type of exception. This is known as a catch-all handler. It will catch all exceptions, regardless of their type. 

## Which base class should a custom exception class typically inherit from in C++?
- std::exception  
  
In C++, custom exception classes typically inherit from std::exception or one of its derived classes. std::exception is the base class for all standard exceptions. std::runtime_error is a derived class of std::exception and can also be used.

## Which statement correctly rethrows the current exception in a catch block?
- throw;  
  
In C++, to rethrow the current exception from within a catch block, you simply use the 'throw;' statement without any argument. This preserves the original exception object and its type. 'throw e;' would throw a new exception of the type of 'e'. 