class TrieNode:
    def __init__(self):
        self.children = {}
        self.items = []

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, key, item):
        current = self.root
        for c in key:
            if c not in current.children:
                current.children[c] = TrieNode()
            current = current.children[c]
        current.items.append(item)

    def search(self, keys):
        itemsList = []
        for key in keys:
            current = self.root
            for c in key:
                if c not in current.children:
                    current = None
                    break
                current = current.children[c]
            if current and current.items :
                itemsList.append(current.items)

        if not itemsList :
            return []

        items = list(itemsList[0])
        for lst in itemsList:
            items = list(set(items) & set(lst))
        return items

class Item :
    def __init__(self, name, keys) :
        self.name = name
        self.keys = keys
    def match_keys(self) :
        return self.keys

T = Trie()

item1 = Item('item1', ['key1', 'key4'])
item2 = Item('item2', ['key1', 'key4', 'key5'])
item3 = Item('item3', ['key1'])
item4 = Item('item4', ['key2', 'key3'])
item5 = Item('item5', ['key3', 'key4'])
item6 = Item('item6', ['key1', 'key2', 'key3', 'key4'])

lst = [ item1, item2, item3, item4, item5, item6 ]

for item in lst :
    keys = item.match_keys()
    for k in keys :
        print(k, item.name)
        T.insert(k, item)

result = T.search(['key1', 'key4' ])

for e in result :
    print(e.name)
