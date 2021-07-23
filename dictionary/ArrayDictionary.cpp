/**********************************************************************************************************************/
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(): itemCount(0), maxItems(DEFAULT_CAPACITY),
                                                       items(make_unique<Entry<KeyType, ItemType>[]>(
                                                               DEFAULT_CAPACITY)) {}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(int maxNumberOfEntries): itemCount(0), maxItems(maxNumberOfEntries),
                                                                             items(make_unique<
                                                                                     Entry<KeyType, ItemType>[]>(
                                                                                     maxNumberOfEntries)) {}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType> &dict):
    itemCount(dict.itemCount), maxItems(dict.maxItems)
{
    items = make_unique<Entry<KeyType, ItemType>[]>(dict.maxItems);
    for (int index = 0; index < dict.itemCount; index++) {
        items[index] = dict.items[index];
    }
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::~ArrayDictionary() {
    destroyDictionary();
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::destroyDictionary() {
    items = make_unique<Entry<KeyType, ItemType>[]>(maxItems);
    itemCount = 0;
}


/**********************************************************************************************************************/
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::isEmpty() const {
    return (itemCount == 0);
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::clear() {
    destroyDictionary();
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::add(const KeyType &searchKey, const ItemType &newItem) {
    bool ableToInsert = (itemCount < maxItems);
    if (ableToInsert) {
        /*
         * TODO: Dictionary ADD
         * Make room for new entry by shifting all entries at positions >= newPosition toward the end of the array
         * (no shift if newPosition == itemCount + 1). Performing a binary search doesn’t help here, because we need to
         * shift the entries while looking for the insertion location.
         *                  More help on section 18.2.1 in our textbook.
         */
        //YOUR CODE HERE
        int index = itemCount;

        while((index > 0) && (searchKey < items[index-1].getKey())){
            items[index] = items[index-1];
            index--;
        }
            items[index] = Entry<KeyType, ItemType>(searchKey, newItem);
            itemCount++;

    }

    return ableToInsert;
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {

    int itemIndex = findEntryIndex(0, itemCount - 1, searchKey);
    bool ableToRemove = !isEmpty() && (itemIndex >= 0);

    if (ableToRemove) { // If found, shift items to left
        while (itemIndex < itemCount - 1) {
            items[itemIndex] = items[itemIndex + 1];
            itemIndex++;
        }

        itemCount--;  // Decrease count of entries
    }

    return ableToRemove;
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {
    return (findEntryIndex(0, itemCount - 1, searchKey) >= 0);
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
ItemType ArrayDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const noexcept(false) {
    int itemIndex = findEntryIndex(0, itemCount - 1, searchKey);
    if (itemIndex < 0)
        throw NotFoundException("\n\nItem not found in Dictionary!\n\n");

    return items[itemIndex].getItem();
}
/**********************************************************************************************************************/
template<class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::findEntryIndex(int firstIndex, int lastIndex, const KeyType &searchKey) const {
    /**
     * TODO: Dictionary FindEntryIndex
     * Recursive Binary Search for the search key.
     * See chp 2 - p70
     */

    //YOUR CODE HERE

    int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
    if(firstIndex>lastIndex)
        return -1;
    else if(searchKey == items[middleIndex].getKey())
        return middleIndex;
    else if(searchKey < items[middleIndex].getKey())
        return findEntryIndex(firstIndex, middleIndex -1, searchKey);
    else
        return findEntryIndex(middleIndex+1, lastIndex, searchKey);

    //return 0;  //replace this
}

/**********************************************************************************************************************/
template<class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::traverse(void visit(ItemType &)) const {
    // Simple because the array is sorted.
    for (int index = 0; index < itemCount; index++) {
        ItemType currentItem = items[index].getItem();
        visit(currentItem);
    }
}
