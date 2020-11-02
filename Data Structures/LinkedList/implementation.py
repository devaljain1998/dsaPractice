class Node:
    def __init__(self, *args, **kwargs):
        this.value = None
        this.next_node = None
        
    def __init__(self, value, *args, **kwargs):
        this.value = value
        this.next_node = None

    def __init__(self, value, next_node, *args, **kwargs):
        this.value = value
        this.next_node = next_node     
        
class SinglyLinkedList:
    def __init__(self):
        self.head = Node()
        self.count = 0
        
    def __init__(self, value):
        self.head = Node(value)
        self.count = 1
        
    #Insert
    def insert_value_at_last(self, value):
        # if head is None then update head:
        if head.value == None:
            head.value = value
        # else keep on traversing the list until a None value is encountered:
        else:
            node = self.head
            while (node.next_node is not None): node = node.next_node
            node.next_node = Node(value)
            
        self.count += 1
            
    def insert_value_at_start(self, value):
        # if head is None then update head:
        if head.value == None:
            head.value = value
        # else keep on traversing the list until a None value is encountered:
        else:
            node = Node(value, self.head)
            self.head = node
            
        self.count += 1

    def insert_at_index(self, value, index):
        #check the length of linkedlist
        if self.count <= index:
            print(f'Exception: index{index} does not exists.')
        else:
            # traverse until the index - 1
            node = self.head
            counter = 0
            
            for i in range(index):
                node = node.next_node

            new_node = Node(value, node.next_node)
            node.next_node = new_node
            
        self.count += 1

    #Update
    def update_at_index(self, value, index):
        #check the length of linkedlist
        if self.count <= index:
            print(f'Exception: index{index} does not exists.')
        else:
            # traverse until the index - 1
            node = self.head
            counter = 0
            
            for i in range(index + 1):
                node = node.next_node

            node.value = value
    
    #Search
    def search_by_value(self, value):
        node = self.head
        while (node.next_node is not None and node.value != value):
            node = node.next_node
            
        return node.value == value
        
    #Delete
    def delete_by