### Set in STL

Sets are a type of associative container in C++ that store unique elements in a specific order. They automatically manage the order of elements and ensure that each element is stored only once.

Here's a quick reference for common operations with the `std::set` container in C++.

*   **Declaration:**
    ```cpp
    set<int> s;
    ```

This declaration creates an empty set that can hold integers. Similar to vectors and arrays, you can choose the data type for the set's elements.

*   **Size:**
    ```cpp
    int sz = s.size();
    ```

At any given point, you can determine the current size (the number of elements) in the set.

*   **Inserting an element:**
    ```cpp
    s.insert(x);
    ```

This inserts an element `x` into the set. If `x` is already present in the set, the insert operation has no effect.

*   **Removing an element:**
    ```cpp
    s.erase(x);
    ```

This removes the element `x` from the set, if it exists. If `x` is not present, the erase operation has no effect.

*   **Finding an element:**
    ```cpp
    auto it = s.find(x);
    ```

This returns an iterator to the element with a value equal to `x`. If `x` is not found, the iterator points to the end of the set.

*   **Checking if an element exists:**
    ```cpp
    if (s.count(x))
    ```

This checks if an element with value `x` exists in the set. Returns 111 if found, 000 otherwise.

*   **Iterating through the set:**
    ```cpp
    for (auto it = s.begin(); it != s.end(); ++it) {
        // Access the current element using *it
    }
    ```

It is important to note that insertion, deletion, and finding elements in a set have a time complexity of O(logn) on average. This is because sets are usually implemented as balanced binary search trees.

Sets maintain a strict order of elements based on their values. Duplicate elements are not allowed. If you want a container that allows multiple occurrences of the same element, you can use the **`multiset`** container.