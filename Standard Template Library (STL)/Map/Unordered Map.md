### Unordered Map in STL

`unordered_map` is another associative container in C++ that stores key-value pairs. Like `map`, each key in `unordered_map` is unique, but unlike `map`, `unordered_map` does not maintain the order of keys and values. Instead, it uses a hash table to store and retrieve elements, making its operations generally faster than `map`.

Here's a quick reference for common operations with the `unordered_map` container in C++ which are mostly similar to that of `map`:

*   **Declaration:**
    ```cpp
    unordered_map<string, int> um;
    ```

This declaration creates an empty `unordered_map` that associates strings with integers. You can choose the data types for both the keys and values in the `unordered_map`.

*   **Size:**
    ```cpp
    int sz = um.size();
    ```

At any given point, you can determine the current size (the number of key-value pairs) in the `unordered_map`.

*   **Inserting an element:**
    ```cpp
    um.insert(make_pair(key, value));
    ```

This inserts a key-value pair `(key, value)` into the `unordered_map`. If `key` is already present, the insert operation updates the corresponding value.  
Alternatively, you can use `um[key] = value` to insert a key-value pair `(key, value)` into the `unordered_map`. If `key` is not present, this will insert the key-value pair into the `unordered_map`. If `key` is already present, this operation will update the corresponding value.

*   **Removing an element:**
    ```cpp
    um.erase(key);
    ```

This removes the key-value pair with the specified key from the `unordered_map`, if it exists.

*   **Finding an element:**
    ```cpp
    auto it = um.find(key);
    ```

This returns an iterator to the key-value pair with the specified key. If the key is not found, the iterator points to the end of the `unordered_map`.

*   **Checking if an element exists:**
    ```cpp
    if (um.count(key))
    ```

This checks if a key exists in the `unordered_map`. Returns 111 if found, 000 otherwise.

*   **Iterating through the `unordered_map`:**
    ```cpp
    for (auto it = um.begin(); it != um.end(); ++it) {
        // Access the current element using *it
    }
    // or using range-based iterator
    for(auto &it: um) {
      // it.first provides key, it.second provides value
    }
    ```

It is important to note that insertion, deletion, and finding elements in an `unordered_map` have an average time complexity of O(1)O(1)O(1). However, in the worst case, the time complexity can be O(n)O(n)O(n) due to hash collisions. Read more about that [here.](https://codeforces.com/blog/entry/62393)

Unlike `map`, `unordered_map` does not maintain the order based on keys. The keys in `unordered_map` are hashed to determine the position of corresponding values in the container, which leads to faster access times compared to `map`.

**Comparison between `map` and `unordered_map`:**

*   **Ordering:**
    
    *   `map`: Maintains order based on keys.
    *   `unordered_map`: Does not maintain any order.
*   **Time Complexity:**
    
    *   `map`: $O(\log n)$ for insertion, deletion, and finding.
    *   `unordered_map`: Average $O(1)$ for insertion, deletion, and finding. Worst case $O(n)$ due to hash collisions.
*   **Implementation:**
    
    *   `map`: Typically implemented as a balanced binary search tree.
    *   `unordered_map`: Implemented as a hash table.
*   **Usage:**
    
    *   Use `map` when you need to maintain order or perform operations that require sorted data.
    *   Use `unordered_map` when you need faster average access times and order is not a concern.