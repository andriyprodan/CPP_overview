# In a std::map, what happens if you try to insert a key-value pair with a key that already exists?
```cpp
std::map<KeyType, ValueType> myMap;
myMap.insert(std::make_pair(key, value));
```
- The insertion is ignored, keeping the old value

When you try to insert a key-value pair into a std::map where the key already exists, the insertion is ignored, and the existing value associated with that key is preserved. If you want to update the value, you need to use the [] operator or the insert() method with a hint. This behavior ensures that keys in a map remain unique.

## Which of the following operations does NOT invalidate iterators in a std::vector?
- operator[]

The operator[] does not invalidate iterators in a std::vector. Operations that modify the size or capacity of the vector, such as push_back(), erase(), or clear(), can potentially invalidate iterators. However, accessing or modifying elements using the subscript operator (operator[]) does not change the vector's structure and thus does not invalidate iterators.

