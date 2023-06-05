class Set:
    def __init__(self):
        self.values = []
    
    # Add new element into set
    def add(self, elem):
        if elem not in self.values:
            self.values.append(elem)
    
    # Remove element from set
    def remove(self, elem):
        if elem in self.values:
           self.values.remove(elem)

    # Check if element is present in set
    def contains(self, elem):
        return elem in self.values
    
    # Return number of elements in set
    def size(self):
        return len(self.values)
    
    # Return an iterator used to loop over collection 
    def __iter__(self):
        return iter(self.values)
    
    # Compute intersection of two sets
    def intersection(self, other):
        result_set = Set()
        for elem in self.values:
            if elem in other.values:
                result_set.add(elem)
        return result_set
    
    # Compute union of two sets
    def union(self, other):
        result_set = Set()
        for elem in self.values:
            result_set.add(elem)
        for elem in other.values:
            result_set.add(elem)
        return result_set
    
    # Compute difference between two sets
    def difference(self, other):
        result_set = Set()
        for elem in self.values:
            if elem not in other.values:
                result_set.add(elem)
        return result_set
    
    # Check if this set is a subset of another set
    def issubset(self, other):
        for elem in self.values:
            if elem not in other.values:
                return False
        return True

# Driver code
if __name__ == "__main__" :
    s = Set()
    s.add(1)
    s.add(2)
    s.add(3)

    print(s.contains(2)) # True
    print(s.size()) # 3

    s.remove(2)
    print(s.contains(2)) # False

    for item in s:
        print(item) # 1, 3

    t = Set()
    t.add(2)
    t.add(3)
    t.add(4)

    u = s.intersection(t)
    print(u.values) # [3]

    v = s.union(t)
    print(v.values) # [1, 3, 2, 4]

    w = s.difference(t)
    print(w.values) # [1]

    print(s.issubset(v)) # True
    print(t.issubset(s)) # False
