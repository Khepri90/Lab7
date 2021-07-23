#ifndef ENTRY_
#define ENTRY_

template<class KeyType, class ItemType>
class Entry {
private:
    KeyType searchKey;
    ItemType item;

protected:
    void setKey(const KeyType &aSearchKey) { searchKey = aSearchKey; }

public:
    explicit Entry() = default;

    explicit Entry(const KeyType &searchKey, const ItemType &newItem) : searchKey(searchKey), item(newItem) {};

    ItemType getItem() const { return item; }

    KeyType getKey() const { return searchKey; }

    void setItem(const ItemType &newItem) { item = newItem; }

    bool operator==(const Entry<KeyType, ItemType> &rightHandItem) const {
        return (searchKey == rightHandItem.getKey());
    }

    bool operator>(const Entry<KeyType, ItemType> &rightHandItem) const {
        return (searchKey > rightHandItem.getKey());
    }
};

#endif
