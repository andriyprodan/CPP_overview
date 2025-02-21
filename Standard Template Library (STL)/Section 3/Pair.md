### Pair

We are familiar with conventional data types like int, char, and double for representing individual values. However, when we need to combine two distinct values into a single entity, the pair data type becomes a valuable tool.

Here's a quick reference for common pair operations in C++.

*   **Declaration:**
    ```cpp
    pair<int, int> p;
    ```

This declaration creates an empty pair that can hold two integers.

You can define different data types for the pair's elements, such as:
    ```cpp
    pair<double, string> p;
    ```

This declaration will create a pair that hold a double and a string together.

*   **Initialisation:**
    ```cpp
    pair<int, int> p = make_pair(1, 2);
    ```

This will initialise the pair with value (1, 2).

Another way to initialise the pair is:

```cpp
pair<int, int> p = {1, 2};
```

*   **Accessing Elements:**
    ```cpp
    int x = p.first;  // First element of the pair is referenced as first.
    int y = p.second; // Second element of the pair is referenced as second.
    ```

The order is fixed for the first and second element in the pair.

*   **Comparing Pairs:**
    *   Pairs can be compared using standard comparison operators i.e., `p1 < p2` compares the first elements and then the second elements if the first ones are equal.

The complexity of above mentioned pair operations takes constant time, or O(1)O(1)O(1).