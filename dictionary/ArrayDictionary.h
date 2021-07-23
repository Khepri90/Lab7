#ifndef ARRAY_DICTIONARY_
#define ARRAY_DICTIONARY_

#include "DictionaryInterface.h"
#include "Entry.h"
#include "../exceptions/NotFoundException.h"

using namespace std;

template<class KeyType, class ItemType>
class ArrayDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    static const int DEFAULT_CAPACITY = 50;
    unique_ptr<Entry<KeyType, ItemType>[]> items;      // Array of dictionary entries
    int itemCount;                                     // Current count of dictionary items
    int maxItems;                                      // Maximum capacity of the dictionary
    void destroyDictionary();

    int findEntryIndex(int firstIndex, int lastIndex, const KeyType &searchKey) const;

public:
    ArrayDictionary();

    explicit ArrayDictionary(int maxNumberOfEntries);

    ArrayDictionary(const ArrayDictionary<KeyType, ItemType> &dict);

    virtual ~ArrayDictionary();

    bool isEmpty() const;

    int getNumberOfItems() const;

    bool add(const KeyType &searchKey, const ItemType &newItem);

    bool remove(const KeyType &searchKey);

    void clear();

    ItemType getItem(const KeyType &searchKey) const noexcept(false);

    bool contains(const KeyType &searchKey) const;

    void traverse(void visit(ItemType &)) const;
};

#include "ArrayDictionary.cpp"

#endif
