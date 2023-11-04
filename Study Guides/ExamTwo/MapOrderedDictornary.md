### Describe a set of operations for an ordered dictionary ADT that would correspond to the functions of the ordered map ADT. Be sure to define the meaning of the functions so that they can deal with the possibility of different entries with equal keys.

---


Insert(key, value): Insert a new key-value pair into the ordered dictionary. If the key already exists, a new entry with the same key is added. The relative order of entries with the same key should be preserved.

Delete(key, value): Delete a specific key-value pair from the ordered dictionary. If there are multiple entries with the same key, only the specified key-value pair is removed.

Search(key): Find and return all values associated with a given key. This operation should return a list (or a similar data structure) of values corresponding to the key.

SearchRange(key1, key2): Find and return all key-value pairs with keys in the range [key1, key2], inclusive. The key-value pairs should be returned in their order of insertion.

MinKey(): Find and return the smallest (leftmost) key in the ordered dictionary.

MaxKey(): Find and return the largest (rightmost) key in the ordered dictionary.

Predecessor(key): Find and return the key-value pairs immediately before the given key in the order of insertion. If there are multiple entries with the same key, the predecessor of the given key is the key-value pair that was inserted first.

Successor(key): Find and return the key-value pairs immediately after the given key in the order of insertion. If there are multiple entries with the same key, the successor of the given key is the key-value pair that was inserted after it.

Size(): Return the number of key-value pairs in the ordered dictionary.