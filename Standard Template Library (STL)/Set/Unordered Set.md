### Unordered Set in STL

In C++, Unordered Set is a versatile associative container provided by the Standard Template Library (STL). It is designed for efficient storage and retrieval of unique elements. Unlike Set, which uses a balanced binary search tree, Unordered Set employs a **hash table** data structure, allowing for constant-time average complexity or O(1)O(1)O(1) for insertions, deletions, and searches.

Here's a quick reference for common operations with the `unordered_set` container in C++, which are almost same as that of `set` or `multiset`.

*   **Declaration:**
    ```cpp
    unordered_set<int> uset;
    ```

This declaration creates an empty set that can hold integers. You can choose the appropriate data type for your specific use case.

*   **Size:**
    ```cpp
    int sz = uset.size();
    ```

At any given point, you can determine the current size (the number of elements) in the unoredered set.

*   **Inserting an element:**
    ```cpp
    uset.insert(x);
    ```

This inserts an element `x` into the set. If `x` is already present in the set, the insert operation has no effect.

*   **Removing an element:**
    ```cpp
    uset.erase(x);
    ```

This removes the element `x` from the set, if it exists. If `x` is not present, the erase operation has no effect.

*   **Finding an element:**
    ```cpp
    auto it = uset.find(x);
    ```

This returns an iterator to the element with a value equal to `x`. If `x` is not found, the iterator points to the end of the set.

*   **Checking if an element exists:**
    ```cpp
    if (uset.count(x))
    ```

This checks if an element with value `x` exists in the set. Returns 111 if found, 000 otherwise.

*   **Iterating through the set:**
    ```cpp
    for (auto it = uset.begin(); it != uset.end(); ++it) {
        // Access the current element using *it
    }
    ```

`unordered_set` is a powerful and efficient container for storing unique elements, offering rapid access and efficient insertion and deletion operations. It is particularly useful when you need to manage a collection of elements with no specific order requirements.