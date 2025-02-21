### Multiset in STL

A Multiset is similar to a Set in many ways, as both containers store elements in a sorted order. However, the key distinction is that Multiset allows duplicate elements, meaning you can have multiple occurrences of the same value in the container. This feature makes it suitable for scenarios where you need to keep track of the frequency of elements or store multiple items with identical values.

Here's a quick reference for common operations with the `multiset` container in C++.

*   **Declaration:**
    ```cpp
    multiset<int> ms;
    ```

This declaration creates an empty multiset that can hold integers. Similar to vectors and arrays, you can choose the data type for the multiset's elements.

*   **Size:**
    ```cpp
    int sz = ms.size();
    ```

At any given point, you can determine the current size (the number of elements) in the multiset.

*   **Inserting an element:**
    ```cpp
    ms.insert(x);
    ```

This inserts an element `x` into the `multiset`. Unlike `set`, `multiset` allows duplicate elements, so you can have multiple occurrences of the same value.

*   **Removing an element:**
    ```cpp
    s.erase(x);
    ```

This removes all occurrence of the element `x` from the `multiset`, if it exists. If there are multiple occurrences of `x`, all of them will be removed.

*   **Finding an element:**
    ```cpp
    auto it = s.find(x);
    ```

This returns an iterator to the first occurrence of the element with a value equal to `x`. If `x` is not found, the iterator points to the end of the `multiset`.

*   **Checking if an element exists:**
    ```cpp
    if (s.count(x))
    ```

This checks if an element with value `x` exists in the `multiset`. Returns the count of occurrences (which could be greater than one) if found, or 000 otherwise.

*   **Iterating through the set:**
    ```cpp
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        // Access the current element using *it
    }
    ```

It is important to note that insertion, deletion, and finding elements in a `multiset` have a time complexity of O(logn)O(log n)O(logn) on average. This is because similar as `set`, multisets are also usually implemented as balanced binary search trees.

`multiset` also maintains a strict order of elements based on their values, similar to `set`. However, unlike `set`, `multiset` allows duplicate elements, making it suitable for scenarios where you need to store multiple occurrences of the same value.