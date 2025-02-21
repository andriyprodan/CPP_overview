### Map in STL

Maps are a type of associative container in C++ that store key-value pairs. Each key in the map is unique, and the map automatically manages the order of keys and values.

Here's a quick reference for common operations with the `map` container in C++.

*   **Declaration:**
    ```cpp
    map<string, int> m;
    ```
This declaration creates an empty map that associates strings with integers. You can choose the data types for both the keys and values in the map.

*   **Size:**
    ```cpp
    int sz = m.size();
    ```

At any given point, you can determine the current size (the number of key-value pairs) in the map.

*   **Inserting an element:**
    ```cpp
    m.insert(make_pair(key, value));
    ```

This inserts a key-value pair `(key, value)` into the map. If `key` is already present, the insert operation updates the corresponding value.  
Alternatively you can use `m[key] = value` to insert a key-value pair `(key, value)` into the map. If `key` is not present, this will insert the key-value pair into the map else if `key` is already present, this operation will update the corresponding value.

*   **Removing an element:**
    ```cpp
    m.erase(key);
    ```

This removes the key-value pair with the specified key from the map, if it exists.

*   **Finding an element:**
    ```cpp
    auto it = m.find(key);
    ```

This returns an iterator to the key-value pair with the specified key. If the key is not found, the iterator points to the end of the map.

*   **Checking if an element exists:**
    ```cpp
    if (m.count(key))
    ```

This checks if an key exists in the map. Returns 111 if found, 000 otherwise.

*   **Iterating through the map:**
    ```cpp
    for (auto it = m.begin(); it != m.end(); ++it) {
        // Access the current element using *it
    }
    // or using range-based iterator
    for(auto &it: m) {
      // it.first provides key, it.second provides value
    }
    ```

It is important to note that insertion, deletion, and finding elements in a map have a time complexity of O(logn) on average. This is because maps are usually implemented as balanced binary search trees.

Maps maintain an order based on the keys. Each `key` in the map is unique, and keys are used to access corresponding values.

В `std::map` порядок збереження елементів **не залежить від порядку їх вставки**, а визначається впорядкованістю **ключів** за допомогою компаратора (за замовчуванням — `std::less<Key>`, тобто **зростання**).  

### 🔹 Як `std::map` підтримує порядок?
- Внутрішньо `std::map` реалізований як **самобалансне бінарне дерево пошуку** (зазвичай **червонo-чорне дерево**).
- Елементи в ньому **завжди зберігаються впорядковано** за ключем.
- Навіть якщо ви вставляєте елементи у випадковому порядку, вони **автоматично сортуються**.