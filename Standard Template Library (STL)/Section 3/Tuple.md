### Tuple Intro

We often work with familiar data types like int, char, and double to represent individual values. Yet, situations arise where we must unite multiple disparate values into a coherent entity. In such cases, the tuple data type emerges as a powerful asset.

Tuples offer a versatile solution for consolidating multiple values of diverse types. Unlike pairs, tuples can accommodate more than two elements, making them adaptable for various scenarios.

Here's a concise reference for fundamental tuple operations in C++:

*   **Declaration:**
    ```cpp
    tuple<int, double, string> t;
    ```

    - This declaration creates an empty tuple capable of holding values of distinct types.
    - You can Customise the data types within the tuple to suit your needs, e.g.:
    
    ```cpp
    tuple<double, int> t;
    ```

*   **Initialisation:**
    ```cpp
    tuple<int, double, string> t(1, 3.14, "Hello");
    ```

    - This will initialise a tuple with specific values for each element. 
    - Another way to initialise a tuple is using make_tuple function e.g.:
    
    ```cpp
    tuple<int, double, string> t = make_tuple(1, 3.14, "Hello");
    ```

*   **Accessing Elements:**  
    Elements can be accessed using the `get` function.
    ```cpp
    get<0>(t);  // Will fetch the 1st element of the tuple.
    get<1>(t);  // Will fetch the 2nd element of the tuple. 
    get<2>(t);  // Will fetch the 3rd element of the tuple. 
    ```    
    
    Similarly you can get the next elements depending on the types in your tuple.
    
*   **Comparing Tuples:**
    
    *   Tuples can be compared using standard comparison operators i.e., `t1 < t2` which compares elements lexicographically meaning first elements will be compared first, then second elements if first elements are equal, and then third elements if both first and second elements are equal and so on.

The above mentioned tuple operations takes constant time, or O(1) except the Comparing Tuples operation which depends on the number of elements in the tuple.

Generally, comparing is done element-wise, comparing each corresponding element in lexicographical order until a difference is found. For tuples containing nnn elements, where the types of elements allow direct comparison (e.g., built-in types like int, double, char, etc.), the comparison time complexity is O(n). However, if the elements in the tuple are more complex (e.g, string, vector, etc.), custom comparison functions or operators might be involved, which could potentially increase the time complexity based on the complexity of those operations.